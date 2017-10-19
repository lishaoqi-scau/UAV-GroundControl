import QtQuick 2.1

import an.qt.QMLCommunicate 1.0

Rectangle {

    property real  _itemsize: mQMLCom ? mQMLCom.ReadItemSize : 300
    property var  widgetparam:  mQMLCom ? mQMLCom.ReadWidgetParam : 0
    property int iwidgetwidth:   mQMLCom ? mQMLCom.ReadWidgetParam[8]:320
    property int iwidgetheight:   mQMLCom ? mQMLCom.ReadWidgetParam[9]:600
    x:0
    y:0
    width: iwidgetwidth
    height: iwidgetheight
 //   radius: 10;//圆角
//    clip:true//这一属性设置表示如果他的子类超出了范围，那么就剪切掉，不让他显示和起作用
    visible: true
    color:"#00ff0000"

//    color:"red"


    QGCCompassWidget {
        id: attitudeWidget2
        opacity:0.8
//      anchors.fill: parent
        x:0
        y:03

        size: _itemsize
        width:iwidgetwidth
        height: iwidgetwidth
    }


    Connections {
            target: mQMLCom;
            onSigWidgetSizeChange:{
                iwidgetwidth = mQMLCom.ReadWidgetParam[8];
                iwidgetheight = mQMLCom.ReadWidgetParam[9];
//                console.info("XXXXXXonSigMTIChange------------------>"+iwidgetwidth+"   "+iwidgetheight);
            }
        }
}
