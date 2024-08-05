import QtQuick
import QtQuick.Window
import QtQuick.Controls
import untitled1
Item {
    id: comPlat
    required property int absWindowHeight
    required property int absWindowWidth
    property var pinOut
    pinOut: 0
    property int freq
    property int bitNum
    property int verify
    property int stopNum
    property bool hardwareStream
    property bool dtr
    property bool rts
    property var allValues
    allValues: [freq, bitNum, verify, stopNum, hardwareStream, dtr, rts]
    anchors.fill: parent
    Repeater {  //for 端口名 window
        anchors.fill: parent
        model: ["波特率:", "数据位:", "校验位:", "停止位:"]
        Text {
            required property string modelData
            required property int index
            text: modelData
            leftPadding: 5
            font.pixelSize: 15
            y: 115/5*(index+1)
        }
    }
    Component {
        id: freqCombo
        ComboBox {
            id: bitRate
            model: [300, 600, 1200, 2400, 4800, 9600, 14400, 19200, 38400, 56000, 57600, 115200, 128000, 256000, 460800]
            y: 115/5 + 2
            anchors.right: parent.right
            anchors.rightMargin: 3
            anchors.topMargin: 5
            currentIndex: 6
            onCurrentTextChanged: {
                if(freqButton.checked === false){
                    freq = currentText
                }
            }
        }
    }

    Button {
        id: freqButton
        y: 115/5
        anchors.right: parent.right
        anchors.rightMargin: 95
        width: 20
        height: freqCombo.height
        checkable: true
        onCheckedChanged: {
            if(checked === false){
                freqLoader.sourceComponent = freqCombo
            } else {
                freqLoader.sourceComponent = freqComponent
            }
        }
    }

    Loader {
        id: freqLoader
        anchors.right: parent.right
        sourceComponent: freqCombo
    }

    Component {
        id: freqComponent
        TextField {
            y:115/5+2
            width: 91
            height: freqCombo.height
            anchors.right: parent.right
            anchors.rightMargin: 2
            validator: IntValidator {
                bottom: 0
            }
            onTextChanged: {
                if(freqButton.checked === true){
                    freq = parseInt(displayText)
                }
            }
        }
    }

    ComboBox {
        id: bitNumBox
        model: [5, 6, 7, 8]
        y: 2*115/5
        anchors.right: parent.right
        currentIndex: 3
        anchors.rightMargin: 3
        onCurrentTextChanged: {
            bitNum =  parseInt(currentText)
        }
    }
    ComboBox {
        id: verifyBox
        model: ["none", "even", "mark", "odd"]
        y: 3*115/5
        anchors.right: parent.right
        anchors.rightMargin: 3
        onCurrentIndexChanged: {
            verify = currentIndex
        }
    }
    ComboBox {
        id: stopBox
        model: [1, 1.5, 2]
        y: 4*115/5
        anchors.right: parent.right
        anchors.rightMargin: 3
        onCurrentTextChanged: {
            stopNum = currentText
        }
    }
    Row {
        id: row
        anchors.fill: parent
        anchors.top: parent.top
        anchors.topMargin: 115
        anchors.left: parent.left
        spacing: 3
        anchors.leftMargin: 5
        Button {
            id: specialButton
            checkable: true
            width: 30
            onCheckedChanged: {
                if(checked === false){
                    hardwareStream = false
                    rep.itemAt(4).checked = false
                    pop.open()
                    timer1.start()
                    timer2.start()
                } else {
                    hardwareStream = true
                    rep.itemAt(4).checked = true
                    pop.open()
                    timer1.start()
                    timer2.start()
                }
            }
        }

        Timer {
            id: timer2
            interval: 2000
            onTriggered: {
                opacityAni.start()
                timer2.stop()
            }
        }

        Timer {
            id: timer1
            interval: 1000
            triggeredOnStart: true
            onTriggered: {
                open.start()
                timer1.stop()
            }
        }

        NumberAnimation {
            id: opacityAni
            target: pop
            properties: "opacity"
            from: 1
            to: 0
            duration: 1000
        }

        NumberAnimation {
            id: open
            target: pop
            properties: "opacity"
            from: 0
            to: 1
            duration: 1000
        }


        Popup {
            required property string displayText
            displayText: ""
            visible: false
            id: pop
            topMargin: comPlat.absWindowHeight/2.5
            leftMargin: comPlat.absWindowWidth/13
            closePolicy: Popup.NoAutoClose
            width: 150
            height: 75
            background: Rectangle {
                radius: 5
                anchors.fill: parent
                color: "lightsteelblue"
            }
            Text {
                anchors.fill: parent
                horizontalAlignment: parent.width/2
                anchors.top: parent.top
                anchors.topMargin: parent.height/3.2
                text: {
                    if(specialButton.checked === false){
                        "已禁用硬件流控制"
                    } else {
                        "已启用硬件流控制"
                    }
                }
            }

        }

        Repeater {
            id: rep
            model: ["RI", "DSR", "CTS", "DTR", "RTS"]
            Button {
                required property string modelData
                required property int index
                checkable: true
                text: modelData
                width: 40
                onCheckedChanged: {
                    if(index === 3) {
                        dtr = checked
                    } else if(index === 4) {
                        rts = checked
                    }
                }   
            }
        }

    }

    onPinOutChanged: {
        if(pinOut !== 0){
            for(var i = 0; i<pinOut.length; i++){
                rep.itemAt(i).checked = pinOut[i]
            }
        }
    }
}

