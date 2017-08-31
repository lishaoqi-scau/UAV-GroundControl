#ifndef MYWEB_H
#define MYWEB_H

#include <QWebPage>
#include <QWebView>
#include <QCoreApplication>
#include <QWebFrame>
#include <QDebug>
class MyWeb : public QWebPage
{
    Q_OBJECT
public:
    explicit MyWeb(QWebView * qwebview,QWidget *parent = 0);
    QString userAgentForUrl(const QUrl &url) const;
signals:
    void SendLocation(QString strLon,QString strLat);
public slots:
    void setCoordinate(QString lon,QString lat);
    void getCoordinate(QString lon,QString lat);
    void SetUAVMakerPosition(QString strLon,QString strLat);
    void on_pushButtonSatelliteMap_clicked();
    void on_pushButtonStreetMap_clicked();
    void slotPopulateJavaScriptWindowObject();
private:
    QWebView * mwebview;
    
};

#endif // MYWEB_H
