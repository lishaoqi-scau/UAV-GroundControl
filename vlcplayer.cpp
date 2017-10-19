#include "vlcplayer.h"

VLCPlayer::VLCPlayer(QWidget *parent) :
    QThread(parent)
{
    this->mParentWidget=parent;
    vlcPlayer = NULL;
    vlcInstance = libvlc_new(0, NULL);
    /* Complain in case of broken installation */
    if (vlcInstance == NULL) {
        //QMessageBox::critical(this, "Qt libVLC player", "Could not init libVLC");
        qDebug()<<"Create libvlc error..";
        exit(1);
    }
}


void VLCPlayer::SetPlayWidget(QWidget *PlayWidget)
{
       this->mPlayWidgetView = PlayWidget;
#if 1
    mPlayWidgetView->setAutoFillBackground( true );
    QPalette plt = this->mPlayWidgetView->palette();
    plt.setColor( QPalette::Window, Qt::red );
    mPlayWidgetView->setPalette( plt );
#endif
}

void VLCPlayer::SetStartButton(QPushButton *StartButton)
{
    this->mStartButton=StartButton;
    if(this->mStartButton != NULL)
    {
        connect(this->mStartButton,SIGNAL(clicked()),this,SLOT(play()));
    }
}


void VLCPlayer::changeVolume(int vol)
{
    if (vlcPlayer)
       {
        libvlc_audio_set_volume (vlcPlayer,vol);
     }

    return ;
}


bool VLCPlayer::CheckPlaying()
{
    if (!vlcPlayer)
        return false;
    if(libvlc_media_player_is_playing(vlcPlayer))
    {
          return true;
    }
    else
    {
          return false;
    }
}

void VLCPlayer::Pause()
{
    if (!vlcPlayer)
        return;
    if (libvlc_media_player_is_playing(vlcPlayer))
    {
        /* Pause */
        libvlc_media_player_pause(vlcPlayer);

    }
}

void VLCPlayer::play()
{
    if (!vlcPlayer)
        return;
    if(!libvlc_media_player_is_playing(vlcPlayer))
    {
        libvlc_media_player_play(vlcPlayer);

   }
}


void VLCPlayer::stop()
{
    if(vlcPlayer) {
        /* stop the media player */
        libvlc_media_player_stop(vlcPlayer);
        /* release the media player */
        libvlc_media_player_release(vlcPlayer);
        /* Reset application values */
        vlcPlayer = NULL;

    }
}


void VLCPlayer::LoadRTSPStream(QString strURL)
{
    //libvlc_media_new_path
}

void VLCPlayer::openFile(QString strURL)
{

    /* The basic file-select box */
//    QString fileOpen = QFileDialog::getOpenFileName(this->mParentWidget, tr("Load a file"),"~");

    /* Stop if something is playing */


    if (vlcPlayer && libvlc_media_player_is_playing(vlcPlayer))
        stop();
    libvlc_media_t *vlcMedia = NULL;
    /* Create a new Media */
    if(strURL.startsWith("http")||strURL.startsWith("rtsp")||strURL.startsWith("rtmp"))
    {
        char*  ch;
        QByteArray ba = strURL.toLatin1();
        ch=ba.data();
        vlcMedia = libvlc_media_new_location(vlcInstance, (ch));
    }
    else
    {
        strURL.replace(":/",":\\");
        char*  ch;
        QByteArray ba = strURL.toLatin1();
        ch=ba.data();

        vlcMedia = libvlc_media_new_path(vlcInstance, (ch));
    }
    if (!vlcMedia)
        return;
    /* Create a new libvlc player */
    vlcPlayer = libvlc_media_player_new_from_media (vlcMedia);
    QString str1=QString("%1:%2").arg(mPlayWidgetView->width()).arg(mPlayWidgetView->height());
    qDebug()<<"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW"<<str1<<"tttttt"<<mPlayWidgetView->width()<<mPlayWidgetView->height();
    if(vlcPlayer !=NULL)
    {
        libvlc_video_set_aspect_ratio(vlcPlayer,str1.toLocal8Bit().data());
    }
    /* Release the media */
    libvlc_media_release(vlcMedia);

    /* Integrate the video in the interface */

    libvlc_media_player_set_hwnd(vlcPlayer, (void*)this->mPlayWidgetView->winId());

    /* And start playback */
    libvlc_media_player_play (vlcPlayer);

    /* Update playback button */

}

void VLCPlayer::FullWidget(int x, int y)
{
    QString str1=QString("%1:%2").arg(x).arg(y);

    if(vlcPlayer !=NULL)
    {
        libvlc_video_set_aspect_ratio(vlcPlayer,str1.toLocal8Bit().data());
    }
}


VLCPlayer::~VLCPlayer()
{
    if (vlcInstance)
        libvlc_release(vlcInstance);
}
