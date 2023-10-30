import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        id: rectangle
        color: "#94c5f6"
        anchors.fill: parent

        Column {
            id: column
            x: 220
            y: 40
            width: 200
            height: 400
            spacing: 15

            Text {
                id: text1
                text: qsTr("text")
                font.pixelSize: 12
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Button {
                id: button
                text: qsTr("Button")
                display: AbstractButton.TextOnly
                anchors.horizontalCenter: parent.horizontalCenter

                onClicked: {
                    text1.text = "HelloWorld"
                }
            }
        }
    }
}
