#include "readini.h"
QTextCodec *codec3=QTextCodec::codecForName("GBK");
ReadIni::ReadIni()
{

    /*
   QFile file("c:\\config.ini");
   file.open(QIODevice::ReadWrite);
   file.close();
   m_filename = "c:\\config.ini";
    */

}
ReadIni::ReadIni(QString filename, bool bReadFileLater)
{
    m_filename = filename ;
    m_MainKeyCount = 0;
    if(!bReadFileLater)ReadFile();
}


ReadIni::~ReadIni()
{

}

void ReadIni::setFile(QString filename , bool bReadFileLater)
{
    m_filename = filename ;
    if(!bReadFileLater)ReadFile();
}

void ReadIni::setMainKey(QString strMainKey)
{
        m_MainKey =  strMainKey ;
        m_Key = m_MainKey+tr("/");
}

//strValue： 键值   strKey：副键  strMainKey：主键  bAddVerSize：是否
//键值存在返回0，键值不存在返回-1.
int ReadIni::setKeyValue ( QString strValue ,  QString strKey , QString strMainKey , bool bAddVerSize)
{
    QString key,str;
    if(strMainKey.length() > 0){
        m_MainKey=strMainKey;
        m_Key=m_MainKey+tr("/");
    }

    StringValueMap::Iterator it;

    //在录入之前增加键值大小SYS_ValueLen
    if(bAddVerSize){
        QString tmpKey,tmpStrLen,tmpSubKey;
        tmpSubKey=tr("SYS_ValueLen_")+strKey;
        tmpKey=m_MainKey+tr("/")+tmpSubKey;// 生成"SYS_ValueLen_"的键值
        tmpStrLen=QString("%1").arg(strValue.length());
        it= mapValue.find(tmpKey);
         if(it == mapValue.end()){
            // 找不到添加键值到map表
            //QMessageBox::warning(NULL,"Add SYSTEM_COUNT key:["+tmpKey+"]" , "mainkey=["+m_MainKey+"]  subkey=["+tmpSubKey+ "]  value= ["+tmpStrLen+"]");
            mapValue.insert(tmpKey,tmpStrLen);//key-value 表
            UpdateKeyMap(m_MainKey,tmpSubKey);//mainkey-subkey表
         }else{
            //有键值，直接替换value，修改即可
            mapValue.remove(tmpKey);
            mapValue.insert(tmpKey,tmpStrLen);
        }

    }//录入SYS_ValueLen完毕


    //录入增加键值到链表
    key = m_Key+ strKey;
    //key = codec3->toUnicode(key.toLatin1());
    //strValue = codec3->toUnicode(strValue.toLatin1());
    //qDebug()<<"SetKey（）  key= "<<key<<tr(" write value： ")<<strValue;

    //QMessageBox::warning(NULL,"Add  key:["+key+"]" , "mainkey=["+m_MainKey+"]  subkey=["+strKey+ "]  value= ["+strValue+"]");
    //mapValue.begin();
    it= mapValue.find(key);
    if(it==mapValue.end()){
        // 找不到添加键值到map表
        //QMessageBox::warning(NULL,"Add  NEW key:["+m_Key+"]",strValue);
        mapValue.insert(key,strValue);//key-value 表
        UpdateKeyMap(m_MainKey,strKey);//mainkey-subkey表
        return 0;
    }else{
        //有键值，直接替换value，修改即可
        //QMessageBox::warning(NULL,"REPLACE  OLD key:["+m_Key+"]",strValue);
        mapValue.remove(key);
        mapValue.insert(key,strValue);
        return -1;
    }

}

