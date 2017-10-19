#include "menuwidgetmanager.h"

MenuWidgetManager::MenuWidgetManager(QMLCommunicate * QMLCom,QWidget *parent) : QWidget(parent)
{
    mQMLCom = QMLCom;
    mSerialSetting = new SerialSettingWidget(this);
    mFlyPrepare    = new FlyPrepareWidget(this);
    this->SetSerialSettingDisplay();
    this->SetFlyPrepareDisplay();
    connect(mSerialSetting,SIGNAL(sigGetAppRect()),this,SIGNAL(sigGetAppRect()));
    connect(mFlyPrepare,SIGNAL(sigGetAppRect()),this,SIGNAL(sigGetAppRect()));
}


void MenuWidgetManager::SetMenuWidget()
{
        this->setAutoFillBackground( true );
        this->setAttribute(Qt::WA_TranslucentBackground);//±³¾°Í¸Ã÷
        this->setStyleSheet("background-color: rgb(222, 222, 222,100);");
        QPalette pal = this->palette();
        pal.setColor(QPalette::Background, QColor(0x00,0x00,0x00,0x00));
        this->setPalette(pal);

}


void MenuWidgetManager::SetFlyPrepareDisplay()
{
    mFlyPrepare->WidgetSetting(mQMLCom);
    mFlyPrepare->Display(false);
}

void MenuWidgetManager::SetSerialSettingDisplay()
{
    mSerialSetting->WidgetSetting(mQMLCom);
    mSerialSetting->Display(false);
}


void MenuWidgetManager::FlyPrepareShow(bool bIsShow)
{
    mFlyPrepare->Display(bIsShow);
}

void MenuWidgetManager::SerialSettingShow(bool bIsShow)
{
    mSerialSetting->Display(bIsShow);
}
