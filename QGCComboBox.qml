import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.4

import QtQuick 2.0


Rectangle {
    property var  strItemName : "No Set"
    property int  iItemNameFontSize: 8
    property var  colorItemName : "black"
    property int  opacityItemName: 1
    property int  iInputTxtFontSize:12
    property var  _mode: ["TV","CD Player","Set Top BOX","Router"]
    id:itemrect
    x:0
    y:0
    width: 250
    height: 40
    color: "#006666FF"
    clip:true
    Loader{
        anchors.centerIn: parent
//        anchors.verticalCenterOffset: -60
        sourceComponent: component
        onLoaded: {
            item.placeHoldText = "请输入"
            item.color = "#FF00FF"
        }
    }

    Component{
        id: component

        Item{


//            property alias text: inputcombo.textAt(1)
//            property alias placeHoldText: placeHold.text
            width: itemrect.width
            height: itemrect.height
            Rectangle{
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.left: iconArea.right
                anchors.leftMargin: 6
                anchors.right: parent.right
                anchors.rightMargin: 9
                radius: 6
                opacity: 0.2
            }

            Rectangle{ // you can change to Image
                id: iconArea
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
                anchors.leftMargin: 9
                width: 60
                height: 30
                clip:true
                color:"#00FFFFFF"   //背景透明
                Text {
                    id: itemname
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    font: iItemNameFontSize
                    color: colorItemName
                    opacity: opacityItemName
                    text:strItemName+":"
                }
            }

            ComboBox {
                id:inputcombo
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.left: iconArea.right
                anchors.leftMargin: 6
                anchors.right: parent.right
                anchors.rightMargin: 9
                currentIndex: 2
                model:_mode
                /*
                model: ListModel {
                    id: cbItems
                    ListElement { text: "Banana";color: "Yellow" }
                    ListElement { text: "Apple";color: "Green" }
                    ListElement { text:"Coconut"; color: "Brown" }
                }
                */

                style: ComboBoxStyle{
                        id:style
                        background:Rectangle {
                            id:background
                            width: inputcombo.width
                            height: inputcombo.height
                            border.color: borderColor
                            border.width: borderWidth
                            gradient: Gradient {
                                GradientStop { position: 0 ;color:  "#8007CEEB"  }
                                GradientStop { position: 1 ;color:  "#80005555"  }
                            }
                            Image {
                                            id: imageDropdown
                                            width: height
                                            height: 0.5 * parent.height
                                            anchors.right: parent.right
                                            anchors.rightMargin: 10
                                            anchors.verticalCenter: parent.verticalCenter
                                            fillMode: Image.Stretch
                                            source: "qrc:/png/comboxchose.png"
                                        }
                         }
                        }
                onCurrentIndexChanged:console.debug(cbItems.get(currentIndex).text + ", " +cbItems.get(currentIndex).color)
            }
        }


    }
}
