/****************************************************************************
 *
 *   (c) 2009-2016 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/


/**
 * @file
 *   @brief QGC Attitude Instrument
 *   @author Gus Grubba <mavlink@grubba.com>
 */

import QtQuick              2.3
import QtGraphicalEffects   1.0
import an.qt.QMLCommunicate 1.0
/**
*import QGroundControl               1.0
*import QGroundControl.Controls      1.0
*import QGroundControl.ScreenTools   1.0
*/
Item {
    id: root

    property bool showPitch:    true
    property var  vehicle:      null
    property real size
    property bool showHeading:  true

    property real _rollAngle:   mQMLCom ? mQMLCom.ReadRoll  : 30
    property real _pitchAngle:  mQMLCom ? mQMLCom.ReadPitch : -10

    width:  360
    height: 360
    Item {
        id:             instrument
        anchors.fill:   parent
        visible:        false


        //----------------------------------------------------
        //-- Artificial Horizon
        QGCArtificialHorizon {
            rollAngle:          _rollAngle
            pitchAngle:         _pitchAngle
            anchors.fill:       parent
        }

        //----------------------------------------------------
        //-- Pointer
        Image {
            id:                 pointer
            source:             "/qmlimages/attitudePointer.png"
            mipmap:             true
            fillMode:           Image.PreserveAspectFit
            anchors.fill:       parent
            sourceSize.height:  parent.height
        }
        //----------------------------------------------------

        //-- Instrument Dial
        Image {
            id:                 instrumentDial
            source:             "/qmlimages/attitudeDial.png"
            mipmap:             true
            fillMode:           Image.PreserveAspectFit
            anchors.fill:       parent
            sourceSize.height:  parent.height
            transform: Rotation {
                origin.x:       root.width  / 2
                origin.y:       root.height / 2
                angle:          -_rollAngle
            }
        }

        //----------------------------------------------------
        //-- Pitch
        QGCPitchIndicator {
            id:                 pitchWidget
            visible:            root.showPitch
            size:               root.size * 0.5
            anchors.verticalCenter: parent.verticalCenter
            pitchAngle:         _pitchAngle
            rollAngle:          _rollAngle
            color:              Qt.rgba(0,255,0,0)
        }

        //----------------------------------------------------
        //-- Cross Hair
        Image {
            id:                 crossHair
  //          anchors.centerIn:   parent
            anchors.fill:       parent
            source:             "/qmlimages/crossHair.png"
            mipmap:             true
            width:              size * 0.75
            sourceSize.width:   width
            fillMode:           Image.PreserveAspectFit
        }
    }


    Rectangle {
        id:             mask
        anchors.fill:   instrument
        radius:         width / 2
        color:          "yellow"
        visible:        false
    }

    OpacityMask {
        anchors.fill: instrument
        source: instrument
        maskSource: mask
    }

    Rectangle {
        id:             borderRect
        anchors.fill:   parent
        radius:         width / 2
        opacity:0.6
        color:          Qt.rgba(0,0,255,0)
        border.color:   "black"
        border.width:   2
    }

    QGCLabel {
        anchors.bottomMargin:       Math.round(12 * .75)
        anchors.bottom:             parent.bottom
        anchors.horizontalCenter:   parent.horizontalCenter
        text:                       _headingString3
        color:                      "red"
        visible:                    showHeading

        property string _headingString: mQMLCom ? vehicle.heading.rawValue.toFixed(0) : "OFF"
        property string _headingString2: _headingString.length === 1 ? "0" + _headingString : _headingString
        property string _headingString3: _headingString2.length === 2 ? "0" + _headingString2 : _headingString2
    }

    Connections {
            target: mQMLCom;
            onSigMTIChange:{
                _rollAngle = mQMLCom.ReadRoll;
                _pitchAngle = mQMLCom.ReadPitch;
            }
        }


}
