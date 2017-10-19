#include "gcsdisplay.h"
#include "ui_gcsdisplay.h"
#if 1
GCSDisplay::GCSDisplay(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GCSDisplay)
{
    ui->setupUi(this);
    this->setWindowTitle("GCS (Ground Control System)");//设置程序标题
    this->setWindowState(Qt::WindowMaximized);//设置窗口为全屏
    int hight = QApplication::desktop()->height();
    int width = QApplication::desktop()->width();
    mReadini = new ReadIni("prame.ini");
    this->setGeometry(0,0,width,hight);
    this->SetQMLCommunicate();
    this->SetToolBar();
    this->SetDockWidget();
    this->SetFlyDataWidget();
    this->SetStatusDisplay();
    this->SetCommandDisplay();
    this->SetUAVLogoDisplay();
    this->SetMagDisplay();

    this->SetMenuWidget();
    this->ChangeSize(this->width(),this->height());
    this->SetButton();
    this->connect(mGoogleMapWeb,SIGNAL(SendLocation(QString,QString)),mQMLCom,SLOT(ChangeLocation(QString,QString)));
    this->connect(ui->FPVaction,SIGNAL(changed()),this,SLOT(DisplayChanged()));
    this->connect(ui->Serialaction,SIGNAL(toggled(bool)),mMenuWidget,SLOT(SerialSettingShow(bool)));
    this->connect(ui->FlyPrepareaction,SIGNAL(toggled(bool)),mMenuWidget,SLOT(FlyPrepareShow(bool)));
    this->connect(mMenuWidget,SIGNAL(sigGetAppRect()),this,SLOT(SendRect()));
    this->connect(ui->Exitaction,SIGNAL(toggled(bool)),this,SLOT(close()));

}



void GCSDisplay::SetQMLCommunicate()
{
    mQMLCom = new QMLCommunicate;
    qmlRegisterType<QMLCommunicate>("an.qt.QMLCommunicate",1,0,"mQMLCom");
    mQMLCom->SetReadIni(mReadini);
}

void GCSDisplay::SetDockWidget(void)
{
    mWebWidget = new QWidget(this);
    mVLCWidget = new QWidget(this);
    mFlyDataWidget = new QWidget(this);
    mCommandWidget = new QWidget(this);
    mVLCPlayer = new VLCPlayer;
    mVLCPlayer->SetPlayWidget(mVLCWidget);
    mGCSStatusWidget = new QWidget(this);
    mGCSCommandWidget = new QWidget(this);
    mGCSUAVLogoWidget = new QWidget(this);
    mWebView = new QWebEngineView(mWebWidget);
    mGoogleMapWeb = new Googlemapweb(mWebView,mWebWidget);
//    mVLCPlayer->openFile(QString("rtmp://live.hkstv.hk.lxdns.com/live/hks"));
//        mVLCPlayer->openFile(QString("D:/\GOPR0859_A01.MP4"));
    mGCSMagWidget = new QWidget(mWebWidget);

    mMenuWidget = new MenuWidgetManager(mQMLCom,this);

//    mSerialSettingWidget->hide();
    //this->setCentralWidget(mWebWidget);
}



void GCSDisplay::onRestoreCatalogueView()
{
    mVLCWidget->setMinimumWidth(0);
    mFlyDataWidget->setMinimumWidth(0);
}

void GCSDisplay::DisplayChanged()
{
    this->ChangeSize(this->width(),this->height());
}

void GCSDisplay::RecordRect()
{

}


