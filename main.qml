import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts 

import "." as App

ApplicationWindow {
    id: window
//    width: 360
//    height: 520
    width: 480
    height: 854
//    width: 720
//    height: 1280
    visible: true
    title: qsTr("Quick Flow")

    Action {
        id: optionsMenuAction
        icon.source: "qrc:/img/param.svg"
        onTriggered: optionsMenu.open()
    }

    Action {
        id: navigateBackAction
        icon.source: "qrc:/img/menu.svg"
        onTriggered:drawer.open()
    }

    header: ToolBar{
        RowLayout {
            spacing: 20
            anchors.fill: parent

            ToolButton {
                action: navigateBackAction
            }

            Label {
                id: titleLabel
                text: "Quick Flow"
                color: "white"
                font.pixelSize: 20
                elide: Label.ElideRight
                horizontalAlignment: Qt.AlignHCenter
                verticalAlignment: Qt.AlignVCenter
                Layout.fillWidth: true
            }

            ToolButton {
                action: optionsMenuAction

                Menu {
                    id: optionsMenu
                    x: parent.width - width
                    transformOrigin: Menu.TopRight

                    Action {
                        text: "Settings"
                        //onTriggered: settingsDialog.open()
                        onTriggered: loader.source ="home.qml"
                    }
                    Action {
                        text: "Help"
                        //onTriggered: help()
                        onTriggered: loader.source ="aboutDialog.qml"
                    }
                    Action {
                        text: "About"
                        onTriggered: {about.open(); /*loader.source = "editrestapi.qml";*/}

                    }
                }
            }
        }
    }

//    ColumnLayout {
//        spacing: 0
//        anchors.margins: 0
//        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
//        height: parent.height/6
//        width: parent.width

//        Button {
//            Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter
//            anchors.margins: 4
//            text: "Test"
//            //onClicked: test()
//            onClicked:
//            {
//                //test()
//                label.text = myObject.getResult()
//            }
//        }

//        Text {
//            id: label
//            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
//            text: "Ready"
//        }
//    }


//    // utiliser loader plutot
//    StackView {
//        id: stackView
//        initialItem: page
//                spacing: 0
//                anchors.margins: 0
//                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
//                height: parent.height/6
//                width: parent.width

//        Component {
//            id: page

//            Pane {
//                id: pane
//                width: parent

//                Column {
//                    spacing: 40
//                    width: parent.width

//                    Label {
//                        width: parent.width
//                        wrapMode: Label.Wrap
//                        horizontalAlignment: Qt.AlignHCenter
//                        text: "StackView provides a stack-based navigation model which can be used with a set of interlinked pages. "
//                        + "Items are pushed onto the stack as the user navigates deeper into the material, and popped off again "
//                        + "when he chooses to go back."
//                    }

//                    Button {
//                        id: button
//                        text: "Push"
//                        anchors.horizontalCenter: parent.horizontalCenter
//                        width: Math.max(button.implicitWidth, Math.min(button.implicitWidth * 2, pane.availableWidth / 3))
//                        onClicked: stackView.push(page)
//                    }

//                    Button {
//                        text: "Pop"
//                        enabled: stackView.depth > 1
//                        width: Math.max(button.implicitWidth, Math.min(button.implicitWidth * 2, pane.availableWidth / 3))
//                        anchors.horizontalCenter: parent.horizontalCenter
//                        onClicked: stackView.pop()
//                    }
//                }
//            }
//        }
//    }

    Loader {
      id: loader
      anchors.fill: parent
      source: "home.qml"
    }

    Drawer {
        id: drawer
        width: Math.min(window.width, window.height) / 3 * 2
        height: window.height
        //interactive: stackView.depth === 1

        ListView {
            id: listView
            focus: true
            currentIndex: -1
            anchors.fill: parent

//            headerPositioning: ListView.OverlayHeader
//            header: Pane {
//                id: header
//                z: 2
//                width: parent.width

//                contentHeight: logo.height

//                Image {
//                    id: logo
//                    width: parent.width
//                    source: "qrc:/img/logo_transparent.png"
//                    fillMode: implicitWidth > width ? Image.PreserveAspectFit : Image.Pad
//                }

//                MenuSeparator {
//                    parent: header
//                    width: parent.width
//                    anchors.verticalCenter: parent.bottom
//                    visible: !listView.atYBeginning
//                }
//            }


            delegate: ItemDelegate {
                width: listView.width
                text: modelData.name
                highlighted: ListView.isCurrentItem
                onClicked: {
                    listView.currentIndex = index
                    //stackView.push(model.source)
                    loader.source = "home.qml"
                    drawer.close()
                }
            }

//            model: ListModel {
//                ListElement { title: "twitter search"; source: "twitter.json" }
//                ListElement { title: "meteo lyon"; source: "test.json" }
//                ListElement { title: "bookmarks"; source: "test.json" }
//                ListElement { title: "google news"; source: "test.json" }
//                ListElement { title: "bitcoin"; source: "test.json" }
//                ListElement { title: "twitter Elon Musk"; source: "test.json" }
//                ListElement { title: "tv Show Schedule"; source: "test.json" }
//                ListElement { title: "euro to dollard"; source: "test.json" }
//            }
            model: quickFlowModel.flows
            ScrollIndicator.vertical: ScrollIndicator { }
        }
    }

    AboutDialog{
        id: about
    }

}