//trValue:返回的键值内容keyvalue   defaultValue：找不到键值时的默认值   strKey：副键  strMainKey： 主键（如果跟上次主键相同，可忽略）
int ReadIni::getKeyValue( QString &rtValue , QString defaultValue , QString strKey , QString strMainKey  )
{
  QString key,outStr;
    if(strMainKey.length() > 0){
        m_MainKey=strMainKey;
        m_Key = m_MainKey+tr("/");
    }
     key = m_Key+ strKey;
    // key = codec3->toUnicode(key.toLatin1());
    StringValueMap::Iterator it;
    it= mapValue.find(key);
    //找不到
    if(it==mapValue.end()){
        rtValue=defaultValue;
        //QMessageBox::warning(NULL,"not find key:["+key+"]",rtValue);
        return -1;
    }
    //找到
    rtValue=it.value();
    //rtValue = codec3->toUnicode(rtValue.toLatin1());
    //QMessageBox::warning(NULL,"read",rtValue);
    return 0;
}


int ReadIni::Find(QString str , QChar ch , int start)
{
    int len;
    int pos=0;
    QChar c;
    len=str.length();
    if( len<=0 || start >= len )return -1;
    for(pos=start ;pos<len;pos++){
        if(ch == str.at(pos))return pos;
    }
    return -1;
}
int ReadIni::RevFind(QString str , QChar ch , int start)
{
    int len;
    int pos=0;
    QChar c;
    len=str.length();
    if(start<0 )start=len-1;
    if( len<=0 || start >= len )return -1;
    for(pos = len -1 ;pos>0;pos--){
        if(ch == str.at(pos))return pos;
    }
    return -1;
}