void GCSDisplay::ChangeSize(int iWidth,int iHeight)
{
    this->RecordRect();
    this->ChangeFlyDataRect(0.005*iWidth,0.08*iHeight,0.15*iWidth,0.7*iHeight);

    mCommandWidget->setGeometry(0.2*iWidth,0.8*iHeight,0.8*iWidth,0.2*iHeight);
    this->ChangeFlyStatusRect(0,0.8*iHeight,0.15*iWidth,0.2*iHeight);
    this->ChangeCommandRect(0.15*iWidth,0.8*iHeight,0.65*iWidth,0.2*iHeight);
    this->ChangeUAVLogoRect(0.8*iWidth,0.8*iHeight,0.2*iWidth,0.2*iHeight);
    mMenuWidget->setGeometry(0.3*iWidth,0.3*iHeight,0.4*iWidth,0.4*iHeight);
    if(ui->FPVaction->isChecked())//显示FPV
    {
        //mWebWidget->setGeometry(0.15*iWidth,0.08*iHeight,0.55*iWidth,0.7*iHeight);
        mWebWidget->setGeometry(0,0.08*iHeight,0.55*iWidth,0.7*iHeight);
        mGoogleMapWeb->ChangeRect(0,0,0.5*iWidth,0.7*iHeight);
        this->ChangeMagRect(0.45*iWidth,0.04*iHeight,0.06*iWidth,0.1*iHeight);
        mVLCWidget->show();

        mVLCWidget->setGeometry(0.7*iWidth,0.08*iHeight,0.3*iWidth,0.7*iHeight);
        mVLCPlayer->openFile(QString("rtmp://live.hkstv.hk.lxdns.com/live/hks"));
        //mVLCPlayer->openFile(QString("D:/\GOPR0859_A01.MP4"));
//        mVLCPlayer->FullWidget(0.5*iWidth,0.7*iHeight);
    }
    else//隐藏FPV
    {
        //mWebWidget->setGeometry(0.15*iWidth,0.08*iHeight,0.85*iWidth,0.7*iHeight);
        mWebWidget->setGeometry(0,0.08*iHeight,0.85*iWidth,0.7*iHeight);
        this->ChangeMagRect(0.77*iWidth,0.04*iHeight,0.08*iWidth,0.05*iHeight);
        mGoogleMapWeb->ChangeRect(0,0,0.85*iWidth,0.7*iHeight);
        mVLCWidget->hide();
        mVLCPlayer->stop();
    }
}

void GCSDisplay::SetButton()
{
//    QPushButton * p1= new QPushButton(mCommondWidget);
    mCommandWidget->setStyleSheet("QPushButton#evilButton { background-color: red; \
                                  border-style: outset;   \
                                  border-width: 2px;   \
                                  border-radius: 10px;   \
                                  border-color: beige;   \
                                  font: bold 14px;    \
                                  min-width: 10em;   \
                                  padding: 6px;   \
                              }");
}

void GCSDisplay::resizeEvent(QResizeEvent *event)
{
    qDebug()<<"ParentWidget:"<<this->width()<<" "<<this->height();
    this->ChangeSize(this->width(),this->height());
}

QRect GCSDisplay::SendRect()
{
    return this->rect();
}

void GCSDisplay::SetToolBar()
{
    ChangeMouseAction = new QAction(QString::fromLocal8Bit("鼠标"), this);
    ChangeMouseAction->setShortcut(QKeySequence::Open);
    ChangeMouseAction->setStatusTip(QString::fromLocal8Bit("改变鼠标为点击"));
    ChangeMouseAction->setIcon(QIcon("://new/toolbar/png/mousepass.png")); // Add code.
    //ui->menu->addMenu(tr("&File"));
    //ui->menu->addAction(ChangeMouseAction);
    ui->toolBar->addAction(ChangeMouseAction);


    ZoomAddAction = new QAction(QString::fromLocal8Bit("放大"),this);      //ToolBar 放大
    ZoomAddAction->setStatusTip(QString::fromLocal8Bit("放大地图"));
    ZoomAddAction->setIcon(QIcon("://new/toolbar/png/ZoomAdd.png"));
    ui->toolBar->addAction(ZoomAddAction);

    ZoomSubAction = new QAction(QString::fromLocal8Bit("缩小"),this);      //ToolBar 缩小
    ZoomSubAction->setStatusTip(QString::fromLocal8Bit("缩小地图"));
    ZoomSubAction->setIcon(QIcon("://new/toolbar/png/ZoomSub.png"));
    ui->toolBar->addAction(ZoomSubAction);

    ScalePlateAction = new QAction(QString::fromLocal8Bit("标尺"),this);      //ToolBar 标尺
    ScalePlateAction->setStatusTip(QString::fromLocal8Bit("测量两点之间的距离"));
    ScalePlateAction->setIcon(QIcon("://new/toolbar/png/ScalePlate.png"));
    ui->toolBar->addAction(ScalePlateAction);

    ChangeMoveAction = new QAction(QString::fromLocal8Bit("移动"),this);      //ToolBar 移动
    ChangeMoveAction->setStatusTip(QString::fromLocal8Bit("把鼠标变为可拖动"));
    ChangeMoveAction->setIcon(QIcon("://new/toolbar/png/ChangeMove.png"));
    ui->toolBar->addAction(ChangeMoveAction);

    CoursePlotAction = new QAction(QString::fromLocal8Bit("画航线"),this);      //ToolBar 画航线
    CoursePlotAction->setStatusTip(QString::fromLocal8Bit("画航线"));
    CoursePlotAction->setIcon(QIcon("://new/toolbar/png/CoursePlot.png"));
    ui->toolBar->addAction(CoursePlotAction);


    ShowGridAction = new QAction(QString::fromLocal8Bit("显示网格"),this);      //ToolBar 显示网格
    ShowGridAction->setStatusTip(QString::fromLocal8Bit("显示网格"));
    ShowGridAction->setIcon(QIcon("://new/toolbar/png/ShowGrid.png"));
    ui->toolBar->addAction(ShowGridAction);

    FindUAVAction = new QAction(QString::fromLocal8Bit("定位无人机"),this);      //ToolBar 定位无人机当前位置
    FindUAVAction->setStatusTip(QString::fromLocal8Bit("定位到无人机当前位置"));
    FindUAVAction->setIcon(QIcon("://new/toolbar/png/FindUAV.png"));
    ui->toolBar->addAction(FindUAVAction);

    ClearRouteAction = new QAction(QString::fromLocal8Bit("清除航线"),this);      //ToolBar 清除航线
    ClearRouteAction->setStatusTip(QString::fromLocal8Bit("清除当前航线"));
    ClearRouteAction->setIcon(QIcon("://new/toolbar/png/ClearRoute.png"));
    ui->toolBar->addAction(ClearRouteAction);

    RouteDisplayAction = new QAction(QString::fromLocal8Bit("显示航线"),this);      //ToolBar 显示航线
    RouteDisplayAction->setStatusTip(QString::fromLocal8Bit("显示无人机轨迹"));
    RouteDisplayAction->setIcon(QIcon("://new/toolbar/png/RouteDisplay.png"));
    ui->toolBar->addAction(RouteDisplayAction);

    RecordDataAction = new QAction(QString::fromLocal8Bit("记录数据"),this);      //ToolBar 记录数据
    RecordDataAction->setStatusTip(QString::fromLocal8Bit("点击开始记录数据"));
    RecordDataAction->setIcon(QIcon("://new/toolbar/png/RecordData.png"));
    ui->toolBar->addAction(RecordDataAction);

    SettingAction = new QAction(QString::fromLocal8Bit("设置"),this);      //ToolBar 设置
    SettingAction->setStatusTip(QString::fromLocal8Bit("点击进入设置界面"));
    SettingAction->setIcon(QIcon("://new/toolbar/png/Setting.png"));
    ui->toolBar->addAction(SettingAction);
    QSize size(30,30);
    ui->toolBar->setIconSize(size);
}

