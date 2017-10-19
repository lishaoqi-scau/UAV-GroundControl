import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.4

//import QGroundControl.Palette 1.0
//import QGroundControl.ScreenTools 1.0

Rectangle {
    property real pitchAngle:       0
    property real rollAngle:        0
    property real size:              100
    property real _reticleHeight:   1
    property real _reticleSpacing:  size * 0.15
    property real _reticleSlot:     _reticleSpacing + _reticleHeight
    property real _longDash:        size * 0.17
    property real _shortDash:       size * 0.09
    property real _fontSize:        12 * 0.75
    property int  _skyspeedspace: 10
    property int  _skyspeedmodenumber: 36
    property int  _prealtspace: 5
    property int  _prealtmodenumber: 36
    property real  _targetskyspeed: 10.56
    property real  _currentskyspeed: 10.56
    property real  _targetheight: 30.2
    property real  _currentheight: 30.2



    height: 200
    width:  62
 //   anchors.left: parent.horizontalCenter
 //   anchors.verticalCenter:   parent .verticalCenter
    clip: true
    visible: true
    color:"#00000000"
    /*
    Rectangle{
        anchors.verticalCenter:  parent.verticalCenter
        width: parent.width
        height: 1
        color: "yellow"
    }
    */

    Image {
        id: _skyspeedscale
        source: "qmlimages/skyspeedscale.png"
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: _skyspeeditem.right
        anchors.leftMargin: -5
        width:sourceSize.width/3
        height: sourceSize.height/3
    }

    Image {
        id: _heightscale
        source: "qmlimages/heightscale.png"
        anchors.verticalCenter: parent.verticalCenter
        anchors.right:  _heightitem.left
        anchors.rightMargin: -5
        width:sourceSize.width/3
        height: sourceSize.height/3
    }

    QGCLabel{
        id:_currentskyspeedlabel
       anchors.left: _skyspeeditem.right
       anchors.leftMargin: parent.width/40
       anchors.bottom: parent.bottom
       anchors.bottomMargin: 5
       width: parent.width*1/10
       height: parent.height/10
       text:_currentskyspeed
       font.pixelSize: 19
    }

    QGCLabel{
        id:_targetskyspeedlabel
       anchors.left: _skyspeeditem.right
       anchors.leftMargin: parent.width/40
       anchors.bottom: _currentskyspeedlabel.top
       anchors.bottomMargin: 5
       width: parent.width*1/10
       height: parent.height/10
       color:"#FFFFFF00"
       text:_targetskyspeed
       font.pixelSize: 19
    }

    QGCLabel{
        id:_currentheightlabel
       anchors.right: _heightitem.left
       anchors.rightMargin: parent.width/40
       anchors.bottom: parent.bottom
       anchors.bottomMargin: 5
       width: parent.width*1/10
       height: parent.height/10
       text:_currentheight
       font.pixelSize: 19
    }

    QGCLabel{
        id:_targetheightlabel
       anchors.right: _heightitem.left
       anchors.rightMargin: parent.width/40
       anchors.bottom: _currentheightlabel.top
       anchors.bottomMargin: 5
       width: parent.width*1/10
       height: parent.height/10
       color:"#FFFFFF00"
       text:_targetheight
       font.pixelSize: 19
    }



    Item {//空速
        id:_skyspeeditem
        height: parent.height
        width:  45
        Column{
            anchors.left: parent.left
            anchors.verticalCenter:   parent.verticalCenter
            spacing: _reticleSpacing
            Repeater {
                model: _skyspeedmodenumber    //重复的数量
                Rectangle {
                    property int _skyspeed: -(modelData *_skyspeedspace -(_skyspeedspace*_skyspeedmodenumber/2) )
//                    anchors.horizontalCenter: parent.horizontalCenter
                    width: (_skyspeed % (_skyspeedspace*2)) === 0 ? _longDash : _shortDash
                    height: _reticleHeight
                    color: "black"
                    antialiasing: true
                    smooth: true


                    QGCLabel {
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.horizontalCenterOffset: (_longDash+5)

                        anchors.verticalCenter: parent.verticalCenter
                        smooth: true
                        font.family: "fixed"
                        font.pointSize: _fontSize
                        text: _skyspeed
                        color: "black"
                        visible: (_skyspeed != 0) && ((_skyspeed % (_skyspeedspace*2)) === 0)
                    }


               }
            }

        }

        transform: [ Translate {
                y: (_currentskyspeed * _reticleSlot / _skyspeedspace) - (_reticleSlot / 2)
                }]

    }

    Item {//气压高
        id:_heightitem
        anchors.right: parent.right
        height: parent.height
        width:  45
        Column{
            anchors.right: parent.right
            anchors.verticalCenter:   parent.verticalCenter
            spacing: _reticleSpacing
            Repeater {
                model: _prealtmodenumber    //重复的数量
                Rectangle {
                    anchors.right: parent.right
                    property int _prealt: -(modelData *_prealtspace  - (_prealtspace*_prealtmodenumber/2))
//                    anchors.horizontalCenter: parent.horizontalCenter
                    width: (_prealt % (_prealtspace*2)) === 0 ? _longDash : _shortDash
                    height: _reticleHeight
                    color: "black"
                    antialiasing: true
                    smooth: true


                    QGCLabel {
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.horizontalCenterOffset: -(_longDash+5)
                        anchors.verticalCenter: parent.verticalCenter
                        smooth: true
                        font.family: "fixed"
                        font.pointSize: _fontSize
                        text: _prealt
                        color: "black"
                        visible: (_prealt != 0) && (_prealt % (_prealtspace*2) === 0)
                    }

               }
            }

        }

        transform: [ Translate {
                y: (_currentheight * _reticleSlot / _prealtspace) - (_reticleSlot / 2)
                }]
    }

}
