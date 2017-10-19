import QtQuick 2.1

import an.qt.QMLCommunicate 1.0
import QtQuick              2.3
import QtGraphicalEffects   1.0
import an.qt.QMLCommunicate 1.0

Rectangle {

    property real  _itemsize: mQMLCom ? mQMLCom.ReadItemSize : 300
    property var  widgetparam:  mQMLCom ? mQMLCom.ReadWidgetParam : 0
    property int statusiwidgetwidth:   mQMLCom ? mQMLCom.ReadWidgetParam[6]:320
    property int statusiwidgetheight:   mQMLCom ? mQMLCom.ReadWidgetParam[7]:600
    property real iwidthspace: 0.1
    property real iheightspace: 0.1
            x:0//这里的坐标是相对于它的父窗口，也就是Window
            y:0
            width: statusiwidgetwidth;
            height: statusiwidgetheight;//一定要指定出大小才能显示
            visible: true
            antialiasing: true;//抗锯齿，默认就是开启的
//            border.width: 2;
//            border.color: "yellow";//边框的一些属性
            color: "lightblue"//内部的颜色

            radius: 10;//圆角
            clip:true//这一属性设置表示如果他的子类超出了范围，那么就剪切掉，不让他显示和起作用
            Image {
                id:                 crossHair
      //          anchors.centerIn:   parent
                anchors.fill:       parent
                source:             "/qmlimages/uavlogo.png"
                mipmap:             true
                width:              size * 0.75
                sourceSize.width:   width
                fillMode:           Image.PreserveAspectFit
            }

   Connections {
                   target: mQMLCom;
                   onSigWidgetSizeChange:{
                       statusiwidgetwidth = mQMLCom.ReadWidgetParam[6];
                       statusiwidgetheight = mQMLCom.ReadWidgetParam[7];
//                       console.info("1111111onSigMTIChange------------------>"+statusiwidgetwidth+"   "+statusiwidgetheight);
                   }
               }

}
