import QtQuick 2.9
import QtQuick.Controls 2.2

ApplicationWindow {
    id: window
    width: 360
    height: 360
    visible: true

    ListView {
        id: listView
        anchors.fill: parent

        contentWidth: headerItem.width
        flickableDirection: Flickable.HorizontalAndVerticalFlick

        header: Row {
            spacing: 1
            function itemAt(index) { return repeater.itemAt(index) }
            Repeater {
                id: repeater
                model: ["Quisque", "Posuere", "Curabitur", "Vehicula", "Proin"]
                Label {
                    text: modelData
                    font.bold: true
                    font.pixelSize: 20
                    padding: 10
                    background: Rectangle { color: "silver" }
                }
            }
        }

        model: 100
        delegate: Column {
            id: delegate
            property int row: index
            Row {
                spacing: 1
                Repeater {
                    model: 5
                    ItemDelegate {
                        property int column: index
                        text: qsTr("%1x%2").arg(delegate.row).arg(column)
                        width: listView.headerItem.itemAt(column).width
                    }
                }
            }
            Rectangle {
                color: "silver"
                width: parent.width
                height: 1
            }
        }

        ScrollIndicator.horizontal: ScrollIndicator { }
        ScrollIndicator.vertical: ScrollIndicator { }
    }
}
