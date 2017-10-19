import QtQuick 2.1
import QtQuick 2.2
import QtQuick.Window 2.1
import QtQuick.Controls 1.2
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.2

import an.qt.QMLCommunicate 1.0

Rectangle {

    property real  _itemsize: mQMLCom ? mQMLCom.ReadItemSize : 300
    property var  widgetparam:  mQMLCom ? mQMLCom.ReadWidgetParam : 0
    property int commandiwidgetwidth:   mQMLCom ? mQMLCom.ReadWidgetParam[4]:320
    property int commandiwidgetheight:   mQMLCom ? mQMLCom.ReadWidgetParam[5]:600
    property real iwidthspace: 0.05
    property real iheightspace: 0.12
    property real ibuttonwidth: 0.1
    property real ibuttonheight: 0.3
            x:0//这里的坐标是相对于它的父窗口，也就是Window
            y:0
            width: commandiwidgetwidth;
            height: commandiwidgetheight;//一定要指定出大小才能显示
            visible: true
            antialiasing: true;//抗锯齿，默认就是开启的
//            border.width: 2;
//            border.color: "yellow";//边框的一些属性
            color: "lightblue"//内部的颜色
//            opacity:0.8
            radius: 10;//圆角
            clip:true//这一属性设置表示如果他的子类超出了范围，那么就剪切掉，不让他显示和起作用

     Button {
                x:commandiwidgetwidth*iwidthspace
                y:commandiwidgetheight*iheightspace
                text: "比例遥控"
                onClicked: retryClicked();
                style: ButtonStyle {
                    background: Rectangle {
                        implicitWidth: commandiwidgetwidth*ibuttonwidth
                        implicitHeight: commandiwidgetheight*ibuttonheight
                        border.width: control.activeFocus ?2 : 1
                        border.color: "#800"
                        radius: 8
                        gradient: Gradient {
                            GradientStop { position: 0 ;color: control.pressed ? "#a00" : "#FF00F000" }
                            GradientStop { position: 1 ;color: control.pressed ? "#500" : "#8F002000" }
                        }
                    }
                }
            }

     Button {
                x:commandiwidgetwidth*(ibuttonwidth+iwidthspace*2)
                y:commandiwidgetheight* iheightspace
                text: "横飞"
                onClicked: retryClicked();
                style: ButtonStyle {
                    background: Rectangle {
                        implicitWidth: commandiwidgetwidth*ibuttonwidth
                        implicitHeight: commandiwidgetheight*ibuttonheight
                        border.width: control.activeFocus ?2 : 1
                        border.color: "#800"
                        radius: 8
                        gradient: Gradient {
                            GradientStop { position: 0 ;color: control.pressed ? "#a00" : "#FF00F000" }
                            GradientStop { position: 1 ;color: control.pressed ? "#500" : "#8F002000" }
                        }
                    }
                }
            }

     Button {
                x:commandiwidgetwidth*(iwidthspace)
                y:commandiwidgetheight* (ibuttonheight+2*iheightspace)
                text: "手控"
                onClicked: retryClicked();
                style: ButtonStyle {
                    background: Rectangle {
                        implicitWidth: commandiwidgetwidth*ibuttonwidth
                        implicitHeight: commandiwidgetheight*ibuttonheight
                        border.width: control.activeFocus ?2 : 1
                        border.color: "#800"
                        radius: 8
                        gradient: Gradient {
                            GradientStop { position: 0 ;color: control.pressed ? "#a00" : "#FF00F000" }
                            GradientStop { position: 1 ;color: control.pressed ? "#500" : "#8F002000" }
                        }
                    }
                }
            }


     Button {
                x:commandiwidgetwidth*(ibuttonwidth+iwidthspace*2)
                y:commandiwidgetheight*(ibuttonheight+iheightspace*2)
                text: "平飞"
                onClicked: retryClicked();
                style: ButtonStyle {
                    background: Rectangle {
                        implicitWidth: commandiwidgetwidth*ibuttonwidth
                        implicitHeight: commandiwidgetheight*ibuttonheight
                        border.width: control.activeFocus ?2 : 1
                        border.color: "#800"
                        radius: 8
                        gradient: Gradient {
                            GradientStop { position: 0 ;color: control.pressed ? "#a00" : "#FF00F000" }
                            GradientStop { position: 1 ;color: control.pressed ? "#500" : "#8F002000" }
                        }
                    }
                }
            }

     Button {
                x:commandiwidgetwidth*(2*ibuttonwidth+3*iwidthspace)
                y:commandiwidgetheight* (iheightspace)
                text: "归航"
                onClicked: retryClicked();
                style: ButtonStyle {
                    background: Rectangle {
                        implicitWidth: commandiwidgetwidth*ibuttonwidth
                        implicitHeight: commandiwidgetheight*ibuttonheight
                        border.width: control.activeFocus ?2 : 1
                        border.color: "#800"
                        radius: 8
                        gradient: Gradient {
                            GradientStop { position: 0 ;color: control.pressed ? "#a00" : "#FF00F000" }
                            GradientStop { position: 1 ;color: control.pressed ? "#500" : "#8F002000" }
                        }
                    }
                }
            }

     Button {
                x:commandiwidgetwidth*(2*ibuttonwidth+3*iwidthspace)
                y:commandiwidgetheight* (ibuttonheight+2*iheightspace)
                text: "盘旋"
                onClicked: retryClicked();
                style: ButtonStyle {
                    background: Rectangle {
                        implicitWidth: commandiwidgetwidth*ibuttonwidth
                        implicitHeight: commandiwidgetheight*ibuttonheight
                        border.width: control.activeFocus ?2 : 1
                        border.color: "#800"
                        radius: 8
                        gradient: Gradient {
                            GradientStop { position: 0 ;color: control.pressed ? "#a00" : "#FF00F000" }
                            GradientStop { position: 1 ;color: control.pressed ? "#500" : "#8F002000" }
                        }
                    }
                }
            }
     Button {
                x:commandiwidgetwidth*(3*ibuttonwidth+4*iwidthspace)
                y:commandiwidgetheight* (iheightspace)
                text: "起飞"
                onClicked: retryClicked();
                style: ButtonStyle {
                    background: Rectangle {
                        implicitWidth: commandiwidgetwidth*ibuttonwidth
                        implicitHeight: commandiwidgetheight*ibuttonheight
                        border.width: control.activeFocus ?2 : 1
                        border.color: "#800"
                        radius: 8
                        gradient: Gradient {
                            GradientStop { position: 0 ;color: control.pressed ? "#a00" : "#FF00F000" }
                            GradientStop { position: 1 ;color: control.pressed ? "#500" : "#8F002000" }
                        }
                    }
                }
            }

     Button {
                x:commandiwidgetwidth*(3*ibuttonwidth+4*iwidthspace)
                y:commandiwidgetheight* (ibuttonheight+2*iheightspace)
                text: "爬升10米"
                onClicked: retryClicked();
                style: ButtonStyle {
                    background: Rectangle {
                        implicitWidth: commandiwidgetwidth*ibuttonwidth
                        implicitHeight: commandiwidgetheight*ibuttonheight
                        border.width: control.activeFocus ?2 : 1
                        border.color: "#800"
                        radius: 8
                        gradient: Gradient {
                            GradientStop { position: 0 ;color: control.pressed ? "#a00" : "#FF00F000" }
                            GradientStop { position: 1 ;color: control.pressed ? "#500" : "#8F002000" }
                        }
                    }
                }
            }
     Button {
                x:commandiwidgetwidth*(4*ibuttonwidth+5*iwidthspace)
                y:commandiwidgetheight* (iheightspace)
                text: "降落"
                onClicked: retryClicked();
                style: ButtonStyle {
                    background: Rectangle {
                        implicitWidth: commandiwidgetwidth*ibuttonwidth
                        implicitHeight: commandiwidgetheight*ibuttonheight
                        border.width: control.activeFocus ?2 : 1
                        border.color: "#800"
                        radius: 8
                        gradient: Gradient {
                            GradientStop { position: 0 ;color: control.pressed ? "#a00" : "#FF00F000" }
                            GradientStop { position: 1 ;color: control.pressed ? "#500" : "#8F002000" }
                        }
                    }
                }
            }

     Button {
                x:commandiwidgetwidth*(4*ibuttonwidth+5*iwidthspace)
                y:commandiwidgetheight* (ibuttonheight+2*iheightspace)
                text: "下降10米"
                onClicked: retryClicked();
                style: ButtonStyle {
                    background: Rectangle {
                        implicitWidth: commandiwidgetwidth*ibuttonwidth
                        implicitHeight: commandiwidgetheight*ibuttonheight
                        border.width: control.activeFocus ?2 : 1
                        border.color: "#800"
                        radius: 8
                        gradient: Gradient {
                            GradientStop { position: 0 ;color: control.pressed ? "#a00" : "#FF00F000" }
                            GradientStop { position: 1 ;color: control.pressed ? "#500" : "#8F002000" }
                        }
                    }
                }
            }

     Button {
                x:commandiwidgetwidth*(5*ibuttonwidth+6*iwidthspace)
                y:commandiwidgetheight* (iheightspace)
                text: "定高"
                onClicked: retryClicked();
                style: ButtonStyle {
                    background: Rectangle {
                        implicitWidth: commandiwidgetwidth*ibuttonwidth
                        implicitHeight: commandiwidgetheight*ibuttonheight
                        border.width: control.activeFocus ?2 : 1
                        border.color: "#800"
                        radius: 8
                        gradient: Gradient {
                            GradientStop { position: 0 ;color: control.pressed ? "#a00" : "#FF00F000" }
                            GradientStop { position: 1 ;color: control.pressed ? "#500" : "#8F002000" }
                        }
                    }
                }
            }

     Button {
                x:commandiwidgetwidth*(5*ibuttonwidth+6*iwidthspace)
                y:commandiwidgetheight* (ibuttonheight+2*iheightspace)
                text: "巡航"
                onClicked: retryClicked();
                style: ButtonStyle {
                    background: Rectangle {
                        implicitWidth: commandiwidgetwidth*ibuttonwidth
                        implicitHeight: commandiwidgetheight*ibuttonheight
                        border.width: control.activeFocus ?2 : 1
                        border.color: "#800"
                        radius: 8
                        gradient: Gradient {
                            GradientStop { position: 0 ;color: control.pressed ? "#a00" : "#FF00F000" }
                            GradientStop { position: 1 ;color: control.pressed ? "#500" : "#8F002000" }
                        }
                    }
                }
            }

     function retryClicked() {
               console.log("DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD");
              }

   Connections {
                   target: mQMLCom;
                   onSigWidgetSizeChange:{
                       commandiwidgetwidth = mQMLCom.ReadWidgetParam[4];
                       commandiwidgetheight = mQMLCom.ReadWidgetParam[5];
//                       console.info("1111111onSigMTIChange------------------>"+statusiwidgetwidth+"   "+statusiwidgetheight);
                   }
               }

}
