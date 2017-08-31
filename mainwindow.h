#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QApplication>
#include <QDesktopWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include "googlemapweb.h"
#include "vlcplayer.h"
#include "readini.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void StartPlay();
    void StopPlay();
    void ShowLocation(QString strLon,QString strLat);
    void ChoseFile();
    void SetUAVMakerPosition();
    
private:
    Ui::MainWindow *ui;
    QWebView * mWebView;
    Googlemapweb * myweb;
    //QWidget * mWidget;
    VLCPlayer * mVlcPlayer;
    QLineEdit * mURLedit;
    QPushButton * mStartButton;
    QPushButton * mChoseFileButton;
    QPushButton * mStopButton;
    QHBoxLayout *  mlayoutVLCControler;
    QLabel      * mlabelLat;
    QLabel      * mlabelLon;
    QString    strOldURL;
    ReadIni * mRecordFile;
    QLineEdit * mLonEdit;
    QLineEdit * mLatEdit;
    QPushButton * mSetPositionButton;
};

#endif // MAINWINDOW_H
