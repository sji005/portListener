import QtQuick
import QtQuick.Window
import QtQuick.Controls
Item {
    id: tcpsClass
    signal tcpsForm(string localIp, int port, bool checkBox, bool all, bool IP)
    Connections {
        target: tcpsClass
        function onTcpsForm(localIp, port, checkBox, all, IP) {
            console.log(localIp + " " + port + " " + checkBox + " " + all + " " + IP)
        }
    }

    Rectangle {
        border.width: 1
        border.color: "lightblue"
        anchors.fill: parent
        color: "transparent"    
    }
    Text {
        id: ip
        anchors.top: parent.top
        anchors.topMargin: 3
        font.pixelSize: 15
        anchors.left: parent.left
        anchors.leftMargin: 5
        text: qsTr("本地IP")
    }

    Text {
        id: port
        anchors.top: parent.top
        anchors.topMargin: 3
        anchors.right: parent.right
        anchors.rightMargin: 50
        font.pixelSize: 15
        text: qsTr("端口")
    }

    ComboBox {
        id: combo
        editable: true
        model: ["127.0.0.1", "192.168.1.98"]
        anchors.top: ip.bottom
        currentIndex: -1
        anchors.left: ip.left
        height: 25
        anchors.right: port.left
        anchors.rightMargin: 5
    }

    TextField {
        id: textF
        anchors.top: port.bottom
        anchors.left: port.left
        anchors.bottom: combo.bottom
        anchors.right: parent.right
        anchors.rightMargin: 5
        verticalAlignment: Text.AlignVCenter
        background: Rectangle {
            id: txtFieldBack
            anchors.fill: parent
            color: "white"
            border.color: "gray"
            border.width: 1
        }
        onFocusChanged:  {
            if(focus === true) {
                txtFieldBack.border.color = "lightsteelblue"
            } else {
                txtFieldBack.border.color = "gray"
            }
        }
    }
    Text {
        anchors.left: parent.left
        anchors.top: textF.bottom
        text: qsTr("客户端")
        font.pixelSize: 15
        anchors.leftMargin: 5
    }

    Row {
        anchors.right: parent.right
        anchors.top: textF.bottom
        anchors.rightMargin: 5
        anchors.topMargin: 5
        spacing: 2
        Repeater {
            model: [" ", "all", "IP"]

            Button {
                required property string modelData
                checkable: true
                text: modelData
                width: 35
            }
        }
    }



}
