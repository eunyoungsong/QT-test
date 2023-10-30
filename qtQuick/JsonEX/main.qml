import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 1.4  //TableViewColumn
import QtQuick.Layouts      1.2

import smMission 1.0

// 수정해야함
Window {
    width: 640
    height: 480
    visible: true

    JsonController {
        id: jsonController
    }

    ColumnLayout {
        Button {
            text:  "jsonController"
            onClicked: {
                console.log("Clicked jsonController")
            }
        }

        Button {
            text:  "open"
            onClicked: {
                console.log("Clicked open")
                jsonController.open(0)
            }
        }

        Button {
            text:  "make"
            onClicked: {
                console.log("Clicked make")
                jsonController.make()
            }
        }

        Button {
            text:  "write"
            onClicked: {
                console.log("Clicked write")
                jsonController.write()
            }
        }

        Button {
            text:  "modify"
            onClicked: {
                console.log("Clicked modify")
                jsonController.modify()
            }
        }

    }
} //window

// 출처 : https://codingcoding.tistory.com/317#google_vignette
