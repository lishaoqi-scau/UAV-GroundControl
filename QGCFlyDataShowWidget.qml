import QtQuick 2.0

import QtQuick              2.3
import QtGraphicalEffects   1.0
import an.qt.QMLCommunicate 1.0
Item {
    id: flydata

    property bool showPitch:    true
    property var  vehicle:      null
    property real size
    property bool showHeading:  true
    property int  maxStringLength: 13
    property var  param:  mQMLCom ? mQMLCom.ReadParam : 0
    property real _textlon:   mQMLCom ? param[0] :"NAN"
    property real _textlat:  mQMLCom ? param[1] : "NAN"
    property color _textColor:  mQMLCom ? param[3]:"white"
    property int  fonesize: 10
        Rectangle{
            id:spaceline
            x:120
            y:3
            width: 2
            height: 300
            opacity:0.3
            color:"yellow"
            visible: true
        }
        QGCLabel {   //经度
            id:longitude
            x:5
            y:5
            text:                       ("经    度:"+_textlon).substring(0,maxStringLength);

            font.pointSize:     fonesize
            color:                      _textColor
            visible:                    true
         }
        QGCLabel {   //纬度
            id:latitude
            x:125
            y:5
            text:                       ("纬    度:"+_textlat).substring(0,maxStringLength);

            font.pointSize:     fonesize
            color:                      _textColor
            visible:                    true
         }
        QGCLabel {   //高度
            id:altitude
            x:5
            y:35
            text:                       ("高    度:"+_textlat).substring(0,maxStringLength);

            font.pointSize:     fonesize
            color:                      _textColor
            visible:                    true
         }
        QGCLabel {   //搜星数
            id:statenum
            x:125
            y:35
            text:                       ("搜星数  :"+_textlat).substring(0,maxStringLength);

            font.pointSize:     fonesize
            color:                      _textColor
            visible:                    true
         }

        QGCLabel {   //滚转角
            id:roll
            x:5
            y:65
            text:                       ("滚转角  :"+_textlat).substring(0,maxStringLength);

            font.pointSize:     fonesize
            color:                      _textColor
            visible:                    true
         }

        QGCLabel {   //俯仰角
            id:pitch
            x:125
            y:65
            text:                       ("俯仰角  :"+_textlat).substring(0,maxStringLength);

            font.pointSize:     fonesize
            color:                      _textColor
            visible:                    true
         }

        QGCLabel {   //航向角
            id:yaw
            x:5
            y:95
            text:                       ("航向角  :"+_textlat).substring(0,maxStringLength);

            font.pointSize:     fonesize
            color:                      _textColor
            visible:                    true
         }

        QGCLabel {   //空速
            id:skyspeed
            x:125
            y:95
            text:                       ("空    速:"+_textlat).substring(0,maxStringLength);

            font.pointSize:     fonesize
            color:                      _textColor
            visible:                    true
         }

        QGCLabel {   //电压
            id:voltage
            x:5
            y:125
            text:                       ("电    压:"+_textlat).substring(0,maxStringLength);

            font.pointSize:     fonesize
            color:                      _textColor
            visible:                    true
         }

        QGCLabel {   //高度
            id:hight
            x:125
            y:125
            text:                       ("高    度:"+_textlat).substring(0,maxStringLength);

            font.pointSize:     fonesize
            color:                      _textColor
            visible:                    true
         }




    Connections {
            target: mQMLCom;
            onSigMTIChange:{
                _textlon = mQMLCom.ReadParam[0];
                _textlat = mQMLCom.ReadParam[1];
//                console.info("onSigMTIChange------------------>"+_textlon+"   "+_textlat);
            }
        }

}
