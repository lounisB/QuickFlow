import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    ListView {
        id: listView

        anchors.fill: parent

//        model: ListModel {
//            id: listmodel
//            ListElement {
//                name: "Bitcoin"
//                value: "45801"
//                update: true
//            }
//            ListElement {
//                name: "Meteo Lyon"
//                value: "28° sunny"
//                update: false
//            }
//            ListElement {
//                name: "Info"
//                value: "Information"
//                update: true
//                //value: "texte très très très très très très très très très très très très très très très long"
//            }
//            ListElement {
//                name: "Bitcoin"
//                value: "49551"
//                update: true
//            }
//            ListElement {
//                name: "Meteo Lyon"
//                value: "28° sunny"
//                update: false
//            }
//            ListElement {
//                name: "Info"
//                value: "Information"
//                update: true
//            }
//            ListElement {
//                name: "Bitcoin"
//                value: "49551"
//                update: true
//            }
//            ListElement {
//                name: "Meteo Lyon"
//                value: "28° sunny"
//                update: false
//            }
//            ListElement {
//                name: "Info"
//                value: "Information"
//                update: true
//            }
//        }
        model : quickFlowModel.flows
        delegate:
            ItemDelegate {
                id: root
                width: parent.width
                checkable: true

                onClicked: ListView.view.currentIndex = index

                contentItem: ColumnLayout {
                    spacing: 0

                    RowLayout {
                        id: rowLayout
                        spacing: 0
                        ColumnLayout {
                            id: columnLayout
                            spacing: 2
                            Text {
                                id: text1
                                text: modelData.name
                                Layout.maximumWidth: window.width  - switch1.width - 10
                                font.pixelSize: Qt.application.font.pixelSize * 1
                                font.bold: true
                                width: 10
                            }
                            Text {
                                id: text2
                                text: modelData.name
                                Layout.maximumWidth: window.width  - switch1.width - 10
                                wrapMode : Label.Wrap
                            }
//                            Label {
//                                id: lblMsg
//                                text: "ajks dlld jklasdasda sdas dasd asda sda sdasd asdasdas dasdasdasd"
//                                Layout.maximumWidth: window.width  - switch1.width - 10
//                                wrapMode: Label.WordWrap
//                            }
                            Text {
                                id: text3
//                                text: model.variables["test1"]
                                text: modelData.variables[0].name
                                Layout.maximumWidth: window.width  - switch1.width - 10
                                wrapMode : Label.Wrap
                            }
                            Repeater{
                                model: modelData.variables
                                Text {
                                    Layout.maximumWidth: window.width  - switch1.width - 10
                                    wrapMode : Label.Wrap
                                    text: modelData.name + " " + modelData.value
                                }
                            }
                            Repeater{
                                model: modelData.restRequests
                                Repeater{
                                    model: modelData.results
                                    Text {
                                        Layout.maximumWidth: window.width  - switch1.width - 10
                                        wrapMode : Label.Wrap
                                        text: modelData.name + " " + modelData.value
                                    }
                                }

                            }
                            Button {
                                text: "Update"
                                onClicked: {
                                    //modelData.variables[0].name = "aaa";
                                    //modelData.name = "nouveau"
                                    modelData.testSlot(5);
                                }
                            }
                            Image {
                                id: image
                                source: "qrc:/img/logo.ico"
                                Layout.preferredWidth: 150
                                Layout.preferredHeight: 150
                                fillMode: Image.PreserveAspectFit
                            }
                        }
                        Item {
                            id: item1
                            Layout.fillWidth: true
                        }
                        Switch {
                            id: switch1
                            checked: modelData.enable
                            Layout.alignment: Qt.AlignTop
                            onClicked: {modelData.enable = checked}
                            //onClicked: {modelData.testSlot(5)}
                        }
                    }

                }
            }

    }

    RoundButton {
        id: addFlow
        text: "+"
        anchors.bottom: listView.bottom
        anchors.bottomMargin: 8
        anchors.horizontalCenter: parent.horizontalCenter
//        anchors.margins: 10
//        anchors.right: parent.right
//        anchors.bottom: parent.bottom
        onClicked: addFlow.open()
    }
}
