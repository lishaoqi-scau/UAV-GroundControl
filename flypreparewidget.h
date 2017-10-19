#ifndef FLYPREPAREWIDGET_H
#define FLYPREPAREWIDGET_H

#include <QWidget>
#include <QQuickWidget>
#include <QApplication>
#include <QDesktopWidget>
#include <QtDataVisualization/QtDataVisualizationVersion>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QtQuickWidgets/QQuickWidget>
#include <QQuickView>
#include <QMessageBox>
#include <QQmlContext>
#include <qmlcommunicate.h>

class FlyPrepareWidget : public QWidget
{
    Q_OBJECT
public:
    explicit FlyPrepareWidget(QWidget *parent = 0);

signals:
    QRect sigGetAppRect();
public slots:
    void Display(bool);
    void WidgetSetting(QMLCommunicate * mQMLCom);
    void ChangeRect();
    void Receive(int list);
private:
    QQuickWidget  * mFlyPrepareDisplayView;
    QWidget * mQMLcontainer;
    QWidget * mparentWidget;
    QMLCommunicate * mQMLCom;
private:
    void SetSize();

};


#endif // FLYPREPAREWIDGET_H
