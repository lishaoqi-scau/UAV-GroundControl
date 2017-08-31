#ifndef VLCPLAYER_H
#define VLCPLAYER_H

#include <QThread>
#include <vlc/vlc.h>
#include <vlc/libvlc.h>
#include <QDebug>
#include <QMessageBox>
#include <QSlider>
#include <QPushButton>
#include <QPalette>
#include <QFileDialog>

class VLCPlayer : public QThread
{
    Q_OBJECT
public:
    explicit VLCPlayer(QWidget *parent = 0);
    void SetPlayWidget(QWidget * PlayWidget);
    void SetStartButton(QPushButton * StartButton);
    void SetSetButton(QPushButton * SetButton);
    void SetValumeSlider(QSlider * ValumeSlider);
    void SetPlayPointSlider(QSlider * PlayPointSlider);
    bool CheckPlaying();
    ~VLCPlayer();
signals:

public:
    libvlc_instance_t *vlcInstance;
    libvlc_media_player_t *vlcPlayer;

public slots:
    void play();
    void stop();
    void Pause();
    void changeVolume(int vol);
    void openFile(QString strURL);
    void LoadRTSPStream(QString strURL);
private:

    QWidget * mPlayWidgetView; //播放界面控件
    QPushButton * mStartButton;//开始按键
    QPushButton * mSetButton;//设置按键
    QSlider    * mValumeSlider;//音量条
    QSlider    * mPlayPointSlider;//播放进度条
    QWidget * mParentWidget;
};

#endif // VLCPLAYER_H
