#ifndef GCSDISPLAY_H
#define GCSDISPLAY_H

#include <QMainWindow>
#include <QtDataVisualization/QtDataVisualizationVersion>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QtQuickWidgets/QQuickWidget>
#include "vlcplayer.h"
#include "googlemapweb.h"
#include "qmlcommunicate.h"
#include "menuwidgetmanager.h"
#include "serialsettingwidget.h"
#include "readini.h"
#include "glwidget.h"

namespace Ui {
class GCSDisplay;
}

class GCSDisplay : public QMainWindow
{
    Q_OBJECT

public:
    explicit GCSDisplay(QWidget *parent = 0);
    ~GCSDisplay();
protected:
    void resizeEvent(QResizeEvent *event);
private:
    void SetQMLCommunicate(void);
    void SetToolBar(void);
    void SetDockWidget(void);
    void SetFlyDataWidget(void);
    void ChangeSize(int iWidget,int iHeight);
    void ChangeFlyDataRect(int x,int y,int iWidget,int iHeight);
    void ChangeFlyStatusRect(int x,int y,int iWidth,int iHeight);
    void ChangeCommandRect(int x,int y,int iWidth,int iHeight);
    void ChangeUAVLogoRect(int x,int y,int iWidth,int iHeight);
    void ChangeMagRect(int x,int y,int iWidth,int iHeight);
    void SetButton();
    void SetStatusDisplay();
    void SetCommandDisplay();
    void SetUAVLogoDisplay();
    void SetMagDisplay();

    void SetMenuWidget();
    void ChangeMenuWidgetRect(int iWidth,int iHeight);
public slots:
    QRect SendRect();

private slots:
    void onRestoreCatalogueView();
    void testChanged();
    void DisplayChanged();
    void RecordRect();
private:
    Ui::GCSDisplay *ui;
    VLCPlayer * mVLCPlayer;
    Googlemapweb * mGoogleMapWeb;
    QWebEngineView * mWebView;
    QMLCommunicate * mQMLCom;
    MenuWidgetManager * mMenuWidget;
    ReadIni * mReadini;

    //QWidget * mMenuWidget;


    QWidget * mWebWidget;
    QWidget * mVLCWidget;
    QWidget * mFlyDataWidget;
    QQuickWidget *mFlyDataQMLcontainer;
    QWidget * mCommandWidget;
//    QWidget * mFlyDataQMLcontainer;
    QWidget * mStatusDisplayQMLcontainer;
    QWidget * mGCSStatusWidget;

    QWidget * mCommandDisplayQMLcontainer;
    QWidget * mGCSCommandWidget;

    QWidget * mUAVLogoDisplayQMLcontainer;
    QWidget * mGCSUAVLogoWidget;
    GLWidget * mAHRSWidget;

    QWidget * mGCSMagWidget;
    QQuickWidget *mMapDisplayView;

    QAction * ChangeMouseAction;  //ToolBar 鼠标
    QAction * ZoomAddAction;      //ToolBar 放大
    QAction * ZoomSubAction;      //ToolBar 缩小
    QAction * ScalePlateAction;   //ToolBar 标尺
    QAction * ChangeMoveAction;   //ToolBar 移动
    QAction * CoursePlotAction;   //ToolBar 画航线
    QAction * ShowGridAction;     //ToolBar 显示网格
    QAction * FindUAVAction;       //ToolBar 定位无人机当前位置
    QAction * ClearRouteAction;    //ToolBar 清除航线
    QAction * RouteDisplayAction;  //ToolBar 显示航线
    QAction * RecordDataAction;    //ToolBar 记录数据
    QAction * SettingAction;       //ToolBar 设置

    QRect mrectWidget;
};

#endif // GCSDISPLAY_H
