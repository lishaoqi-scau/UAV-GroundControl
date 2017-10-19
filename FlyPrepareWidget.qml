import QtQuick 2.1

import an.qt.QMLCommunicate 1.0

Rectangle {
    property real  _itemsize: mQMLCom ? mQMLCom.ReadItemSize : 300
    property var  widgetparam:  mQMLCom ? mQMLCom.ReadWidgetParam : 0
    property int iwidgetwidth:   mQMLCom ? mQMLCom.ReadWidgetParam[10]:320
    property int iwidgetheight:   mQMLCom ? mQMLCom.ReadWidgetParam[11]:600
    property real  widthsize: 0.4
    property real  highsize: 0.15
    property int  widthspace: (1-2*widthsize)/3*iwidgetwidth
    property int  highspace: (1-3*highsize)/5*iwidgetheight
    property bool bComStatus: true
    x:0
    y:0
    width: iwidgetwidth
    height: iwidgetheight
    radius: 16;//圆角
    clip:true//这一属性设置表示如果他的子类超出了范围，那么就剪切掉，不让他显示和起作用
    color:"#00ff0000"   //设置背景透明

    Rectangle{
        id:_background
        x:0
        y:0
        width: parent.width
        height: parent.height
        opacity:0.8
        radius: 16
        color: "lightblue"//内部的颜色

        gradient: Gradient {
            GradientStop { position: 0 ;color:  "#FF87CEEB"  }
            GradientStop { position: 1 ;color:  "#FF305555"  }
        }
    }

    QGCListView{
        id:_listview
        x:0
        y:0
        width: iwidgetwidth
        height: iwidgetheight
    }

    Connections {
            target: mQMLCom;
            onSigWidgetSizeChange:{
                iwidgetwidth = mQMLCom.ReadWidgetParam[10];
                iwidgetheight = mQMLCom.ReadWidgetParam[11];
//                console.info("XXXXXXonSigMTIChange------------------>"+iwidgetwidth+"   "+iwidgetheight);
            }
        }
}