//从文件读出数据，录入到键值列表中。 每次读一行，如果没启动SYS_ValueLen前置键，则所有键和值都删除前后空格。
//当前一个键是SYS_ValueLen_键，表面下面的键的长度，此时“=”后面的内容前后空格均不去除，读第二行时空格也不去除。
//错误返回-1  成功返回键值的数量（不含主键）
int ReadIni::ReadFile()
{
    QString str,strBak;              // 读出每一行的数据，strBak为一个备份，如果是跨几行读取则不进行前后空格去除
    QString key;                     // 主键+副键合起来进行搜索的总键
    QString strMainKey,strSubKey,strValue; //主键，副键，键值
    int nMainKey=0,nSubKey=0;
    int nValueLen=0;
    bool longValue=false;            //键值的附加长度信息，由SYS_ValueLen_键值提供
    QString strOldMainKey;           //主键改变时存入链表，作为一个切换标志
    QStringList subkeyList;          //特定主键下的副键列表

    //打开文件
    if(m_filename.length()<=0)return -1; //文件名为空返回读文件失败
    QFile file(m_filename);
    if(!file.open(QIODevice::ReadOnly))return -1;
    QTextStream out(&file);

    //清除链表
    mapValue.clear();// key-value
    mapKey.clear();// mainkey-subkeylist
    subkeyList.clear();//subkeylist

    //初值
    strMainKey.clear();
    strSubKey.clear();
    strValue.clear();
    strOldMainKey.clear();


    //开始读出文件内容
    do{
        str=out.readLine(MAXLINELEN );
        if(nValueLen>0)strBak=str;//如果多项模式则保留原样，留空格
        str=str.trimmed();

        //有附加value长度的可能跨越几行，直接加上
        if( (strValue.length()<nValueLen) && (strSubKey.length()>0) ){
            strValue+=tr("\r\n");
            strValue=strValue+strBak;
            longValue=false;
            //QMessageBox::warning(NULL,"["+strMainKey+"]",strSubKey + " == "+ strValue+tr("\r\nnValueLen=%1  strLen=%2").arg(nValueLen).arg(strValue.length()));
            continue;
        }

        if(!longValue)nValueLen=0;//如果前一个键值非SYS_ValueLen指定内容长度的话，则清除nValueLen长度标志。

        //显示上一次的主键值,在此处录入到链表
        if(strMainKey != strOldMainKey){
            if(subkeyList.count()>0){
                mapKey.insert(strOldMainKey,subkeyList);
                subkeyList.clear();
            }
            strOldMainKey=strMainKey;
            subkeyList.clear();
            //QMessageBox::warning(NULL,"MainKey Change to:["+strMainKey+"]",strMainKey);

        }

        //显示上一次的键值,在此处录入到链表
        if(strSubKey.length()>0){
            key=strMainKey+QString(tr("/"))+strSubKey;
            mapValue.insert(key,strValue);
            subkeyList.append(strSubKey);
            //QMessageBox::warning(NULL,"["+strMainKey+"]",strSubKey + " == "+ strValue);
            strSubKey.clear();
            strValue.clear();
        }


        if(str.length()==0)continue;  //读出行为空则继续下一行循环

        if(longValue == false ) nValueLen=0;
        //判断是否为主键[]
        if( str.at(0) == QChar('['))
        {
            nMainKey = Find(str,QChar(']'),1);
            if(nMainKey>=0){
                strMainKey=str.mid(1,nMainKey-1);
                strMainKey=strMainKey.trimmed();
                nValueLen=0;
                strSubKey.clear();
                strValue.clear();
            }
        }
        else{
            //非主键则判断是否副键
            nSubKey = Find(str,QChar('='),1);
            if(nSubKey>=0){
                strSubKey=str.left(nSubKey).trimmed();
                if(nValueLen>0){
                    strValue=strBak.mid(Find(strBak,QChar('='),1)+1);//如果为多项值，则不去掉空格
                    //QMessageBox::warning(NULL,"nValueLen>0",strSubKey + " = "+ strValue + tr(" valuelen=%1").arg(strValue.length()));
                    }else strValue=str.mid(nSubKey+1).trimmed();

                if(strSubKey.left(12)==QString(tr("SYS_ValueLen"))){
                    nValueLen=strValue.toInt();
                    longValue=true;
                    strSubKey.clear();
                    strValue.clear();
                }
                //QMessageBox::warning(NULL,"Find Sub Key",strSubKey + " = "+ strValue);
            }else{
                //非主键也非子键，忽略不处理，清除上一次内容
                nValueLen=0;
                strValue.clear();
                strSubKey.clear();
            }
        }

    }while(!out.atEnd());//读文件结束

    //最后一个键值
    if(strSubKey.length()>0){
        key=strMainKey+QString(tr("/"))+strSubKey;
        mapValue.insert(key,strValue);
        subkeyList.append(strSubKey);
        //QMessageBox::warning(NULL,"["+strMainKey+"]",strSubKey + " == "+ strValue);
    }
    //最后一个主键
    if(subkeyList.count()>0){
                mapKey.insert(strOldMainKey,subkeyList);
            }

    file.close();
    m_MainKeyCount = mapKey.count();
    return mapValue.count();
}



