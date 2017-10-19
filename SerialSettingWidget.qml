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
        x:0
        y:0
        width: parent.width
        height: parent.height
        opacity:0.9
        radius: 16
        color: "lightblue"//内部的颜色
        gradient: Gradient {
            GradientStop { position: 0 ;color:  "#FF87CEEB"  }
            GradientStop { position: 1 ;color:  "#FF305555"  }
        }
    }
    QGCComboBox {
        x:widthspace
        y:highspace
        width: iwidgetwidth*widthsize
        height: iwidgetheight*highsize
        strItemName: "串口号"
        _mode:["COM3","COM4","COM5","COM6","COM7","COM8"]
    }

    QGCComboBox{
        x:widthspace*2 + iwidgetwidth*widthsize
        y:highspace
        width: iwidgetwidth*widthsize
        height: iwidgetheight*highsize
        strItemName: "波特率"
        _mode:["115200","230400","57600","38400","19200","9600"]
    }

    QGCComboBox{
        x:widthspace
        y:highspace*2+iwidgetheight*highsize
        width: iwidgetwidth*widthsize
        height: iwidgetheight*highsize
        strItemName: "停止位"
        _mode:["1","1.5","2"]
    }

    QGCComboBox{
        x:widthspace*2 + iwidgetwidth*widthsize
        y:highspace*2+iwidgetheight*highsize
        width: iwidgetwidth*widthsize
        height: iwidgetheight*highsize
        strItemName: "数据位"
        _mode:["8","7","6"]
    }

    QGCComboBox{
        x:widthspace
        y:highspace*3+2*(iwidgetheight*highsize)
        width: iwidgetwidth*widthsize
        height: iwidgetheight*highsize
        strItemName: "奇偶校验"
        _mode:["无","奇校验","偶校验"]
    }

    QGCComButton {
        x:widthspace*2 + iwidgetwidth*widthsize
        y:highspace*3+2*(iwidgetheight*highsize)
        width: iwidgetwidth*widthsize
        height: iwidgetheight*highsize
        colorstatussymbol: bComStatus? "#FF555555":"red"
        strButtonText: bComStatus? "打开串口":"关闭串口"
    }

   QGCButton {
       anchors.bottom: parent.bottom
       anchors.right: parent.right
       anchors.rightMargin: 20
       anchors.bottomMargin: 6
       width: iwidgetwidth*0.1
       height: iwidgetheight*0.1

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
