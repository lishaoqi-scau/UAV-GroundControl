import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.4
Rectangle{
    property bool bComStatus: false
    property var  strTxt: "关闭"
    id:buttonrect
    width: 640
    height: 480
    radius: 10;//圆角
    clip:true//这一属性设置表示如果他的子类超出了范围，那么就剪切掉，不让他显示和起作用
    color :"#00000000"
    signal sigButtonClicked
/*
    Rectangle {
        id:statusicon
        anchors.left: parent.left
        anchors.verticalCenter: parent.verticalCenter

        anchors.leftMargin: 16
        width: buttonrect.height*2/3
        height: buttonrect.height*2/3
        radius: buttonrect.height*2 / 6
        border.color:"black"
        border.width: 3
        color: bComStatus ? "red":"#FF888888"
    }
*/
    Button{
        id:_button
        text: strTxt
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.left: parent.left

        anchors.right: parent.right


        clip:true//这一属性设置表示如果他的子类超出了范围，那么就剪切掉，不让他显示和起作用
        //anchors.centerIn: parent
        style: ButtonStyle{
            background: Rectangle{
            implicitWidth: buttonrect.width
            implicitHeight: buttonrect.height
            border.width: control.press?4:2
            border.color: (control.hovered||control.pressed)?"blue":"green"

            radius:10
/*
            gradient: Gradient {
                GradientStop { position: 0 ;color:  "#80AAAAAA"  }
                GradientStop { position: 1 ;color:  "#8F555555"  }
            }
*/
            gradient: Gradient {
                GradientStop { position: 0 ;color: control.pressed ? "#80AAAAAA" : "#80AAAAAA" }
                GradientStop { position: 1 ;color: control.pressed ? "#8F111111" : "#8F555555" }
            }
        }
    }

    onClicked: {
        buttonrect.sigButtonClicked();
    }
    }

}
