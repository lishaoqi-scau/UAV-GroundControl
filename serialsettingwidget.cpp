#include "serialsettingwidget.h"

SerialSettingWidget::SerialSettingWidget(QWidget *parent) : QWidget(parent)
{
    mparentWidget=parent;
}


void SerialSettingWidget::WidgetSetting(QMLCommunicate * QMLCom)
{

    mSerialSettingDisplayView = new QQuickWidget(mparentWidget);
    mQMLCom = QMLCom;
    mSerialSettingDisplayView->setSource(QUrl(QStringLiteral("qrc:/SerialSettingWidget.qml")));
    QQmlContext* context=mSerialSettingDisplayView->rootContext();
     context->setContextProperty("mQMLCom",mQMLCom);
    mSerialSettingDisplayView->setAttribute(Qt::WA_AlwaysStackOnTop, true); //这两句是使QML背景透明
    mSerialSettingDisplayView->setClearColor(QColor(Qt::transparent));
}


void SerialSettingWidget::ChangeRect()
{
    QRect rectApp = sigGetAppRect();
    qDebug()<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!----->"<<rectApp.width()<<"    "<<rectApp.height();

    mparentWidget->setGeometry(0.3*rectApp.width(),0.3*rectApp.height(),0.4*rectApp.width(),0.4*rectApp.height());

    mSerialSettingDisplayView->setGeometry(0,0,0.4*rectApp.width(),0.4*rectApp.height());
#if 1
    mQMLCom->ChangeSerialSettingDisplaySize(0.4*rectApp.width(),0.4*rectApp.height());
#endif
}


void SerialSettingWidget::Display(bool bChecked)
{
    if(bChecked)
    {
        if(mparentWidget != NULL)
        {

            //mparentWidget->show();
             //this->SetSize();
             mSerialSettingDisplayView->show();
             ChangeRect();

        }
    }
    else
    {
       //QMessageBox::information(NULL,"aaaa"," bbbb", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
       //mparentWidget->hide();
       mSerialSettingDisplayView->hide();
    }
}

//这里是以整屏为标准所以不用传入参数
void SerialSettingWidget::SetSize()
{
    int hight = QApplication::desktop()->height();
    int width = QApplication::desktop()->width();
    QString str1=QString("%1   %2").arg(width).arg(hight);
//    QMessageBox::information(NULL,"aaaa",str1, QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    mparentWidget->setGeometry(0.3*width,0.3*hight,0.4*width,0.4*hight);
    mSerialSettingDisplayView->setGeometry(0,0,0.4*width,0.4*hight);
}