void GCSDisplay::SetMenuWidget()
{
    mMenuWidget->SetMenuWidget();
}



void GCSDisplay::SetStatusDisplay()
{
    QQuickView *view = new QQuickView();
    mStatusDisplayQMLcontainer = QWidget::createWindowContainer(view,mGCSStatusWidget);
    view->setSource(QUrl(QStringLiteral("qrc:/gcsstatusdisplay.qml")));
    QQmlContext* context=view->rootContext();
     context->setContextProperty("mQMLCom",mQMLCom);
     mStatusDisplayQMLcontainer->setParent(mGCSStatusWidget);
     //mStatusDisplayQMLcontainer->setGeometry(0,0,600,600);
}


void GCSDisplay::SetCommandDisplay()
{
    QQuickView *view = new QQuickView();
    mCommandDisplayQMLcontainer = QWidget::createWindowContainer(view,mGCSCommandWidget);

    view->setSource(QUrl(QStringLiteral("qrc:/gcscommanddisplay.qml")));
    QQmlContext* context=view->rootContext();
     context->setContextProperty("mQMLCom",mQMLCom);
     mCommandDisplayQMLcontainer->setParent(mGCSCommandWidget);
}



void GCSDisplay::SetUAVLogoDisplay()
{
#if 0
    QQuickView *view = new QQuickView();
    mUAVLogoDisplayQMLcontainer = QWidget::createWindowContainer(view,mGCSUAVLogoWidget);

    view->setSource(QUrl(QStringLiteral("qrc:/gcsuavlogodisplay.qml")));
    QQmlContext* context=view->rootContext();
     context->setContextProperty("mQMLCom",mQMLCom);
     mUAVLogoDisplayQMLcontainer->setParent(mGCSUAVLogoWidget);
#else
    mAHRSWidget = new GLWidget(mGCSUAVLogoWidget);
    QColor clearColor;
    clearColor.setHsv( 0xAD , 0xD8, 0xE6);
    mAHRSWidget->setClearColor(clearColor);
    mAHRSWidget->rotateBy(0,0,0);
#endif
}



