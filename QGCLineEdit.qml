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
    property var strText: _loader.item.text
    id:itemrect
    x:0
    y:0
    width: 250
    height: 40
    color: "#006666FF"
    clip:true
    Loader{
        id:_loader
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
            property alias text: input.text
            property alias placeHoldText: placeHold.text
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

            TextInput{
                id: input
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.left: iconArea.right
                anchors.leftMargin: 6
                anchors.right: parent.right
                anchors.rightMargin: 9
                horizontalAlignment: TextInput.AlignLeft
                verticalAlignment: TextInput.AlignVCenter
                font.pixelSize: iInputTxtFontSize
                color: "black"
                clip: true
                text:strText

                Text {
                    id: placeHold
                    font: input.font
                    color: "#88808080"
//                    opacity: !input.activeFocus
                    opacity: input.length? 0:1
                    Behavior on opacity{
                        NumberAnimation{ duration: 300 }
                    }
                    anchors.fill: parent
                    verticalAlignment: TextInput.AlignVCenter

                }
                onTextChanged: {
                    strText= text
                }
            }
        }
    }
}
