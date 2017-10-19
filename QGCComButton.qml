import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.4
Rectangle{
    property bool bComStatus: false
    property var  strButtonText: bComStatus ? "关闭串口":"打开串口"
    property var  colorstatussymbol: bComStatus ? "red":"#FF888888"
    id:buttonrect
    width: 640
    height: 480
    radius: 10;//圆角
    clip:true//这一属性设置表示如果他的子类超出了范围，那么就剪切掉，不让他显示和起作用
    color :"#00000000"

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
        color: colorstatussymbol
    }

    Button{
        text:strButtonText
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.left: statusicon.right
        anchors.leftMargin: 16
        anchors.right: parent.right
        anchors.rightMargin: 9

        clip:true//这一属性设置表示如果他的子类超出了范围，那么就剪切掉，不让他显示和起作用
        //anchors.centerIn: parent
        style: ButtonStyle{
            background: Rectangle{
            implicitWidth: buttonrect.width
            implicitHeight: buttonrect.height
            border.width: control.press?4:2
            border.color: (control.hovered||control.pressed)?"blue":"green"
            radius:10
            gradient: Gradient {
                GradientStop { position: 0 ;color:  "#F000CE5B"  }
                GradientStop { position: 1 ;color:  "#8F005535"  }
            }
        }
    }

    onClicked: {
        console.log("The button is pressed!")
    }
    }

}
