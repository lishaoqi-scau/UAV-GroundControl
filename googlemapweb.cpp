#include "googlemapweb.h"


Googlemapweb::Googlemapweb(QWebView * webview, QWidget *parent) :
    QWebPage(parent)
{
    mwebview = webview;
    QString strMapPath="file:///";
    strMapPath+=QCoreApplication::applicationDirPath();
    strMapPath+="/localised.html";
 #if 0
    ui->webView->settings()->setAttribute(QWebSettings::PluginsEnabled, true);
    ui->webView->settings()->setAttribute(QWebSettings::JavascriptEnabled, true);
        ui->webView->settings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);
        ui->webView->settings()->setAttribute(QWebSettings::JavascriptCanOpenWindows, true);
        ui->webView->settings()->setAttribute(QWebSettings::JavaEnabled, true);
#endif
    QUrl url(strMapPath);
    mwebview->setPage(this);
    mwebview->load(url);
    mwebview->setContentsMargins(0,0,0,0);
    mwebview->setTextSizeMultiplier(1);//设置网页字体大小
    //ui->webView->

    QWidget::connect(mwebview->page()->mainFrame(), SIGNAL(javaScriptWindowObjectCleared()),
            this, SLOT(slotPopulateJavaScriptWindowObject()));
}


void Googlemapweb::setCoordinate(QString lon,QString lat)
{

    QWebFrame *webFrame = mwebview->page()->mainFrame();
    QString cmd = QString("showAddress(\"%1\",\"%2\")").arg(lon).arg(lat);
    webFrame->evaluateJavaScript(cmd);
}


void Googlemapweb::on_pushButtonStreetMap_clicked()
{
    QWebFrame *frame = mwebview->page()->mainFrame();
    QString cmd = QString("showStreetMap()");
    frame->evaluateJavaScript(cmd);
}

void Googlemapweb::SetUAVMakerPosition(QString strLon,QString strLat)
{
    QWebFrame *webFrame = mwebview->page()->mainFrame();
    QString cmd = QString("SetUAVMakerPosition(\"%1\",\"%2\")").arg(strLon).arg(strLat);
    webFrame->evaluateJavaScript(cmd);
    qDebug()<<"Lon:"<<strLon<<"     "<<"Lat:"<<strLat;
}

void Googlemapweb::on_pushButtonSatelliteMap_clicked()
{
    QWebFrame *frame = mwebview->page()->mainFrame();
    QString cmd = QString("showSatelliteMap()");
    frame->evaluateJavaScript(cmd);
}

void Googlemapweb::getCoordinate(QString lon,QString lat)
{
    emit this->SendLocation(lon,lat);
}


void Googlemapweb::slotPopulateJavaScriptWindowObject()
{
   mwebview->page()->mainFrame()->addToJavaScriptWindowObject("ReinforcePC", this);
}



QString Googlemapweb::userAgentForUrl ( const QUrl & url ) const
{
//    return "Mozilla/5.0 (Windows NT 6.1; WOW64; rv:27.0) Gecko/20100101 Firefox/27.0";    //火狐的agent
      return "Mozilla/5.0 (Windows; U; Windows NT 5.2) AppleWebKit/525.13 (KHTML, like Gecko) Chrome/0.2.149.27 Safari/525.13 ";//360的agent
//    return "Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/60.0.3112.90 Safari/537.36";  //chrome 的agent
}