void GCSDisplay::SetFlyDataWidget()
{
#if 0
    QQuickWidget *mFlyDataQMLcontainer = new QQuickWidget();
    mFlyDataQMLcontainer = QWidget::createWindowContainer(view,mFlyDataWidget);
//    container->setGeometry(0,17,300,580);
    view->setSource(QUrl(QStringLiteral("qrc:/flydata.qml")));
    QQmlContext* context=view->rootContext();
     context->setContextProperty("mQMLCom",mQMLCom);
     mFlyDataQMLcontainer->setParent(mFlyDataWidget);
#endif
     mFlyDataQMLcontainer = new QQuickWidget(mFlyDataWidget);

     mFlyDataQMLcontainer->setSource(QUrl(QStringLiteral("qrc:/flydata.qml")));
     QQmlContext* context=mFlyDataQMLcontainer->rootContext();
      context->setContextProperty("mQMLCom",mQMLCom);
     mFlyDataQMLcontainer->setAttribute(Qt::WA_AlwaysStackOnTop, true); //这两句是使QML背景透明
     mFlyDataQMLcontainer->setClearColor(QColor(Qt::transparent));

//     mMapDisplayView->setAttribute(Qt::WA_AlwaysStackOnTop, true); //这两句是使QML背景透明
//     mMapDisplayView->setClearColor(QColor(Qt::transparent));
}

void GCSDisplay::SetMagDisplay()
{
    mMapDisplayView = new QQuickWidget(mGCSMagWidget);

    mMapDisplayView->setSource(QUrl(QStringLiteral("qrc:/MagneticCompass.qml")));
    QQmlContext* context=mMapDisplayView->rootContext();
     context->setContextProperty("mQMLCom",mQMLCom);
    mMapDisplayView->setAttribute(Qt::WA_AlwaysStackOnTop, true); //这两句是使QML背景透明
    mMapDisplayView->setClearColor(QColor(Qt::transparent));

     //view->setColor(QColor(Qt::transparent));
#if 0
     mGCSMagWidget->setAutoFillBackground( true );
     QPalette plt = this->mGCSMagWidget->palette();
     plt.setColor( QPalette::Window, Qt::red );
     mGCSMagWidget->setPalette( plt );

#else
     mGCSMagWidget->setAutoFillBackground( true );
     mGCSMagWidget->setAttribute(Qt::WA_TranslucentBackground);//背景透明
     mGCSMagWidget->setStyleSheet("background-color: rgb(222, 222, 222,100);");
     QPalette pal = this->mGCSMagWidget->palette();
     pal.setColor(QPalette::Background, QColor(0x00,0x00,0x00,0x00));
     mGCSMagWidget->setPalette(pal);

#endif
}

void GCSDisplay::ChangeFlyDataRect(int x,int y,int iWidth,int iHeight)
{
    mFlyDataWidget->setGeometry(x,y,iWidth,iHeight);

    mFlyDataQMLcontainer->resize(iWidth,iHeight);
    mQMLCom->ChangeSize(iWidth,iHeight);

}

void GCSDisplay::ChangeMenuWidgetRect(int iWidth,int iHeight)
{

}

void GCSDisplay::ChangeFlyStatusRect(int x,int y,int iWidth,int iHeight)
{
    mGCSStatusWidget->setGeometry(x,y,iWidth,iHeight);
    mQMLCom->ChangeStatusDisplaySize(iWidth,iHeight);
    mStatusDisplayQMLcontainer->resize(iWidth,iHeight);
}

void GCSDisplay::ChangeCommandRect(int x,int y,int iWidth,int iHeight)
{
    mGCSCommandWidget->setGeometry(x,y,iWidth,iHeight);
    mQMLCom->ChangeCommandDisplaySize(iWidth,iHeight);
    mCommandDisplayQMLcontainer->resize(iWidth,iHeight);
}

void GCSDisplay::ChangeUAVLogoRect(int x,int y,int iWidth,int iHeight)
{
    mGCSUAVLogoWidget->setGeometry(x,y,iWidth,iHeight);
    mQMLCom->ChangeUAVLogoDisplaySize(iWidth,iHeight);
    mAHRSWidget->setGeometry(0,0,iWidth,iHeight);
//    mUAVLogoDisplayQMLcontainer->resize(iWidth,iHeight);
}

void GCSDisplay::ChangeMagRect(int x,int y,int iWidth,int iHeight)
{
    mQMLCom->ChangeMagDisplaySize(iWidth,iWidth);
    mGCSMagWidget->setGeometry(x,y,iWidth,iWidth);
    mMapDisplayView->setGeometry(0,0,iWidth,iWidth);

}

void GCSDisplay::testChanged(void)
{
    QMessageBox::information(NULL,"test", "111111111", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
}

GCSDisplay::~GCSDisplay()
{
    delete ui;
}
#endif
