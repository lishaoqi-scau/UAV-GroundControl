import QtQuick 2.1

import an.qt.QMLCommunicate 1.0

Rectangle {
    property alias mouseArea: mouseArea
    property alias textEdit: textEdit
    property real  _itemsize: mQMLCom ? mQMLCom.ReadItemSize : 300
    property var  widgetparam:  mQMLCom ? mQMLCom.ReadWidgetParam : 0
    property int iwidgetwidth:   mQMLCom ? mQMLCom.ReadWidgetParam[0]:320
    property int iwidgetheight:   mQMLCom ? mQMLCom.ReadWidgetParam[1]:600
    x:iwidgetwidth/600
    y:iwidgetheight/600
    width: iwidgetwidth
    height: iwidgetheight
    radius: 10;//圆角
    clip:true//这一属性设置表示如果他的子类超出了范围，那么就剪切掉，不让他显示和起作用
    color:"#00000000"
    MouseArea {
        id: mouseArea

    }
    TextEdit {
        id: textEdit

    }
    Rectangle{
        x:0
        y:0
        width: parent.width
        height: parent.height
        opacity:0.6
        radius: 10
        color: "#FFA0A0A0"//内部的颜色
    }
    /*
    Image {
        id:                 skybackground
//          anchors.centerIn:   parent
        opacity:0.8
        anchors.fill:       parent
        source:             "/qmlimages/sky.png"
        width: iwidgetwidth
        height: iwidgetheight

    }
*/
    QGCAttitudeWidget {
        id: attitudeWidget
        opacity:1
 //     anchors.fill: parent
        x:iwidgetwidth/4
        y:iwidgetheight/20
        size: _itemsize
        width: iwidgetwidth*1/2
        height: iwidgetwidth*1/2
    }
    QGCScaleplate{
        id:skyspeed
        opacity: 0.9
        x:0
        y:40
        width:iwidgetwidth
        height: iwidgetheight*1/3
    }


    QGCFlyDataShowWidget {
        id:flydatawidget
        x:0
        y:iwidgetheight*3/20+  iwidgetwidth*2/3
    }
    Connections {
            target: mQMLCom;
            onSigWidgetSizeChange:{
                iwidgetwidth = mQMLCom.ReadWidgetParam[0];
                iwidgetheight = mQMLCom.ReadWidgetParam[1];
//                console.info("XXXXXXonSigMTIChange------------------>"+iwidgetwidth+"   "+iwidgetheight);
            }
        }
}
