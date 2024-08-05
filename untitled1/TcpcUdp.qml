import QtQuick
import QtQuick.Window
import QtQuick.Controls
Item {
    //端口, 本地IP
    id: tcpcClass
    signal tcpcForm(string destIp, int destPort, string localPort, string localPort)

    Connections {
        target: tcpcClass
        function onTcpcForm(destIp, destPort, localIp, localPort){
            console.log(destIp, + " " + destPort + " " + localIp + " " + localPort)
        }
    }

    Rectangle {
        anchors.fill: parent
        color: "transparent"
        border.color: "blue"
        border.width: 1
    }
    Column {
        id: col1
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.leftMargin: 5
        anchors.topMargin: 5
        spacing: 25
        Text {
            id: ip
            font.pixelSize: 15
            text: qsTr("远端IP")
        }
        Text {
            id: localIp
            font.pixelSize: 15
            text: qsTr("本地IP")
        }

    }
    Column {
        id: col2
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.topMargin: 5
        anchors.rightMargin: 40
        spacing: 25
        Text {
            id: port
            text: qsTr("端口")
            font.pixelSize: 15
        }
        Text {
            id: port2
            text: qsTr("端口")
            font.pixelSize: 15
        }
    }

    ComboBox { //本地ip
        id: combo
        editable: true
        model: ["127.0.0.1", "192.168.1.98"]
        anchors.top: col1.bottom
        currentIndex: -1
        anchors.left: col1.left
        height: 25
        anchors.right: col2.left
        anchors.rightMargin: 5
    }

    TextField { //本地port
        anchors.right: parent.right
        anchors.left: combo.right
        anchors.top: col2.bottom
        anchors.bottom: combo.bottom
        anchors.rightMargin: 3
        background: Rectangle {
            id: txtFieldBack
            anchors.fill: parent
            color: "white"
            border.width: 1
            border.color: "gray"
        }
        onFocusChanged:  {
            if(focus === true) {
                txtFieldBack.border.color = "lightsteelblue"
            } else {
                txtFieldBack.border.color = "gray"
            }
        }
    }

    ComboBox { //远程ip
        id: combo1
        editable: true
        currentIndex: -1
        model: ["127.0.0.1", "192.168.1.98"]
        anchors.top: parent.top
        anchors.topMargin: 23
        anchors.left: parent.left
        anchors.leftMargin: 5
        height: 25
        anchors.right: col2.left
        anchors.rightMargin: 5
    }

    TextField { //远程text
        anchors.right: parent.right
        anchors.left: combo1.right
        anchors.top: combo1.top
        anchors.bottom: combo1.bottom
        anchors.rightMargin: 3
        background: Rectangle {
            id: txtFieldBack1
            anchors.fill: parent
            color: "white"
            border.width: 1
            border.color: "gray"
        }
        onFocusChanged:  {
            if(focus === true) {
                txtFieldBack1.border.color = "lightsteelblue"
            } else {
                txtFieldBack1.border.color = "gray"
            }
        }
    }


}
