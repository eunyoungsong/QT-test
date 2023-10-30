import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: 640
    height: 480
    visible: true
    //title: qsTr("images Test")

    Image {
        id: root
        source: "background.png"

        Image {
                id: pole
                source: "pole.png"
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottom: parent.bottom
            }

        Image {
            id: wheel
            source: "pinwheel.png"
            anchors.centerIn: parent
            Behavior on rotation {
                NumberAnimation {
                    duration: 250
                }
            }
        }

        MouseArea {
            anchors.fill: parent
            onClicked: wheel.rotation += 90
        }
    }


}
