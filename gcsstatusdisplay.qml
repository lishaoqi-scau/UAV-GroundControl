import QtQuick 2.1

import an.qt.QMLCommunicate 1.0
import QtQuick              2.3
import QtGraphicalEffects   1.0
import an.qt.QMLCommunicate 1.0

Rectangle {

    property real  _itemsize: mQMLCom ? mQMLCom.ReadItemSize : 300
    property var  widgetparam:  mQMLCom ? mQMLCom.ReadWidgetParam : 0
    property int statusiwidgetwidth:   mQMLCom ? mQMLCom.ReadWidgetParam[2]:320
    property int statusiwidgetheight:   mQMLCom ? mQMLCom.ReadWidgetParam[3]:600
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
            Rectangle{
                id:link
                x:statusiwidgetwidth*iwidthspace;
                y:statusiwidgetheight*iheightspace;
                radius: 10;//圆角
                width: statusiwidgetwidth*0.3;
                height: statusiwidgetheight*0.3;
                gradient: Gradient{//颜色渐变
                    GradientStop { position: 0.0; color: "#8F200000" }
                    GradientStop { position: 1.0; color: "#8FFF0000" }
                }
                QGCLabel {
                    x:5
                    y:5
//                    anchors.bottomMargin:       Math.round(12 * .75)
//                    anchors.bottom:             parent.bottom
                    anchors.verticalCenter :  parent.verticalCenter
                    anchors.horizontalCenter:   parent.horizontalCenter
                    text:                       _headingString
                    color:                      "yellow"
                    visible:                    showHeading

                    property string _headingString:"链路"
                }
            }

            Rectangle{
                id:uav
                x:statusiwidgetwidth*(0.3+2*iwidthspace);
                y:statusiwidgetheight*iheightspace;
                radius: 10;//圆角
                width: statusiwidgetwidth*0.3;
                height: statusiwidgetheight*0.3;
                color: "red";
                gradient: Gradient{//颜色渐变
                    GradientStop { position: 0.0; color: "#8F002000" }
                    GradientStop { position: 1.0; color: "#FF00F000" }
                }
                QGCLabel {
                    x:5
                    y:5
//                    anchors.bottomMargin:       Math.round(12 * .75)
//                    anchors.bottom:             parent.bottom
                    anchors.verticalCenter :  parent.verticalCenter
                    anchors.horizontalCenter:   parent.horizontalCenter
                    text:                       _headingString
                    color:                      "yellow"
                    visible:                    showHeading

                    property string _headingString:"飞控"
                }
            }

            Rectangle{
                id:fpv
                x:statusiwidgetwidth*iwidthspace;
                y:statusiwidgetheight*(0.3+2*iheightspace);
                radius: 10;//圆角
                width: statusiwidgetwidth*0.3;
                height: statusiwidgetheight*0.3;
                color: "red";
                gradient: Gradient{//颜色渐变
                    GradientStop { position: 0.0; color: "#8F002000" }
                    GradientStop { position: 1.0; color: "#FF00F000" }
                }
                QGCLabel {
                    x:5
                    y:5
//                    anchors.bottomMargin:       Math.round(12 * .75)
//                    anchors.bottom:             parent.bottom
                    anchors.verticalCenter :  parent.verticalCenter
                    anchors.horizontalCenter:   parent.horizontalCenter
                    text:                       _headingString
                    color:                      "yellow"
                    visible:                    showHeading

                    property string _headingString:"FPV"
                }
            }

            Rectangle{
                id:check
                x:statusiwidgetwidth*(0.3+2*iwidthspace);
                y:statusiwidgetheight*(0.3+2*iheightspace);
                radius: 10;//圆角
                width: statusiwidgetwidth*0.3;
                height: statusiwidgetheight*0.3;
                color: "red";
                gradient: Gradient{//颜色渐变
                    GradientStop { position: 0.0; color: "#8F200000" }
                    GradientStop { position: 1.0; color: "#8FF00000" }
                }
                QGCLabel {
                    x:5
                    y:5
//                    anchors.bottomMargin:       Math.round(12 * .75)
//                    anchors.bottom:             parent.bottom
                    anchors.verticalCenter :  parent.verticalCenter
                    anchors.horizontalCenter:   parent.horizontalCenter
                    text:                       _headingString
                    color:                      "yellow"
                    visible:                    showHeading

                    property string _headingString:"检查"
                }
            }

            Image {
                id:                 pointer
                anchors.bottom:     parent.bottom
                anchors.right:     parent.right
                source:             "/qmlimages/unlock.png"
                mipmap:             true
            }

   Connections {
                   target: mQMLCom;
                   onSigWidgetSizeChange:{
                       statusiwidgetwidth = mQMLCom.ReadWidgetParam[2];
                       statusiwidgetheight = mQMLCom.ReadWidgetParam[3];
//                       console.info("1111111onSigMTIChange------------------>"+statusiwidgetwidth+"   "+statusiwidgetheight);
                   }
               }

}
