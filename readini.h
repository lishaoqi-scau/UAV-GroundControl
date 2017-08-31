/*
  主键形式为  [MainKey] 单独行，读取时忽略所有前后空格
  副键形式为  SubKey = Value
  键值Value一般是一行，不跨行。
  如果Value跨几行，则在SubKey=Value前增加键值：  SYS_ValueLen = 下一个键值的value的长度  如：
         SYS_ValueLen_strInfo = 135
         strInfo="..."
         这样读取下一条时必须读够135个字节才会停止，可跨多行。
         注：SYS_ValueLen 只对下一个键有效.SYS_ValueLen_strInfo 只有SYS_ValueLen有效，后面_strInfo被忽略
  读写键值key=主键/副键 形式读写。分别的主键，副键为参数，函数自动连接成 “主键/副键”形式
  写入键值后，要存盘savefile（），savefile（true）则自动为所有键值增加键值长度标识键值，数据内容可以跨多行
  读出键值要先设置文件名，文件设置后自动打开。setFile(QString filename,true)  第二个参数默认为true为自动打开读出文件内容。false则先不读文件。要调用ReadFile()
  构造函数也默认自动打开文件，如果不自动打开读取文件则 ReadIni(QString filename, false);

  *****************************************************************************************************************************************
   QMap<QString, QString>     StringValueMap mapValue;
             存储所有（键key---值value）列表， 键 =  主键+QString(tr("/"))+ 子键 。等于主键和子键唯一确定列表一项，value存储该子键的内容
   QMap<QString, QStringList> StringKeyMap mapKey;
             存储MAP类型 （主键--该主键下子键列表） 列表，
   删除和增加键和键值，都必须同步操作两个MAP表，同步更新。
*/


#ifndef READINI_H
#define READINI_H
#include <QString>
#include <QSettings>
#include <QFile>
#include <QDebug>
#include <QTextCodec>
#include <QStringList>
#include <QMessageBox>
#include <QFile>
#include <QStringList>




#define MAXLINELEN 1024000
typedef QMap<QString, QString> StringValueMap;
typedef QMap<QString, QStringList> StringKeyMap;

class ReadIni : public QObject
{
    public:
        ReadIni();
        ReadIni(QString filename, bool bReadFileLater = false);
        ~ReadIni();

    public:

        //读写ini文件
        void    setFile(QString filename, bool bReadFileLater = false );
        int     ReadFile();
        int     SaveFile(bool bCreatValueLenKey = false);  //键值链表存为文件，文件先清空，bCreatValueLenKey是否为每一个项自动强制创建长度信息

        //录入、读出、删除键值
        void    setMainKey(QString strMainKey); //设置默认的主键，下面的调用可以省略掉主键
        int     setKeyValue(QString strValue ,  QString strKey , QString strMainKey = ""  , bool bAddVerSize=false ); //写入键值，bAddVerSize=true 则自动写入长度信息
        int     getKeyValue(QString &rtValue , QString defaultValue , QString strKey , QString strMainKey = "");//获得一个键值
        bool    isKeyExist(QString MainKey , QString SubKey = ""); //判断是否有该键，存在返回true
        int     DelKey(QString MainKey , QString SubKey = "");  //删除键，SubKey = ""则删除主键
        void    ClearAll();   //清除内存的所有键值

        //获得键值表的各种形式
        int     GetMainKeyStringList(QStringList &rtList);  //获得主键列表QStringList
        int     GetValueKeyMap(QString MainKey , StringValueMap &rtMap);//返回MainKey键值下的（副键--值）的map
        int     GetSubKeyStringList(QString MainKey , QStringList &rtList);//返回MainKey键值下的副键列表QStringList
        int     GetMainKeyCount();                          //返回主键个数//  ~~~没怎么测试过，待测
        int     GetValueKeyCount();                         //返回所有副键值的总个数，主键不计算在内，比较少用

       //输出和调试用
        void    OutPrintAll();//输出整个键值表

        //静态方法，查找字符在字符串中的位置
        static int Find(QString str , QChar ch, int start = 0);// 查找字符在字符串中的位置
        static int RevFind(QString str , QChar ch , int start = -1);//反向查找字符串

private:
        int UpdateKeyMap(QString MainKey , QString SubKey ); //键值插入写入后，同步改变主键-副键map列表


private:
        QString m_filename;
        QString m_MainKey;
        int m_MainKeyCount;     //有效主键的个数
        StringValueMap mapValue;//key-value
        StringKeyMap mapKey;    //mainkey-subkeylist
        QString m_Key;


};
#endif // READINI_H
