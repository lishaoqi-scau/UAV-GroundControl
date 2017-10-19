#ifndef SERIALSETTINGWIDGET_H
#define SERIALSETTINGWIDGET_H

#include <QWidget>
#include <QMainWindow>
#include <QApplication>
#include <QDesktopWidget>
#include <QtDataVisualization/QtDataVisualizationVersion>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QtQuickWidgets/QQuickWidget>
#include <QQuickView>
#include <QMessageBox>
#include <QQmlContext>
#include "qmlcommunicate.h"

class SerialSettingWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SerialSettingWidget(QWidget *parent = 0);

signals:
    QRect sigGetAppRect();
public slots:
    void Display(bool);
    void WidgetSetting(QMLCommunicate * mQMLCom);
    void ChangeRect();
private:
    QQuickWidget  * mSerialSettingDisplayView;
    QWidget * mQMLcontainer;
    QWidget * mparentWidget;
    QMLCommunicate * mQMLCom;
private:
    void SetSize();

};

#endif // SERIALSETTINGWIDGET_H
