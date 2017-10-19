import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.2
import QtQuick 2.0
import an.qt.QMLCommunicate 1.0

Rectangle {
    property int  _chosedItem: currentIndex
    property var  strTaskName:mQMLCom ? mQMLCom.ReadFlyPrepareData[0] : ""
    property var  strOperatorName:mQMLCom ? mQMLCom.ReadFlyPrepareData[1] : ""
    property var  strOperatorIDNum:mQMLCom ? mQMLCom.ReadFlyPrepareData[2] : ""
    property var  strFlyDataList: mQMLCom.ReadFlyPrepareData
    property real  widthsize: 0.4
    property real  _page1highsize: 0.075
    property real _page2widthspace: 0.2
    property real _page2heightspace: 0.08
    property real _page3widthspace: 0.1
    property real _page4widthspace: 0.1
    property real _page4heightspace: 0.1
    property real _page5widthspace: 0.1
    id:listrect
    width: parent.width
    height:parent.height
    color: "steelblue"
//    color:"#00000000"
    opacity: 0.7
    signal sigSendRecordData(int iIndex);
    ListModel{
        id:listData
        ListElement{
            fruitName:"1:基本信息登记"
        }
        ListElement{
            fruitName:"2.安装及连接检查"
        }
        ListElement{
            fruitName:"3.RC遥控舵面检查"
        }
        ListElement{
            fruitName:"4.飞控舵面/指令检查"
        }
        ListElement{
            fruitName:"5.姿态检查"
        }
        ListElement{
            fruitName:"6.磁航向检查"
        }
        ListElement{
            fruitName:"7.高度检查"
        }
        ListElement{
            fruitName:"8.空速检查"
        }
        ListElement{
            fruitName:"9.RC遥控距离检查"
        }
        ListElement{
            fruitName:"10.任务载荷检查"
        }
        ListElement{
            fruitName:"11.航线规划检查"
        }
        ListElement{
            fruitName:"12.保护配置"
        }
        ListElement{
            fruitName:"13.初始油门检查"
        }
        ListElement{
            fruitName:"14.震动状态检查"
        }
        ListElement{
            fruitName:"15.最终确认"
        }
    }

    ListView {
        id:_listview2
        //自适应宽高
//        anchors.fill: parent
        width:parent.width/3
        height: parent.height
        anchors.left: parent.left
        //距顶部2px
        anchors.top: parent.top
        anchors.topMargin: 2
        //数据
        model: listData
        //当前选中项 默认为0
        currentIndex: -1
        //滑动启用，默认启用
        interactive: true
        //间隔
        spacing:1

        onCurrentIndexChanged: {
            if(currentIndex == 0)
            {
               // _page1loader.source= "TestCompend1.qml"
                _page1loader.sourceComponent=_page1
            }
            else if(currentIndex == 1)
            {
                // _page1loader.source="TestCompend2.qml"
                _page1loader.sourceComponent=_page2
            }
            else if(currentIndex == 2)
            {
                // _page1loader.source="TestCompend2.qml"
                _page1loader.sourceComponent=_page3
            }
            else if(currentIndex == 3)
            {
                // _page1loader.source="TestCompend2.qml"
                _page1loader.sourceComponent=_page4
            }
            else if(currentIndex == 4)
            {
                // _page1loader.source="TestCompend2.qml"
                _page1loader.sourceComponent=_page5
            }
            else if(currentIndex == 5)
            {
                // _page1loader.source="TestCompend2.qml"
                _page1loader.sourceComponent=_page6
            }
            else
            {
                // _page1loader.source="TestCompend2.qml"
                _page1loader.sourceComponent=_page7
            }

        }

        //分类数据源 加"" 引用
        section.property: "title"
        section.criteria: ViewSection.FullString
        section.delegate: Rectangle{
            id:titleRect
            width: ListView.view.width
            height:15
//            radius: 8
            Text{
                //系统默认关键字
                text:section
                //比较pixelSize
                font.pointSize: 14
                //距离左边5px
                anchors.left: parent.left
                anchors.leftMargin: 5
                //上下居中
                anchors.verticalCenter: parent.verticalCenter
            }

        }

        //布局  可以封装到文件
        delegate: Rectangle {
            id:rect
            color: ListView.isCurrentItem?"green":"lightblue"
            //高度设置
            //height: ListView.view.height-30
            implicitHeight: showText.contentHeight*3
            width: ListView.view.width
//            radius: 8
            Text {
                id:showText
                //上下 左右居中
                //anchors.centerIn: parent
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: 20
                //显示文本
                text: fruitName
                font.pixelSize: 14
                color: rect.ListView.isCurrentItem?"white":"green"//"white"
            }
            MouseArea{
                //覆盖 rect 组件
                anchors.fill: parent
                onClicked: {
                    //index  系统默认
                    rect.ListView.view.currentIndex = index;
                }
            }

        }

    }
    Loader{
        id:_page1loader
        anchors.left : _listview2.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        sourceComponent: _page1
    }

    Component {  //登记
        id:_page1
        Rectangle{
            id:_page1rect
            color:"#000000FF"

            QGCLineEdit{
                id:_taskname
                anchors.left: parent.left
                anchors.leftMargin: 10
                anchors.right: parent.right
                anchors.rightMargin: 10
                anchors.top: parent.top
                anchors.topMargin: _page1highsize*parent.height/2
                height: _page1highsize*parent.height
                strItemName:"任务名称"
                strText:strFlyDataList[0]
            }
            QGCLineEdit{
                id:_operatorname
                anchors.left: parent.left
                anchors.leftMargin: 10
                anchors.right: parent.right
                anchors.rightMargin: 100
                anchors.top: _taskname.bottom
                anchors.topMargin: _page1highsize*parent.height/2
                height: _page1highsize*parent.height
                strItemName:"操作员姓名"
                strText:strFlyDataList[1]
            }

            QGCLineEdit{
                id:_operatoridnumber
                anchors.left: parent.left
                anchors.leftMargin: 10
                anchors.right: parent.right
                anchors.rightMargin: 100
                anchors.top: _operatorname.bottom
                anchors.topMargin: _page1highsize*parent.height/2
                height: _page1highsize*parent.height
                strItemName:"证件号码"
                strText:strFlyDataList[2]
            }


            QGCLineEdit{
                id:_aircraft
                anchors.left: parent.left
                anchors.leftMargin: 10
                anchors.right: parent.right
                anchors.rightMargin: 100
                anchors.top: _operatoridnumber.bottom
                anchors.topMargin: _page1highsize*parent.height/2
                height: _page1highsize*parent.height
                strItemName:"飞机编号"
                strText:strFlyDataList[3]
            }

            QGCLineEdit{
                id:_takeoffweight
                anchors.left: parent.left
                anchors.leftMargin: 10
                anchors.right: parent.right
                anchors.rightMargin: 100
                anchors.top: _aircraft.bottom
                anchors.topMargin: _page1highsize*parent.height/2
                height: _page1highsize*parent.height
                strItemName:"起飞重量"
                strText:strFlyDataList[4]
            }

            QGCLineEdit{
                id:_cellvol1
                width: 180
                anchors.left: parent.left
                anchors.leftMargin: 10
                //anchors.right: _cellvol2.left
                //anchors.rightMargin: 100
                anchors.top: _takeoffweight.bottom
                anchors.topMargin: _page1highsize*parent.height/2
                height: _page1highsize*parent.height
                strItemName:"电池1电压"
                strText:strFlyDataList[5]
            }

            QGCLineEdit{
                id:_cellvol2
                anchors.left: _cellvol1.right
                anchors.leftMargin: 10
                anchors.right: parent.right
                anchors.rightMargin: 20
                anchors.top: _takeoffweight.bottom
                anchors.topMargin: _page1highsize*parent.height/2
                height: _page1highsize*parent.height
                strItemName:"电池2电压"
                strText:strFlyDataList[6]
            }

            QGCLineEdit{
                id:_weather
                anchors.left: parent.left
                anchors.leftMargin: 10
                anchors.right: parent.right
                anchors.rightMargin: 100
                anchors.top: _cellvol1.bottom
                anchors.topMargin: _page1highsize*parent.height/2
                height: _page1highsize*parent.height
                strItemName:"天气情况"
                strText:strFlyDataList[7]
            }

            QGCLineEdit{
                id:_windpower
                anchors.left: parent.left
                anchors.leftMargin: 10
                anchors.top: _weather.bottom
                anchors.topMargin: _page1highsize*parent.height/2
                width: 180
                height: _page1highsize*parent.height
                strItemName:"风力"
                strText:strFlyDataList[8]
            }
            QGCLineEdit{
                id:_winddire
                anchors.left: _windpower.right
                anchors.leftMargin: 10
                anchors.right: parent.right
                anchors.rightMargin: 20
                anchors.top: _weather.bottom
                anchors.topMargin: _page1highsize*parent.height/2
                height: _page1highsize*parent.height
                strItemName:"风向"
                strText:strFlyDataList[9]
            }
            QGCButton {
                id:_checkagain
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 10
                anchors.right: _clearpage.left
                anchors.margins: 15
                width: 80
                height: 30
                strTxt:"重新检查"

            }
            QGCButton {
                id:_clearpage
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 10
                anchors.right: _checkbox.left
                anchors.margins: 15
                width: 80
                height: 30
                strTxt:"清空本页"
                onSigButtonClicked:{
                    clearRecordData();
                }


            }
            CheckBox{
                id:_checkbox
                anchors.right: parent.right
                anchors.rightMargin: 5
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 4
                width: 80
                height: 30
                text:"完成登记";
                onClicked:
                      {
                                if(_checkbox.checkedState)
                                {
                                _listview2.currentIndex=1;
                                }
                                saveRecordData();
                                console.log("YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY.."+strFlyDataList[0]);
                       }
                }
            function saveRecordData(){
                strFlyDataList[0]=_taskname.strText;
                strFlyDataList[1]=_operatorname.strText;
                strFlyDataList[2]=_operatoridnumber.strText;
                strFlyDataList[3]=_aircraft.strText;
                strFlyDataList[4]=_takeoffweight.strText;
                strFlyDataList[5]=_cellvol1.strText;
                strFlyDataList[6]=_cellvol2.strText;
                strFlyDataList[7]=_weather.strText;
                strFlyDataList[8]=_windpower.strText;
                strFlyDataList[9]=_winddire.strText;
                mQMLCom.qmlCallFlyPreparefunction(strFlyDataList);
                console.log("TTTTTTTTTTTTTTTTTTTT..");
            }
            function clearRecordData(){
                _taskname.strText="";
                _operatorname.strText="";
                _operatoridnumber.strText="";
                _aircraft.strText="";
                _takeoffweight.strText="";
                _cellvol1.strText="";
                _cellvol2.strText="";
                _weather.strText="";
                _windpower.strText="";
                _winddire.strText="";
                saveRecordData();
            }

        }


    }



    Component {
        id:_page2
        Rectangle{
            color:"#0000FFFF"
            CheckBox{
                id:_page2_checkbox1
                anchors.top: parent.top
                anchors.topMargin:_page2heightspace*parent.height
                anchors.left: parent.left
                anchors.leftMargin: _page2widthspace*parent.width

                width: 200
                height: 50
                //Font.pointSize: 14
                //FontLoader: { id: fixedFont; name: "Courier" }
                text:"机体、机翼、起落架安装牢靠？";
            }

            CheckBox{
                id:_page2_checkbox2
                anchors.top: _page2_checkbox1.top
                anchors.topMargin:_page2heightspace*parent.height
                anchors.left: parent.left
                anchors.leftMargin: _page2widthspace*parent.width

                width: 200
                height: 50
                //Font.pointSize: 14
                //FontLoader: { id: fixedFont; name: "Courier" }
                text:"各活动舵面、连杆安装牢靠？";
            }

            CheckBox{
                id:_page2_checkbox3
                anchors.top: _page2_checkbox2.top
                anchors.topMargin:_page2heightspace*parent.height
                anchors.left: parent.left
                anchors.leftMargin: _page2widthspace*parent.width

                width: 200
                height: 50
                //Font.pointSize: 14
                //FontLoader: { id: fixedFont; name: "Courier" }
                text:"螺旋桨的旋转方向是否正确？";
            }

            CheckBox{
                id:_page2_checkbox4
                anchors.top: _page2_checkbox3.top
                anchors.topMargin:_page2heightspace*parent.height
                anchors.left: parent.left
                anchors.leftMargin: _page2widthspace*parent.width

                width: 200
                height: 50
                //Font.pointSize: 14
                //FontLoader: { id: fixedFont; name: "Courier" }
                text:"发动机、电机、螺旋桨安装牢靠？";
            }

            CheckBox{
                id:_page2_checkbox5
                anchors.top: _page2_checkbox4.top
                anchors.topMargin:_page2heightspace*parent.height
                anchors.left: parent.left
                anchors.leftMargin: _page2widthspace*parent.width

                width: 200
                height: 50
                //Font.pointSize: 14
                //FontLoader: { id: fixedFont; name: "Courier" }
                text:"各机载设备、天线安装牢靠？";
            }

            CheckBox{
                id:_page2_checkbox6
                anchors.top: _page2_checkbox5.top
                anchors.topMargin:_page2heightspace*parent.height
                anchors.left: parent.left
                anchors.leftMargin: _page2widthspace*parent.width

                width: 200
                height: 50
                //Font.pointSize: 14
                //FontLoader: { id: fixedFont; name: "Courier" }
                text:"飞控接口航插拧紧？其他电缆连接正确可靠？";
            }

            CheckBox{
                id:_page2_checkbox7
                anchors.top: _page2_checkbox6.top
                anchors.topMargin:_page2heightspace*parent.height
                anchors.left: parent.left
                anchors.leftMargin: _page2widthspace*parent.width

                width: 200
                height: 50
                //Font.pointSize: 14
                //FontLoader: { id: fixedFont; name: "Courier" }
                text:"空速管路无堵塞、漏气现象？";
            }

            CheckBox{
                id:_page2_checkbox8
                anchors.top: _page2_checkbox7.top
                anchors.topMargin:_page2heightspace*parent.height
                anchors.left: parent.left
                anchors.leftMargin: _page2widthspace*parent.width

                width: 200
                height: 50
                //Font.pointSize: 14
                //FontLoader: { id: fixedFont; name: "Courier" }
                text:"飞机重心位置在合理范围内？";
            }

            CheckBox{
                id:_page2_checkbox9
                anchors.top: _page2_checkbox8.top
                anchors.topMargin:_page2heightspace*parent.height
                anchors.left: parent.left
                anchors.leftMargin: _page2widthspace*parent.width

                width: 200
                height: 50
                //Font.pointSize: 14
                //FontLoader: { id: fixedFont; name: "Courier" }
                text:"飞机各口盖是否固定牢靠？";
            }

            QGCButton {
                id:_clearpage
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 10
                anchors.right: _checkbox.left
                anchors.margins: 15
                width: 80
                height: 30
                strTxt:"清空本页"
                onSigButtonClicked:{
                }


            }
            CheckBox{
                id:_checkbox
                anchors.right: parent.right
                anchors.rightMargin: 5
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 4
                width: 80
                height: 30
                text:"完成检查";
                onClicked:
                      {
                                if(_checkbox.checkedState)
                                {
                                _listview2.currentIndex=2;
                                }

                       }
                }
        }
    }

    Component {
        id:_page3
        Rectangle{
            color:"#0000FFFF"
            Image {
                y:parent.height/3
                id: _warnningimage
                anchors.left: parent.left
                anchors.leftMargin: _page3widthspace*parent.width
                width: sourceSize.width
                height:sourceSize.height
                source: "/qmlimages/warnning.png"
            }
            QGCLabel{
                id:_label1
                anchors.left: parent.left
                anchors.leftMargin: _page3widthspace*parent.width
                anchors.top: _warnningimage.bottom
                anchors.topMargin: 10
                text: "操作手切换至RC手动遥控模式，"
            }
            QGCLabel{
                id:_label2
                anchors.left: parent.left
                anchors.leftMargin: _page3widthspace*parent.width
                anchors.top: _label1.bottom
                anchors.topMargin: 10
                text: "操作副翼、升降、油门、方向等活动舵面或机构，"
            }
            QGCLabel{
                id:_label3
                anchors.left: parent.left
                anchors.leftMargin: _page3widthspace*parent.width
                anchors.top: _label2.bottom
                anchors.topMargin: 10
                text: "检查各舵面或机构的零位、行程、正反逻辑是否正常？"
            }
            QGCLabel{
                id:_label4
                anchors.left: parent.left
                anchors.leftMargin: _page3widthspace*parent.width
                anchors.top: _label3.bottom
                anchors.topMargin: 20
                font.pixelSize: 14
                color: "#FFFF0000"
                text: "请确认旋翼各电机的转动方向、控制逻辑是否正常？"
            }
            CheckBox{
                id:_finish
                anchors.right: _checkbox.left
                anchors.rightMargin: 5
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 4
                width: 80
                height: 30
                text:"正常";
                onClicked:
                      {


                       }
                }
            CheckBox{
                id:_checkbox
                anchors.right: parent.right
                anchors.rightMargin: 5
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 4
                width: 80
                height: 30
                text:"完成检查";
                onClicked:
                      {
                                if(_checkbox.checkedState)
                                {
                                _listview2.currentIndex=2;
                                }

                       }
                }
        }
    }

    Component {
        id:_page4
        Rectangle{
            color:"#0000FFFF"
            Image {
                y:parent.height/20
                id: _warnningimage
                anchors.left: parent.left
                anchors.leftMargin: _page4widthspace*parent.width
                width: sourceSize.width
                height:sourceSize.height
                source: "/qmlimages/warnning.png"
            }
            QGCLabel{
                id:_label1
                anchors.left: _warnningimage.right
                anchors.leftMargin:5
                anchors.top: _warnningimage.top
                //anchors.topMargin: 10
                text: "切换至固定翼、全自主模式，检查副翼、升降、油门、"
            }
            QGCLabel{
                id:_label2
                anchors.left: _warnningimage.right
                anchors.leftMargin:5
                anchors.top: _label1.bottom
                anchors.topMargin: 10
                text: "方向等活动舵面的零位、行程、正反逻辑是否正常？"
            }

            QGCButton{
                id:_entersteercheckbutton
                anchors.left: _warnningimage.left
                anchors.leftMargin:5
                anchors.top: _warnningimage.bottom
                anchors.topMargin: 10
                anchors.bottom:  _streercheckstatus.bottom
                width: _page4widthspace*parent.width*2
                strTxt: "进入舵面检查"
                onSigButtonClicked: {
                }
            }
            Rectangle{
                id:_streercheckstatus
                anchors.left: _entersteercheckbutton.right
                anchors.leftMargin:_page4widthspace*parent.width
                anchors.top: _warnningimage.bottom
                anchors.topMargin: 10
                border.width:5
                border.color: "#FF000000"
                width: _page4widthspace*parent.width
                height: _page4widthspace*parent.width
                radius: _page4widthspace*parent.width
                color:"#FFFF0000"
            }
            QGCButton{
                id:_exitsteercheckbutton
                anchors.left: _streercheckstatus.right
                anchors.leftMargin:_page4widthspace*parent.width
                anchors.top: _warnningimage.bottom
                anchors.topMargin: 10
                anchors.bottom:  _streercheckstatus.bottom
                width: _page4widthspace*parent.width*2

                strTxt: "退出舵面检查"
                onSigButtonClicked: {

                }
            }
            QGCLabel{
                id:_label3
                anchors.left: _entersteercheckbutton.left

                anchors.top: _entersteercheckbutton.bottom
                anchors.topMargin: 30
                width:50
                height: 20
                text: "副翼"
            }

            QGCLabel{
                id:_label4
                anchors.left: _entersteercheckbutton.left
                anchors.top: _label3.bottom
                anchors.topMargin: 33
                width:50
                height: 20
                text: "升降舵"
            }

            QGCLabel{
                id:_label5
                anchors.left: _entersteercheckbutton.left

                anchors.top: _label4.bottom
                anchors.topMargin: 33
                width:50
                height: 20
                text: "方向舵"
            }

            QGCButton{
                id:_button1
                anchors.left: _label3.right
                anchors.leftMargin:_page4widthspace*parent.width/2
                anchors.top: _entersteercheckbutton.bottom
                anchors.topMargin: 13
                height: 40
                width: _page4widthspace*parent.width*3/2

                strTxt: "左上右下"
                onSigButtonClicked: {

                }
            }

            QGCButton{
                id:_button2
                anchors.left: _button1.right
                anchors.leftMargin:_page4widthspace*parent.width/2
                anchors.top: _button1.top
                anchors.bottom: _button1.bottom
                width: _page4widthspace*parent.width*3/2

                strTxt: "中位"
                onSigButtonClicked: {

                }
            }

            QGCButton{
                id:_button3
                anchors.left: _button2.right
                anchors.leftMargin:_page4widthspace*parent.width/2
                anchors.top: _button1.top
                anchors.bottom: _button1.bottom
                width: _page4widthspace*parent.width*3/2

                strTxt: "左下右上"
                onSigButtonClicked: {

                }
            }


            QGCButton{
                id:_button4
                anchors.left: _label4.right
                anchors.leftMargin:_page4widthspace*parent.width/2
                anchors.top: _button1.bottom
                anchors.topMargin: 13
                height: 40
                width: _page4widthspace*parent.width*3/2

                strTxt: "下偏"
                onSigButtonClicked: {

                }
            }

            QGCButton{
                id:_button5
                anchors.left: _button4.right
                anchors.leftMargin:_page4widthspace*parent.width/2
                anchors.top: _button4.top
                anchors.bottom: _button4.bottom
                width: _page4widthspace*parent.width*3/2

                strTxt: "中位"
                onSigButtonClicked: {

                }
            }

            QGCButton{
                id:_button6
                anchors.left: _button5.right
                anchors.leftMargin:_page4widthspace*parent.width/2
                anchors.top: _button4.top
                anchors.bottom: _button4.bottom
                width: _page4widthspace*parent.width*3/2

                strTxt: "上偏"
                onSigButtonClicked: {

                }
            }


            QGCButton{
                id:_button7
                anchors.left: _label5.right
                anchors.leftMargin:_page4widthspace*parent.width/2
                anchors.top: _button4.bottom
                anchors.topMargin: 13
                height: 40
                width: _page4widthspace*parent.width*3/2

                strTxt: "左偏"
                onSigButtonClicked: {

                }
            }

            QGCButton{
                id:_button8
                anchors.left: _button7.right
                anchors.leftMargin:_page4widthspace*parent.width/2
                anchors.top: _button7.top
                anchors.bottom: _button7.bottom
                width: _page4widthspace*parent.width*3/2

                strTxt: "中位"
                onSigButtonClicked: {

                }
            }

            QGCButton{
                id:_button9
                anchors.left: _button8.right
                anchors.leftMargin:_page4widthspace*parent.width/2
                anchors.top: _button7.top
                anchors.bottom: _button7.bottom
                width: _page4widthspace*parent.width*3/2

                strTxt: "右偏"
                onSigButtonClicked: {

                }
            }
            Image {
                id: _warnningimage2
                anchors.top: _label5.bottom
                anchors.left: parent.left
                anchors.leftMargin: _page4widthspace*parent.width
                width: sourceSize.width
                height:sourceSize.height
                source: "/qmlimages/warnning.png"
            }
            QGCLabel{
                anchors.top: _warnningimage2.top
                anchors.topMargin: 15
                anchors.left: _warnningimage2.right
                anchors.leftMargin: 5
                anchors.bottom: _warnningimage2.bottom
                width: 300
                text: "检查油门时，应注意防护螺旋桨转动、飞机移动！"
            }

            QGCLabel{
                id:_label6
                anchors.top: _warnningimage2.bottom
                anchors.topMargin: 20
                anchors.left: _warnningimage2.left
                anchors.leftMargin: 10
                height: 20
                width: 30
                text: "油门"
            }

            QGCButton{
                id:_button10
                anchors.top: _warnningimage2.bottom
                anchors.topMargin: 10
                anchors.left: _label6.right
                anchors.leftMargin: _page4widthspace*parent.width/6
                height: _button1.height-5
                width: _page4widthspace*parent.width
                strTxt:  "熄火"
            }

            QGCButton{
                id:_button11
                anchors.top: _warnningimage2.bottom
                anchors.topMargin: 10
                anchors.left: _button10.right
                anchors.leftMargin: _page4widthspace*parent.width/6
                height: _button10.height
                width: _page4widthspace*parent.width
                strTxt:  "怠速"
            }
            QGCButton{
                id:_button12
                anchors.top: _warnningimage2.bottom
                anchors.topMargin: 10
                anchors.left: _button11.right
                anchors.leftMargin: _page4widthspace*parent.width/6
                height: _button10.height
                width: _page4widthspace*parent.width
                strTxt:  "下降"
            }
            QGCButton{
                id:_button13
                anchors.top: _warnningimage2.bottom
                anchors.topMargin: 10
                anchors.left: _button12.right
                anchors.leftMargin: _page4widthspace*parent.width/6
                height: _button10.height
                width: _page4widthspace*parent.width
                strTxt:  "巡航"
            }
            QGCButton{
                id:_button14
                anchors.top: _warnningimage2.bottom
                anchors.topMargin: 10
                anchors.left: _button13.right
                anchors.leftMargin: _page4widthspace*parent.width/6
                height: _button10.height
                width: _page4widthspace*parent.width
                strTxt:  "爬升"
            }
            QGCButton{
                id:_button15
                anchors.top: _warnningimage2.bottom
                anchors.topMargin: 10
                anchors.left: _button14.right
                anchors.leftMargin: _page4widthspace*parent.width/6
                height: _button10.height
                width: _page4widthspace*parent.width
                strTxt:  "最大"
            }

            Rectangle{
                id:_line1
                anchors.top:_label6.bottom
                anchors.topMargin: 10
                anchors.left: _warnningimage2.left
                anchors.right: parent.right
                anchors.rightMargin: 30
                height: 3
                color: "#F0666666"
            }
            QGCButton{
                id:_button16
                anchors.top: _line1.bottom
                anchors.topMargin: 15
                anchors.left: _entersteercheckbutton.left
                anchors.right: _entersteercheckbutton.right
                height: _entersteercheckbutton.height
                width: _entersteercheckbutton.width
                strTxt:  "旋翼检查"
            }
            QGCButton{
                id:_button17
                anchors.top: _line1.bottom
                anchors.topMargin: 15
                anchors.left: _exitsteercheckbutton.left
                anchors.right: _exitsteercheckbutton.right
                height: _exitsteercheckbutton.height
                width: _exitsteercheckbutton.width
                strTxt:  "开关指令检查"
            }
            CheckBox{
                id:_finish
                anchors.right: _checkbox.left
                anchors.rightMargin: 5
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 4
                width: 80
                height: 30
                text:"正常";
                onClicked:
                      {


                       }
                }
            CheckBox{
                id:_checkbox
                anchors.right: parent.right
                anchors.rightMargin: 5
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 4
                width: 80
                height: 30
                text:"完成检查";
                onClicked:
                      {
                                if(_checkbox.checkedState)
                                {
                                _listview2.currentIndex=2;
                                }

                       }
                }
        }
    }

    Component {
        id:_page5
        Rectangle{
            color:"#0000FFFF"
            Image {
                id: _warnningimage
                anchors.top: parent.top
                anchors.topMargin: parent.height/4
                anchors.left: parent.left
                anchors.leftMargin: _page5widthspace*parent.width
                width: sourceSize.width
                height:sourceSize.height
                source: "/qmlimages/warnning.png"
            }
            QGCLabel{
                anchors.top: _warnningimage.top
                anchors.topMargin: 15
                anchors.left: _warnningimage.right
                anchors.leftMargin: 5
                anchors.bottom: _warnningimage.bottom
                width: 300
                text: "转动机身，检查姿态显示是否与实际一致"
            }
            QGCLineEdit{
                id:_pitchedit
                anchors.top: parent.top
                anchors.topMargin: parent.height*4/9
                anchors.left: parent.left
                anchors.leftMargin: parent.width*2/8
                width: 200
                height: 30
                strItemName: "俯仰"
            }

            QGCLineEdit{
                id:_rolledit
                anchors.top: _pitchedit.bottom
                anchors.topMargin: 20
                anchors.left: _pitchedit.left
                width: 200
                height: 30
                strItemName: "滚转"
            }

            QGCLabel{
                id:_pitchlabel
                anchors.top: _pitchedit.top
                anchors.topMargin: 5
                anchors.left: _pitchedit.right
                width: 5
                height: 5
                text: "。"
            }
            QGCLabel{
                id:_rolllabel
                anchors.top: _rolledit.top
                anchors.topMargin: 5
                anchors.left: _rolledit.right
                width: 5
                height: 5
                text: "。"
            }

            CheckBox{
                id:_finish
                anchors.right: _checkbox.left
                anchors.rightMargin: 5
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 4
                width: 80
                height: 30
                text:"一致";
                onClicked:
                      {


                       }
                }
            CheckBox{
                id:_checkbox
                anchors.right: parent.right
                anchors.rightMargin: 5
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 4
                width: 80
                height: 30
                text:"完成检查";
                onClicked:
                      {
                                if(_checkbox.checkedState)
                                {
                                _listview2.currentIndex=2;
                                }

                       }
                }
        }
    }

    Component {
        id:_page6
        Rectangle{
            color:"#0000FFFF"
            Image {
                id: _warnningimage
                anchors.top: parent.top
                anchors.topMargin: parent.height/4
                anchors.left: parent.left
                anchors.leftMargin: _page5widthspace*parent.width
                width: sourceSize.width
                height:sourceSize.height
                source: "/qmlimages/warnning.png"
            }
            QGCLabel{
                anchors.top: _warnningimage.top
                anchors.topMargin: 15
                anchors.left: _warnningimage.right
                anchors.leftMargin: 5
                anchors.bottom: _warnningimage.bottom
                width: 300
                text: "转动机身，检查姿态显示是否与实际一致"
            }
            QGCLineEdit{
                id:_yawedit
                anchors.top: parent.top
                anchors.topMargin: parent.height*4/9
                anchors.left: parent.left
                anchors.leftMargin: parent.width*2/8
                width: 200
                height: 30
                strItemName: "磁航向"
            }

            QGCLabel{
                id:_yawlabel
                anchors.top: _yawedit.top
                anchors.topMargin: 5
                anchors.left: _yawedit.right
                width: 5
                height: 5
                text: "。"
            }

            Image {
                id: _warnningimage2
                anchors.top: parent.top
                anchors.topMargin: parent.height*5/8
                anchors.left: parent.left
                anchors.leftMargin: _page5widthspace*parent.width
                width: sourceSize.width
                height:sourceSize.height
                source: "/qmlimages/warnning.png"
            }
            QGCLabel{
                anchors.top: _warnningimage2.top
                anchors.topMargin: 15
                anchors.left: _warnningimage2.right
                anchors.leftMargin: 5
                anchors.bottom: _warnningimage2.bottom
                width: 300
                text: "若当偏差>20度，则建议重新校准磁航向，\n若偏差>30度，则必须重新校准磁航向。"
            }


            CheckBox{
                id:_finish
                anchors.right: _checkbox.left
                anchors.rightMargin: 5
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 4
                width: 80
                height: 30
                text:"一致";
                onClicked:
                      {


                       }
                }
            CheckBox{
                id:_checkbox
                anchors.right: parent.right
                anchors.rightMargin: 5
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 4
                width: 80
                height: 30
                text:"完成检查";
                onClicked:
                      {
                                if(_checkbox.checkedState)
                                {
                                _listview2.currentIndex=2;
                                }

                       }
                }
        }
    }

    Component {
        id:_page7
        Rectangle{
            color:"#FF00FFFF"

        }
    }




    //加载完成时设置数据源
    Component.onCompleted: {
        //增加数据
 //       listData.append({fruitName:"Orange",title:"O"})
    }
}
