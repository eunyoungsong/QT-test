import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

import smMission 1.0

Window {
    width: 500
    height: 300
    visible: true
    title: qsTr("JSON TEST")

    Deviceinfo {
        id: deviceInfo
    }

    GridLayout {
        columns: 3
        anchors.horizontalCenter: parent.horizontalCenter

        Label {
            text: "Device Name: "
        }
        TextField {
            id: deviceName
        }
        Button {
            text: "Load"
            //onClicked:
        }


        Label {
            text: "Device ID: "
        }
        TextField {
            id: deviceID
        }
        Button {
            text: "Save"
            onClicked: {

            }
        }

    }
}

// 출처 : https://here4you.tistory.com/79
