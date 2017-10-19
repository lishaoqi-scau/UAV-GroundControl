#ifndef QMLCOMMUNICATE_H
#define QMLCOMMUNICATE_H

#include <QObject>
#include <QTimer>
#include <QDebug>
#include <QColor>
#include "readini.h"

class QMLCommunicate : public QObject
{
    Q_OBJECT
public:
    explicit QMLCommunicate(QObject *parent = nullptr);
    float mfRoll;
    float mfPitch;
    float mfYaw;
    QString mstrLon;
    QString mstrLat;
    int   miItemSize;
    int  miWidth;
    int miHeight;
    int miStatusWidgetWidth;
    int miStatusWidgetHeight;
    int miCommandWidgetWidth;
    int miCommandWidgetHeight;
    int miUAVLogoWidgetWidth;
    int miUAVLogoWidgetHeight;
    int miMagWidgetWidth;
    int miMagWidgetHeight;
    int miSerialSettingWidgetWidth;
    int miSerialSettingWidgetHeight;
    int   miTmp;
    int   miTmp2;
    QTimer * mTimer;
    QColor * mTextColor;
    QVariantList mWidgetParamList;
    QVariantList mParamVarianList;
    QVariantList mFlyPrepareDataVarianList;
    Q_INVOKABLE void testChangeRoll();
    Q_INVOKABLE void testChangePitch();
    Q_INVOKABLE void testChangeYaw();
    Q_PROPERTY(float ReadRoll READ ReadRoll NOTIFY sigMTIChange) ;
    Q_PROPERTY(float ReadPitch READ ReadPitch) ;
    Q_PROPERTY(float ReadYaw READ ReadYaw);
    Q_PROPERTY(int ReadItemSize READ ReadItemSize);
    Q_PROPERTY(QString ReadLon READ ReadLon);
    Q_PROPERTY(QString ReadLat READ ReadLat);
    Q_PROPERTY(QColor ReadDataColor READ ReadDataColor);
    Q_PROPERTY(QVariantList ReadParam READ ReadParam);
    Q_PROPERTY(QVariantList ReadWidgetParam READ ReadWidgetParam);
    Q_PROPERTY(QVariantList ReadFlyPrepareData READ ReadFlyPrepareData WRITE WriteFlyPrepareData);
    Q_PROPERTY(float  sigMTIChange READ sigMTIChange);
    Q_PROPERTY(float  sigWidgetSizeChange READ sigWidgetSizeChange);
public:
    Q_INVOKABLE void qmlCallFlyPreparefunction(QVariantList strList);
    float ReadRoll();
    float ReadPitch();
    float ReadYaw();
    int   ReadItemSize();
    QString ReadLon();
    QString ReadLat();
    QColor  ReadDataColor();
    QVariantList ReadParam();
    QVariantList ReadWidgetParam();
    QVariantList ReadFlyPrepareData();
    void ChangeSize(int iWidth,int iHeight);
    void ChangeStatusDisplaySize(int iWidget,int iHeight);
    void ChangeCommandDisplaySize(int iWidget,int iHeight);
    void ChangeUAVLogoDisplaySize(int iWidget,int iHeight);
    void ChangeMagDisplaySize(int iWidth,int iHeight);
    void ChangeSerialSettingDisplaySize(int iWidget,int iHeight);
    void WriteFlyPrepareData(QVariantList &qmlcommunicate);
    void SetReadIni(ReadIni * ini);
signals:
    float sigMTIChange();
    float sigWidgetSizeChange();
    void sigChangeRoll();
    void sigChangePitch();
    void sigChangeYaw();
public slots:
    void Update();
    void ChangeRoll();
    void ChangePitch();
    void ChangeYaw();
    void ChangeLocation(QString,QString);
private:
    ReadIni * mReadIni;
};

#endif // QMLCOMMUNICATE_H
