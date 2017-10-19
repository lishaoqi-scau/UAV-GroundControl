#ifndef MENUWIDGETMANAGER_H
#define MENUWIDGETMANAGER_H

#include <QWidget>
#include <QRect>
#include <serialsettingwidget.h>
#include <qmlcommunicate.h>
#include "flypreparewidget.h"

class MenuWidgetManager : public QWidget
{
    Q_OBJECT
public:
    explicit MenuWidgetManager(QMLCommunicate * QMLCom, QWidget *parent = 0);

signals:
    QRect sigGetAppRect();

public slots:
    void SetMenuWidget();
    void SerialSettingShow(bool);
    void FlyPrepareShow(bool bIsShow);
private:
    void SetSerialSettingDisplay();
    void SetFlyPrepareDisplay();
private:
    QMLCommunicate * mQMLCom;
    SerialSettingWidget * mSerialSetting;
    FlyPrepareWidget * mFlyPrepare;
};

#endif // MENUWIDGETMANAGER_H