//存盘。参数 bCreatValueLenKey 为是否在每一个键值前创建一个键 （SYS_ValueLen_副键 = len ）纪录长度信息。此模式可以多行纪录
//返回存入的子键数量.不带主键数量
int ReadIni::SaveFile(bool bCreatValueLenKey)
{
    QString strMainKey,strSubKey,key;
    int nWriteKeyNum=0;

    if(m_filename.length()<=0)return -1; //文件名为空返回读文件失败
    QFile file(m_filename);
    if(!file.open(QIODevice::WriteOnly|QFile::Truncate))return -1;
    QTextStream out(&file);

    //获取主键列表和主键下副键的value列表map
    QStringList rtMainKeyList;
    StringValueMap rtSubKeyList;

    int rt=GetMainKeyStringList(rtMainKeyList); //获取主键列表
     for(int i=0;i<rtMainKeyList.count();i++)
    {

        strMainKey=rtMainKeyList.at(i);
        out<<"["<<strMainKey<<"]"<<"\r\n";

        rt=GetValueKeyMap(strMainKey,rtSubKeyList);
        StringValueMap::Iterator it;
        //遍历所有主键下的子键项目
        for ( it = rtSubKeyList.begin(); it != rtSubKeyList.end(); ++it ) {
            strSubKey=it.key();
            if(strSubKey.left(12)==QString(tr("SYS_ValueLen")))  continue;//"SYS_ValueLen_"的键跳过不写入
            key=strMainKey+tr("/SYS_ValueLen_")+strSubKey;// 生成"SYS_ValueLen_"的键值
            if(!bCreatValueLenKey)
            {
                //如果没有统一强制写入长度键则搜索
                StringValueMap::Iterator itsys;
                itsys=mapValue.find(key);                      //查找是否有对应项的"SYS_ValueLen_"键值
                //QMessageBox::warning(NULL,"SaveFile() TO Find SYS_VALUELEN Key["+m_MainKey+"]",key);
                if(itsys != mapValue.end()){
                    //QMessageBox::warning(NULL,"SaveFile() Find! SYS_VALUELEN Key["+m_MainKey+"]",key);
                    //"SYS_ValueLen_"的键值存在则写入
                    out<<tr("SYS_ValueLen_")+strSubKey<<tr("=")<<itsys.value()<<tr("\r\n");
                    nWriteKeyNum++;
                }
            }else{
                //统一强制写入长度键
                out<<tr("SYS_ValueLen_")+strSubKey << tr("=") <<it.value().length()<<tr("\r\n");
                nWriteKeyNum++;

            }
            //非"SYS_ValueLen_"则写入
             out<<it.key()<<tr("=")<<it.value()<<tr("\r\n");
             nWriteKeyNum++;

        }

    }
    out.flush();
    file.close();
    return nWriteKeyNum;
}


//返回主键个数
int ReadIni::GetMainKeyCount()
{
    return m_MainKeyCount;
}

//返回副键值的总个数
int ReadIni::GetValueKeyCount()
{
    return mapValue.count();
}

//返回有效主键列表，不带副键的主键忽略。 如果没有则返回-1，有则返回主键个数。
//rtList：返回的主键字串列表
int ReadIni::GetMainKeyStringList(QStringList &rtList)
{
    StringKeyMap::Iterator itkey;
    if(m_MainKeyCount<=0)return -1;
    rtList.clear();
    for ( itkey = mapKey.begin(); itkey != mapKey.end(); ++itkey ) {
         rtList.append(itkey.key());
      }
      return rtList.count();
}

//返回MainKey键值下的副键列表
int ReadIni::GetSubKeyStringList(QString MainKey , QStringList &rtList)
{
    if(mapValue.count()<=0)return -1;
    StringKeyMap::Iterator it;
    it=mapKey.find(MainKey);
    if(it != mapKey.end()){
        rtList=it.value();
        return rtList.count();
    }
    return -1;

}


//返回MainKey键值下的（副键--值）的map,如果没有返回-1，如果有返回项数
//rtMap 为返回的 map列表
int ReadIni::GetValueKeyMap(QString MainKey , StringValueMap& rtMap)
{
    if(mapValue.count()<=0)return -1;
    StringValueMap::Iterator it;
    QString key;
    rtMap.clear();
    for ( it = mapValue.begin(); it != mapValue.end(); ++it ) {
            key=it.key();
            if(key.left(MainKey.length())== MainKey){
                rtMap.insert(key.mid(MainKey.length()+1),it.value());
            }
    }
    return rtMap.count();
}



//增加键值到键值map表里面
int ReadIni::UpdateKeyMap(QString MainKey , QString SubKey )
{
        QStringList lst;
        StringKeyMap::Iterator itkey;
        itkey = mapKey.find(MainKey);
        if(itkey == mapKey.end() ){
            //没找到主键，直接添加主键
            lst.append(SubKey);
            mapKey.insert(MainKey,lst);
            m_MainKeyCount++;
            return 1;
        }else{
            //找到主键，没有此副键.读取副键列表，添加。然后再插入。
            lst=itkey.value();
            lst.append(SubKey);
            mapKey.remove(MainKey);
            mapKey.insert(MainKey,lst);
            return 0;
        }
}

