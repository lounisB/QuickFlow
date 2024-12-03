import QtQuick 2.0
import QtQuick.Layouts
import QtQuick.Controls

Dialog {
    id: aboutDialog
    modal: true
    focus: true
    //title: "About"
    x: (window.width - width) / 2
    y: (window.height - height) / 4
    width: Math.min(window.width, window.height) /  1.5
    contentHeight: aboutColumn.height

    Column {
        id: aboutColumn
        spacing: 20

        Image{
            width: aboutDialog.availableWidth
            source: "qrc:/img/logo.ico"
            fillMode: Image.PreserveAspectFit
        }

        Text {
            width: aboutDialog.availableWidth
            text: "QuickFlow\nBy Space Monkey Software"
            horizontalAlignment: Text.AlignHCenter
            wrapMode: Label.Wrap
            font.pixelSize: 12
        }

        Text {
            width: aboutDialog.availableWidth
            text: "Only web data"
            horizontalAlignment: Text.AlignHCenter
            wrapMode: Label.Wrap
            font.pixelSize: 12
        }
    }
}


