#include "qmlcommunicate.h"

QMLCommunicate::QMLCommunicate(QObject *parent) : QObject(parent)
{
    mfRoll=-30;
    mfPitch =-30;
    mfYaw =0;
    miItemSize = 180;
    miWidth=0;
    miHeight=0;
    miStatusWidgetWidth=0;
    miStatusWidgetHeight=0;
    miCommandWidgetWidth=0;
    miCommandWidgetHeight=0;
    miUAVLogoWidgetWidth=0;
    miUAVLogoWidgetHeight=0;
    miTmp=1;
    miTmp2=1;
    mstrLat="34.5629";
    mstrLon="118.32423";
    mTextColor = new QColor(0,0,0,250);
    mTimer = new QTimer(this);
    connect(mTimer, SIGNAL(timeout()), this, SLOT(Update()));
    mTimer->start(200);

    QVariant variant = QVariant::fromValue(mstrLon);
    mParamVarianList.append(variant);

    variant = QVariant::fromValue(mstrLat);
    mParamVarianList.append(variant);

    variant = QVariant::fromValue(mfYaw);
    mParamVarianList.append(variant);

    variant = QVariant::fromValue(*mTextColor);
    mParamVarianList.append(variant);

    variant = QVariant::fromValue(miWidth);
    mWidgetParamList.append(variant);

    variant = QVariant::fromValue(miHeight);
    mWidgetParamList.append(variant);
    variant = QVariant::fromValue(miStatusWidgetWidth);
    mWidgetParamList.append(variant);

    variant = QVariant::fromValue(miStatusWidgetHeight);
    mWidgetParamList.append(variant);

    variant = QVariant::fromValue(miCommandWidgetWidth);
    mWidgetParamList.append(variant);

    variant = QVariant::fromValue(miCommandWidgetHeight);
    mWidgetParamList.append(variant);

    variant = QVariant::fromValue(miUAVLogoWidgetWidth);
    mWidgetParamList.append(variant);

    variant = QVariant::fromValue(miUAVLogoWidgetHeight);
    mWidgetParamList.append(variant);

    variant = QVariant::fromValue(miMagWidgetWidth);
    mWidgetParamList.append(variant);

    variant = QVariant::fromValue(miMagWidgetHeight);
    mWidgetParamList.append(variant);

    variant = QVariant::fromValue(miSerialSettingWidgetWidth);
    mWidgetParamList.append(variant);

    variant = QVariant::fromValue(miSerialSettingWidgetHeight);
    mWidgetParamList.append(variant);

    QString strTmp;
    mFlyPrepareDataVarianList.append(QVariant::fromValue(strTmp));
    mFlyPrepareDataVarianList.append(QVariant::fromValue(strTmp));
    mFlyPrepareDataVarianList.append(QVariant::fromValue(strTmp));
    mFlyPrepareDataVarianList.append(QVariant::fromValue(strTmp));
    mFlyPrepareDataVarianList.append(QVariant::fromValue(strTmp));
    mFlyPrepareDataVarianList.append(QVariant::fromValue(strTmp));
    mFlyPrepareDataVarianList.append(QVariant::fromValue(strTmp));
    mFlyPrepareDataVarianList.append(QVariant::fromValue(strTmp));
    mFlyPrepareDataVarianList.append(QVariant::fromValue(strTmp));
    mFlyPrepareDataVarianList.append(QVariant::fromValue(strTmp));


}

void QMLCommunicate::WriteFlyPrepareData(QVariantList &qmlcommunicate)
{
    mFlyPrepareDataVarianList.clear();
    mFlyPrepareDataVarianList.append(qmlcommunicate);
}