bool ReadIni::isKeyExist(QString MainKey , QString SubKey )
{
    StringKeyMap::Iterator it;
    QStringList rtSubKeyList;
    if(MainKey=="")return false;
    it = mapKey.find(MainKey);
    if(SubKey==""){
         if(it==mapKey.end())return false;
         return true;
    }else{
        QString key=MainKey+tr("/")+SubKey;// 生成"SYS_ValueLen_"的键值
        if( mapValue.find(key)!= mapValue.end())return true ;
        return false;
    }
}

//删除键值，返回删除的项目个数
int ReadIni::DelKey(QString MainKey , QString SubKey )
{
    //获取主键列表和主键下副键的value列表map
    QStringList rtMainKeyList;
    QStringList rtSubKeyList;
    QString key;

    if(!isKeyExist(MainKey , SubKey ))return 0;
    int rt=GetMainKeyStringList(rtMainKeyList); //获取主键列表

    //遍历主键列表，透过每一项主键，再获得该主键下子键和值的列表map。删除mapValue 及 mapKey 里面的内容
    for(int i=0;i<rtMainKeyList.count();i++)
    {
        QString mainkey;
        mainkey=rtMainKeyList.at(i);
        if(MainKey!=mainkey)continue;

        //找到主键项，删除所有符合要求的项
        rt=GetSubKeyStringList(mainkey,rtSubKeyList);
        if( SubKey == "" ){
            //删除一个主键，包括下面所有子键内容从mapValue表中移除
            for ( int k=0;k<rtSubKeyList.count(); k++ ) {
                key=MainKey+QString(tr("/"))+ rtSubKeyList.at(k);//获得主键+子键
                //QMessageBox::warning(NULL,"ReMoveKey() delkey=["+key+"]","subkey="+rtSubKeyList.at(k));
                mapValue.remove(key);
            }
            //移除主键
            mapKey.remove(MainKey);
            m_MainKeyCount=mapKey.count();
            //QMessageBox::warning(NULL,"ReMoveKey() delkey ["+key+"]" ,tr("total=%1").arg(rtSubKeyList.count()));
            return rtSubKeyList.count();
        }else{
            //移除特定组合键
            rtSubKeyList.removeOne(SubKey);
            mapKey.remove(MainKey);
            mapKey.insert(MainKey,rtSubKeyList);
            key=MainKey+QString(tr("/"))+ SubKey;//获得主键+子键
            mapValue.remove(key);//移除值
            return 1;
        }

    }


}

//对话框输出所有的主键和键值，测试用
void ReadIni::OutPrintAll()
{

    //获取主键列表和主键下副键的value列表map
    QStringList rtMainKeyList;
    StringValueMap rtSubKeyList;

    int rt=GetMainKeyStringList(rtMainKeyList); //获取主键列表

    //遍历主键列表，透过每一项主键，再获得该主键下子键和值的列表map
    for(int i=0;i<rtMainKeyList.count();i++)
    {
        QString mainkey;
        mainkey=rtMainKeyList.at(i);
        rt=GetValueKeyMap(mainkey,rtSubKeyList);

        StringValueMap::Iterator it;
        for ( it = rtSubKeyList.begin(); it != rtSubKeyList.end(); ++it ) {
             QMessageBox::warning(NULL,"OutPrintAll() ","MainKey=["+mainkey+"]\r\n SubKey=["+ it.key()+"] :\r\n"+ it.value()+tr("\r\nvalueLen= %1").arg(it.value().length()));
        }

    }
}

//清楚所有的内存链表内容
void ReadIni::ClearAll()
{
      mapValue.clear();//key-value
      mapKey.clear();;    //mainkey-subkeylist
      m_MainKeyCount=0;     //有效主键的个数
}
