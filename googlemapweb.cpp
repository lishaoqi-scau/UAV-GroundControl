#include "googlemapweb.h"

void MapRefresher::refreshMap()
{
  emit refreshMapSignal();
}


void MapRefresher::getCoordinate(QString lon,QString lat)
{
    qDebug()<<"Lon:"<<lon<<"    "<<"Lat"<<lat;
}



Googlemapweb::Googlemapweb(QWebEngineView * webview, QWidget *parent) :
    QWidget(parent)
{
    mwebview = webview;
    mwebview->resize(parent->contentsRect().width(),parent->contentsRect().height());
    mMapRef = new MapRefresher;
    connect(mMapRef, SIGNAL(refreshMapSignal()), this, SIGNAL(refreshMap()));
    QString strMapPath="file:///";
    strMapPath+=QCoreApplication::applicationDirPath();
    strMapPath+="/localised.html";
    qDebug()<<"AAAAAA"<<parent->contentsRect().width()<<parent->contentsRect().height();
    QUrl url(strMapPath);
//    mwebview->setPage(this);

    channel = new QWebChannel(this);
    mwebview->page()->setWebChannel(channel);
    channel->registerObject(QStringLiteral("ReinforcePC"),this);
//  mwebview->load(QUrl("https://www.google.com/maps/preview"));
    mwebview->load(url);
    QWebEngineProfile webprofile;
    webprofile.setHttpUserAgent("Mozilla/5.0 (Windows; U; Windows NT 5.2) AppleWebKit/525.13 (KHTML, like Gecko) Chrome/0.2.149.27 Safari/525.13 ");
//    mwebview->setContentsMargins(0,0,0,0);
//    mwebview->setTextSizeMultiplier(1);//设置网页字体大小

}

void Googlemapweb::resizeEvent(QResizeEvent *event)
{
    qDebug()<<"Widget size --->"<<this->size().width()<<this->size().height();
}


void Googlemapweb::setCoordinate(QString lon,QString lat)
{

#if 0
#else
 //   QWebFrame *webFrame = mwebview->page()->mainFrame();
    QString cmd = QString("showAddress(\"%1\",\"%2\")").arg(lon).arg(lat);
    this->executeJavascript(cmd);
#endif
}

void Googlemapweb::ChangeRect(int x,int y,int iWidget, int iHeight)
{
    //this->resize(iWidget,iHeight);
//    this->parent()->setGeometry(x,y,iWidget,iHeight);
    this->mwebview->resize(iWidget,iHeight);
}

void Googlemapweb::on_pushButtonStreetMap_clicked()
{
#if 1
#else
    QWebFrame *frame = mwebview->page()->mainFrame();
    QString cmd = QString("showStreetMap()");
    frame->evaluateJavaScript(cmd);
#endif
}

void Googlemapweb::SetUAVMakerPosition(QString strLon,QString strLat)
{
#if 1
#else

    QWebFrame *webFrame = mwebview->page()->mainFrame();
    QString cmd = QString("SetUAVMakerPosition(\"%1\",\"%2\")").arg(strLon).arg(strLat);
    webFrame->evaluateJavaScript(cmd);
    qDebug()<<"Lon:"<<strLon<<"     "<<"Lat:"<<strLat;
#endif
}

void Googlemapweb::on_pushButtonSatelliteMap_clicked()
{
#if 1
#else
    QWebFrame *frame = mwebview->page()->mainFrame();
    QString cmd = QString("showSatelliteMap()");
    frame->evaluateJavaScript(cmd);
#endif
}

void Googlemapweb::getCoordinate(QString lon,QString lat)
{
#if 0
    QMessageBox::information(NULL,lon, lat, QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
#else
    mstrLon=lon;
    mstrLat=lat;
//     qDebug()<<"Lon:"<<lon<<"    "<<"Lat:"<<lat;
    emit this->SendLocation(lon,lat);
#endif
}


void Googlemapweb::slotPopulateJavaScriptWindowObject()
{
#if 1
#else
   mwebview->page()->mainFrame()->addToJavaScriptWindowObject("ReinforcePC", this);
#endif
}



QString Googlemapweb::userAgentForUrl ( const QUrl & url ) const
{
#if 0
#else
//    return "Mozilla/5.0 (Windows NT 6.1; WOW64; rv:27.0) Gecko/20100101 Firefox/27.0";    //火狐的agent
      return "Mozilla/5.0 (Windows; U; Windows NT 5.2) AppleWebKit/525.13 (KHTML, like Gecko) Chrome/0.2.149.27 Safari/525.13 ";//360的agent
//    return "Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/60.0.3112.90 Safari/537.36";  //chrome 的agent
#endif
}

void Googlemapweb::executeJavascript(const QString &jsCode)
{
#ifdef QT_HAS_WEBKIT
  return frame->evaluateJavaScript(jsCode);
#else
  mwebview->page()->runJavaScript(jsCode);
#endif
}
