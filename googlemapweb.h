#ifndef GOOGLEMAPWEB_H
#define GOOGLEMAPWEB_H

#include <QMainWindow>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QtWebEngineWidgets/QtWebEngineWidgets>
#include <QCoreApplication>
#include <QtWebChannel/QWebChannel>
#include <QDebug>


class MapRefresher : public QObject {

  Q_OBJECT

public slots:

  void refreshMap();
  void getCoordinate(QString lon,QString lat);
signals:

  void refreshMapSignal();

};


class Googlemapweb : public QWidget
{
    Q_OBJECT
//    Q_PROPERTY(QString param1 READ ReinforcePC WRITE getCoordinate)
//    Q_PROPERTY(QString param2 READ ReinforcePC WRITE getCoordinate)
public:
    Googlemapweb(QWebEngineView * qwebview,QWidget *parent = 0);
    QString userAgentForUrl(const QUrl &url) const;
    void ChangeRect(int x,int y,int iWidget,int iHeight);
    QString mstrLon;
    QString mstrLat;
signals:
    void SendLocation(QString strLon,QString strLat);
public slots:
    void setCoordinate(QString lon,QString lat);
    void getCoordinate(QString lon,QString lat);
    void SetUAVMakerPosition(QString strLon,QString strLat);
    void on_pushButtonSatelliteMap_clicked();
    void on_pushButtonStreetMap_clicked();
    void slotPopulateJavaScriptWindowObject();
protected:
    void resizeEvent(QResizeEvent *event);
private:
    QWebEngineView * mwebview;
    QWebChannel *channel;
    MapRefresher * mMapRef;
private:
    void executeJavascript(const QString &jsCode);
};


#endif // GOOGLEMAPWEB_H
