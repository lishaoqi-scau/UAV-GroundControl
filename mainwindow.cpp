#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mRecordFile = new ReadIni("record.ini");
    mVlcPlayer = new VLCPlayer(this);
    mVlcPlayer->SetPlayWidget(ui->vlcplayerwidget);
    mlayoutVLCControler = new QHBoxLayout(this);
    mWebView = new QWebView(this);
    mLonEdit = new QLineEdit(this);
    mLatEdit = new QLineEdit(this);
    mSetPositionButton = new QPushButton("SetUAVPosition",this);
    mURLedit = new QLineEdit(this);
    mStartButton = new QPushButton("Start",this);
    mStopButton  = new QPushButton("Stop",this);
    mChoseFileButton  = new QPushButton("ChoseFile",this);
    mlabelLon = new QLabel(this);
    mlabelLat = new QLabel(this);

    mlayoutVLCControler->addWidget(mURLedit);
    mlayoutVLCControler->addWidget(mStartButton);
    myweb = new Googlemapweb(mWebView,this);

    QString strURL;
    QString strLon;
    QString strLat;
    mRecordFile->getKeyValue(strURL,"","URL","Record");
    mRecordFile->getKeyValue(strLon,"","Lon","Record");
    mRecordFile->getKeyValue(strLat,"","Lat","Record");
    mLonEdit->setText(strLon);
    mLatEdit->setText(strLat);
    mURLedit->setText(strURL);
    int hight = QApplication::desktop()->height();
    int width = QApplication::desktop()->width();
    this->setWindowState(Qt::WindowMaximized);

    mWebView->setGeometry(5,20,width*50/100,hight*75/100);
    ui->vlcplayerwidget->setGeometry(5+width*50/100,8,width*50/100-10,hight*75/100);
    QRect rectTmp(5+width*50/100,hight*80/100-20,width*50/100-10,hight*20/100);
    mlayoutVLCControler->setGeometry(rectTmp);
    connect(this->mStartButton,SIGNAL(clicked()),this,SLOT(StartPlay()));
    connect(this->mStopButton,SIGNAL(clicked()),this,SLOT(StopPlay()));
    mlabelLon->setGeometry(55,hight*78/100,152,30);
    mlabelLat->setGeometry(5+300,hight*78/100,152,30);
    mURLedit->setGeometry(width*52/100,hight*85/100,width*25/100,40);
    mLonEdit->setGeometry(width*2/100,hight*85/100,width*15/100,40);
    mLatEdit->setGeometry(width*19/100,hight*85/100,width*15/100,40);
    mSetPositionButton->setGeometry(width*36/100,hight*85/100,width*8/100,40);
    mStartButton->setGeometry(width*77/100,hight*85/100,width*6/100,40);
    mStopButton->setGeometry(width*84/100,hight*85/100,width*6/100,40);
    mChoseFileButton->setGeometry(width*91/100,hight*85/100,width*6/100,40);
    connect(myweb,SIGNAL(SendLocation(QString,QString)),this,SLOT(ShowLocation(QString,QString)));
    connect(this->mSetPositionButton,SIGNAL(clicked()),this,SLOT(SetUAVMakerPosition()));
    connect(mChoseFileButton,SIGNAL(clicked()),this,SLOT(ChoseFile()));
    QFont font;
    font.setPointSize(12);
    mlabelLon->setFont(font);
    mlabelLat->setFont(font);
}

void MainWindow::ShowLocation(QString strLon,QString strLat)
{
    mlabelLon->setText(tr("经度：")+strLon);
    mlabelLat->setText(tr("纬度：")+strLat);
}

void MainWindow::StopPlay()
{
    if(mVlcPlayer->vlcPlayer != NULL)
    {
         mVlcPlayer->stop();
         mStartButton->setText("Start");
    }
}


void MainWindow::StartPlay()
{
    if(mVlcPlayer->CheckPlaying())
    {
        mVlcPlayer->Pause();
        this->mStartButton->setText("Start");
    }
    else
    {
        if(mVlcPlayer->vlcPlayer == NULL )//完全没播放视频
        {
            mVlcPlayer->openFile(this->mURLedit->text());
            mRecordFile->setKeyValue(this->mURLedit->text(),"URL","Record");
            mRecordFile->SaveFile();
            strOldURL = this->mURLedit->text();
            mVlcPlayer->play();
            this->mStartButton->setText("Pause");
        }
        else//已经初始化过视频
        {
            if(this->mURLedit->text()==NULL || !this->mURLedit->text().compare(strOldURL)) //如果输入的URL为空或都和之前的一样就不用切换，否则就切换视频
            {
                mVlcPlayer->play();
                this->mStartButton->setText("Pause");
            }
            else
            {
                mVlcPlayer->stop();
                mVlcPlayer->openFile(this->mURLedit->text());
                mRecordFile->setKeyValue(this->mURLedit->text(),"URL","Record");
                mRecordFile->SaveFile();
                strOldURL = this->mURLedit->text();
                mVlcPlayer->play();
                this->mStartButton->setText("Pause");
            }
        }
    }
}


void MainWindow::SetUAVMakerPosition()
{
        mRecordFile->setKeyValue(this->mLonEdit->text(),"Lon","Record");
        mRecordFile->setKeyValue(this->mLatEdit->text(),"Lat","Record");
        mRecordFile->SaveFile();
        myweb->SetUAVMakerPosition(this->mLonEdit->text(),this->mLatEdit->text());
}

void MainWindow::ChoseFile()
{
     this->mURLedit->setText(QFileDialog::getOpenFileName(this, tr("Load a file"),"~"));

}

MainWindow::~MainWindow()
{
    delete ui;
}
