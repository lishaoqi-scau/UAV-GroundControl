#include "flypreparewidget.h"

FlyPrepareWidget::FlyPrepareWidget(QWidget *parent) : QWidget(parent)
{
    mparentWidget = parent;
}


void FlyPrepareWidget::WidgetSetting(QMLCommunicate * QMLCom)
{

    mFlyPrepareDisplayView = new QQuickWidget(mparentWidget);
    mQMLCom = QMLCom;
    mFlyPrepareDisplayView->setSource(QUrl(QStringLiteral("qrc:/FlyPrepareWidget.qml")));
    QQmlContext* context=mFlyPrepareDisplayView->rootContext();
     context->setContextProperty("mQMLCom",mQMLCom);
    mFlyPrepareDisplayView->setAttribute(Qt::WA_AlwaysStackOnTop, true); //这两句是使QML背景透明
    mFlyPrepareDisplayView->setClearColor(QColor(Qt::transparent));
    //QQuickItem * rootobject = mFlyPrepareDisplayView->rootObject();
    QObject::connect(mFlyPrepareDisplayView,SIGNAL(sigSendRecordData(int)),this,SLOT(Receive(int)));
}

void FlyPrepareWidget::Receive(int list)
{
    qDebug()<<"xxxxxx!!!!!!!!!!!!!!!!!!!----->"<<list;
}


void FlyPrepareWidget::ChangeRect()
{
    QRect rectApp = sigGetAppRect();
    qDebug()<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!----->"<<rectApp.width()<<"    "<<rectApp.height();

    mparentWidget->setGeometry(0.3*rectApp.width(),0.2*rectApp.height(),0.4*rectApp.width(),0.6*rectApp.height());

    mFlyPrepareDisplayView->setGeometry(0,0,0.4*rectApp.width(),0.6*rectApp.height());
#if 1
    mQMLCom->ChangeSerialSettingDisplaySize(0.4*rectApp.width(),0.6*rectApp.height());
#endif
}


void FlyPrepareWidget::Display(bool bChecked)
{
    if(bChecked)
    {
        if(mparentWidget != NULL)
        {

            //mparentWidget->show();
             //this->SetSize();
             mFlyPrepareDisplayView->show();
             ChangeRect();

        }
    }
    else
    {
       //mparentWidget->hide();
       mFlyPrepareDisplayView->hide();
    }
}

//这里是以整屏为标准所以不用传入参数
void FlyPrepareWidget::SetSize()
{
    int hight = QApplication::desktop()->height();
    int width = QApplication::desktop()->width();
    QString str1=QString("%1   %2").arg(width).arg(hight);
    mparentWidget->setGeometry(0.3*width,0.3*hight,0.4*width,0.4*hight);
    mFlyPrepareDisplayView->setGeometry(0,0,0.4*width,0.4*hight);
}