QVariantList QMLCommunicate::ReadFlyPrepareData()
{
    QString strTaskName;
    mReadIni->getKeyValue(strTaskName,"","TaskName","FlyPrepare");
    mFlyPrepareDataVarianList[0]=QVariant::fromValue(strTaskName);

    QString strOperatorName;
    mReadIni->getKeyValue(strOperatorName,"","OperatorName","FlyPrepare");
    mFlyPrepareDataVarianList[1]=QVariant::fromValue(strOperatorName);

    QString strOperatorIDNum;
    mReadIni->getKeyValue(strOperatorIDNum,"","OperatorIDNum","FlyPrepare");
    mFlyPrepareDataVarianList[2]=QVariant::fromValue(strOperatorIDNum);

    QString strAirCraft;
    mReadIni->getKeyValue(strAirCraft,"","AirCraft","FlyPrepare");
    mFlyPrepareDataVarianList[3]=QVariant::fromValue(strAirCraft);

    QString strTakeoffWeight;
    mReadIni->getKeyValue(strTakeoffWeight,"","TakeoffWeight","FlyPrepare");
    mFlyPrepareDataVarianList[4]=QVariant::fromValue(strTakeoffWeight);

    QString strCellVol1;
    mReadIni->getKeyValue(strCellVol1,"","CellVol1","FlyPrepare");
    mFlyPrepareDataVarianList[5]=QVariant::fromValue(strCellVol1);

    QString strCellVol2;
    mReadIni->getKeyValue(strCellVol2,"","CellVol2","FlyPrepare");
    mFlyPrepareDataVarianList[6]=QVariant::fromValue(strCellVol2);

    QString strWeather;
    mReadIni->getKeyValue(strWeather,"","Weather","FlyPrepare");
    mFlyPrepareDataVarianList[7]=QVariant::fromValue(strWeather);

    QString strWindPower;
    mReadIni->getKeyValue(strWindPower,"","WindPower","FlyPrepare");
    mFlyPrepareDataVarianList[7]=QVariant::fromValue(strWindPower);

    QString strWindDire;
    mReadIni->getKeyValue(strWindDire,"","WindDire","FlyPrepare");
    mFlyPrepareDataVarianList[9]=QVariant::fromValue(strWindDire);

    return mFlyPrepareDataVarianList;
}


void QMLCommunicate::qmlCallFlyPreparefunction(QVariantList strList)
{
    QString strTaskName=strList[0].toString();
    QString strOperatorName=strList[1].toString();
    QString strOperatorIDNum=strList[2].toString();
    QString strAirCraft=strList[3].toString();
    QString strTakeoffWeight=strList[4].toString();
    QString strCellVol1=strList[5].toString();
    QString strCellVol2=strList[6].toString();
    QString strWeather=strList[7].toString();
    QString strWindPower=strList[8].toString();
    QString strWindDire=strList[9].toString();
    mReadIni->setKeyValue(strTaskName,"TaskName","FlyPrepare");
    mReadIni->setKeyValue(strOperatorName,"OperatorName","FlyPrepare");

    mReadIni->setKeyValue(strOperatorIDNum,"OperatorIDNum","FlyPrepare");
    mReadIni->setKeyValue(strAirCraft,"AirCraft","FlyPrepare");
    mReadIni->setKeyValue(strTakeoffWeight,"TakeoffWeight","FlyPrepare");
    mReadIni->setKeyValue(strCellVol1,"CellVol1","FlyPrepare");
    mReadIni->setKeyValue(strCellVol2,"CellVol2","FlyPrepare");
    mReadIni->setKeyValue(strWeather,"Weather","FlyPrepare");
    mReadIni->setKeyValue(strWindPower,"WindPower","FlyPrepare");
    mReadIni->setKeyValue(strWindDire,"WindDire","FlyPrepare");
    mReadIni->SaveFile();
}

void QMLCommunicate::SetReadIni(ReadIni *ini)
{
    mReadIni = ini;
}

QVariantList QMLCommunicate::ReadWidgetParam()
{
    return mWidgetParamList;
}

void QMLCommunicate::Update()
{
    mfRoll += miTmp*1;
    mfPitch += 0.5;
    mfYaw +=miTmp2*1;
    if(abs(mfRoll) >=30)
    {
        miTmp*=-1;
    }
    if(mfPitch >=20)
    {
        mfPitch =-20;
    }
    if(mfYaw >=360)
    {
        miTmp2 =-1;
    }
    else if(mfYaw <=0)
    {
        miTmp2 =1;
    }
    mParamVarianList[0]=mstrLon;
    mParamVarianList[1]=mstrLat;
    emit sigMTIChange();
    emit sigWidgetSizeChange();

}

