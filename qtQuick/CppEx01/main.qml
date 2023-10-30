import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Dialogs 1.2
import QtQuick.Controls.Styles 1.4

import sm.qtproject.test 1.0

Window {
    id: window
    visible: true
    width: 640
    height: 480

    //property DocumentHandler backend: DocumentHandler{}

    DocumentHandler {
        id: document
        //target: textArea
        //cursorPosition: textArea.cursorPosition
        //selectionStart: textArea.selectionStart
        //selectionEnd: textArea.selectionEnd
        //textColor: colorDialog.color
        Component.onCompleted: document.fileUrl = "/home/eunyoung/.config/smMission/cppEx01.json";
        onError: {
            errorDialog.text = message
            errorDialog.visible = true
        }
    }

    FileDialog{
        id: fileDialog
        nameFilters: ["Text files (*.txt)", "HTML files (*.html, *.htm)"]
        onAccepted: {
            if (fileDialog.selectExisting)
                document.fileUrl = fileUrl
            else
                document.saveAs(fileUrl, selectedNameFilter)
        }
    }

    Column {
        anchors.fill: parent

        Row {
            id: buttons
            anchors.horizontalCenter: parent.horizontalCenter
            Button {
                id: open
                text: qsTr("Open")
                onClicked: {
                    fileDialog.selectExisting = false
                    fileDialog.open()
                }
            }
            Button {
                id: save
                text: qsTr("Save")
                onClicked: {
                    fileDialog.selectExisting = false
                    fileDialog.open()
                }
            }
        }

        ScrollView {
            id: view
            contentHeight: Window.height - buttons.height
            contentWidth: parent.width

            TextArea {
                id: textArea
                //width: parent.width
                //anchors.top: secondaryToolBar.bottom
                //anchors.bottom: parent.bottom
                baseUrl: "qrc:/"
                text: document.text
                Accessible.name: "document"
                selectByMouse: true
                Component.onCompleted: forceActiveFocus()
            }
        }


    } // Column
}