void QMLCommunicate::ChangeSize(int iWidget,int iHeight)
{
    miWidth=iWidget;
    miHeight=iHeight;
    mWidgetParamList[0]=QVariant::fromValue(miWidth);
    mWidgetParamList[1]=QVariant::fromValue(miHeight);
    emit sigWidgetSizeChange();
}

void QMLCommunicate::ChangeStatusDisplaySize(int iWidget,int iHeight)
{
    miStatusWidgetWidth=iWidget;
    miStatusWidgetHeight=iHeight;
    mWidgetParamList[2]=QVariant::fromValue(miStatusWidgetWidth);
    mWidgetParamList[3]=QVariant::fromValue(miStatusWidgetHeight);

    emit sigWidgetSizeChange();
}

void QMLCommunicate::ChangeCommandDisplaySize(int iWidget,int iHeight)
{
    miCommandWidgetWidth=iWidget;
    miCommandWidgetHeight=iHeight;
    mWidgetParamList[4]=QVariant::fromValue(miCommandWidgetWidth);
    mWidgetParamList[5]=QVariant::fromValue(miCommandWidgetHeight);
    emit sigWidgetSizeChange();
}

void QMLCommunicate::ChangeUAVLogoDisplaySize(int iWidget,int iHeight)
{
    miUAVLogoWidgetWidth=iWidget;
    miUAVLogoWidgetHeight=iHeight;
    mWidgetParamList[6]=QVariant::fromValue(miUAVLogoWidgetWidth);
    mWidgetParamList[7]=QVariant::fromValue(miUAVLogoWidgetHeight);
    emit sigWidgetSizeChange();
}

void QMLCommunicate::ChangeMagDisplaySize(int iWidget,int iHeight)
{
    miMagWidgetWidth=iWidget;
    miMagWidgetHeight=iHeight;
    mWidgetParamList[8]=QVariant::fromValue(miMagWidgetWidth);
    mWidgetParamList[9]=QVariant::fromValue(miMagWidgetHeight);
    emit sigWidgetSizeChange();
}


void QMLCommunicate::ChangeSerialSettingDisplaySize(int iWidget,int iHeight)
{

    miSerialSettingWidgetWidth=iWidget;

    miSerialSettingWidgetHeight=iHeight;
#if 1
    mWidgetParamList[10]=QVariant::fromValue(miSerialSettingWidgetWidth);
    mWidgetParamList[11]=QVariant::fromValue(miSerialSettingWidgetHeight);
//    emit sigWidgetSizeChange();
#endif
}

QColor QMLCommunicate::ReadDataColor()
{
    return QColor(180,10,10);
}

void QMLCommunicate::ChangeLocation(QString strLon,QString strLat)
{
    mstrLat=strLat;
    mstrLon=strLon;
}

QVariantList QMLCommunicate::ReadParam()
{
    return mParamVarianList;
}

QString QMLCommunicate::ReadLon()
{
    return mstrLon;
}

QString QMLCommunicate::ReadLat()
{
    return mstrLat;
}

int   QMLCommunicate::ReadItemSize()
{
    return miItemSize;
}

float QMLCommunicate::ReadRoll()
{
    return mfRoll;
}

float QMLCommunicate::ReadPitch()
{
    return mfPitch;
}

float QMLCommunicate::ReadYaw()
{
    return mfYaw;
}

void QMLCommunicate::testChangeRoll()
{
    mfRoll = -60;
}

void QMLCommunicate::testChangePitch()
{
    mfPitch = -60;
}

void QMLCommunicate::testChangeYaw()
{
    mfYaw = 270;
}


void QMLCommunicate::ChangeRoll()
{
    mfRoll = -60;
}

void QMLCommunicate::ChangePitch()
{
    mfPitch = -60;
}

void QMLCommunicate::ChangeYaw()
{
    mfYaw = 270;
}
