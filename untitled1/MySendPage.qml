import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts
import untitled1
Item {
    id: sendPage
    required property int absWindowWidth
    required property int absWindowHeight
    //box1 variables (unfinished)
    property var pin
    property var allValues1
    property var allPorts
    property string output
    property string input
    property bool showHist
    //box2 variables
    property string repath
    property bool rehex
    property bool autoStopFrame
    property bool rescript //have no idea how this works
    property bool pause
    property int gracePeriod
    property int timeStampOrPost
    property var box2Values: [repath, rehex, autoStopFrame, rescript,
        pause, gracePeriod, timeStampOrPost]
    //box3 varaibles
    property string outPath
    property string outHex
    property bool script
    property bool intervalSend
    property int intervalVal
    property string scriptType
    property var box3Values: [outPath, outHex, script, intervalSend,
    intervalVal, scriptType]
    property string buffer

    function updateOutput(data){ //slot
        if(rehex === true){
            buffer = "" + data
            for(var i = 0; i<buffer.length; i++){
                output += buffer.charCodeAt(i).toString(16) + " "
            }
        } else {
            output += data
        }
    }

    function errorNotification(){
        notify.text = allPorts[port.index*2] + qsTr(" 正在使用")
        pop.open()
        timer1.start()
        timer2.start()
        openButton.checked = false
    }

    Connections {
        target: port
        function onReadSig(data){
            updateOutput(data)
        }
    }

    Connections {
        target: port
        function onPortSwitchError(){
            console.log("activate")
            errorNotification()
        }
    }

    PortController { //thing that will communicate with the outside port
        id: port
        index: {  //REQUIRED FOR PROGRAM TO WORK
            if(combo1.currentIndex < comCount){
                index = combo1.currentIndex
            }
        }

        onErrorChanged: {
            console.log("this is the port error code " + error)
        }

    }

    Timer { //refreshes all ports
        interval: 1000
        repeat: true
        running: true
        onTriggered: {
            var oldComCount = port.comCount
            allPorts = port.getAllPorts();  //place holder for port refresh function
            if(oldComCount != port.comCount){
                selectionModel.remove(0,oldComCount);
                if(porrt.comCount === 0){
                    selectionModel.insert(0, {name:"No Com"})
                } else {
                    console.log(allPorts)
                    for(var i = port.comCount-1; i >= 0; i--){
                        var index = allPorts[i*2]
                        selectionModel.insert(0, {name: allPorts[i*2]})
                    }
                }
            } else {
                for(var j = 0; j<oldComCount; j++){
                    selectionModel.set(j, {name: allPorts[j*2]});
                }
            }
            if(port.open === true){
                pin = port.updatePinOut()
            }
        }
    }

    //baudRate, bitRate, comCount, input, output, verify, stopNum, hardwareStream, dtr, rts
    onAllValues1Changed: {
        port.baudRate = allValues1[0]
        port.bitRate = allValues1[1]
        port.verify = allValues1[2]
        port.stopNum = allValues1[3]
        port.hardwareStream = allValues1[4]
        port.dtr = allValues1[5]
        port.rts = allValues1[6]
        //    allValues: [freq, bitNum, verify, stopNum, hardwareStream, dtr, rts]
    }

    Item {
        anchors.top: parent.top
        anchors.left: parent.left
        width: 260
        anchors.bottom: parent.bottom
        id: leftWindow
        ScrollView {
            contentHeight: 200 + 150 + 175 - 50
            anchors.fill: parent
            clip: true
            Item {
                id: box1
                width: parent.width
                anchors.top: parent.top
                anchors.topMargin: 5
                height: 175 //might change later\
                Text {
                    anchors.top: parent.top
                    text: "端口名:"
                    leftPadding: 5
                    font.pixelSize: 15
                }
                ComboBox {
                    id: combo1
                    height: 22
                    anchors.right: parent.right
                    anchors.rightMargin: 3
                    anchors.topMargin: 5
                    onCurrentIndexChanged: {
                        if(combo1.currentIndex < port.comCount){
                            port.index = combo1.currentIndex
                        }
                    }

                    model:
                        ListModel {
                            id: selectionModel

                            ListElement {
                                name: "TCP-S"
                            }
                            ListElement {
                                name: "TCP-C"
                            }
                            ListElement {
                                name: "UDP"
                            }
                            Component.onCompleted: {
                                if(port.comCount === 0){
                                    selectionModel.insert(0, {name:"No Com"})
                                } else {
                                    allPorts = port.getAllPorts()
                                     //need fix
                                    console.log(allPorts)
                                    for(var i = port.comCount-1; i >= 0; i--){
                                        var index = allPorts[i*2]
                                        selectionModel.insert(0, {name: allPorts[i*2]})
                                    }
                                }
                            }

                        }
                }
                Component {
                    id: com
                    ComPlat {
                        id: comClass
                        pinOut: pin
                        anchors.fill: parent
                        absWindowHeight: sendPage.absWindowHeight
                        absWindowWidth: sendPage.absWindowWidth
                        onAllValuesChanged: {
                            sendPage.allValues1 = allValues
                            console.log(allValues1)
                        }
                    }
                }
                Component {
                    id: tcps
                    Tcps {
                        id: tcpsClass
                        anchors.top: parent.top
                        anchors.topMargin: 25
                        anchors.bottom: parent.bottom
                    }
                }
                Component {
                    id: tcpc
                    TcpcUdp {
                        id: tcpcClass
                        anchors.fill: parent
                        anchors.topMargin: 22
                    }
                }
                Loader {
                    anchors.fill: box1
                    sourceComponent: {
                        if(combo1.currentIndex < port.comCount) {
                            com
                        } else if(combo1.currentIndex === port.comCount) {
                            tcps
                        } else if(combo1.currentIndex === 1 + port.comCount) {
                            tcpc
                        } else if(combo1.currentIndex === 2 + port.comCount) {
                            tcpc
                        }
                    }
                }
                Button {
                    id: openButton
                    anchors.bottom: parent.bottom
                    anchors.left: parent.left
                    anchors.right: parent.right
                    height: 30
                    anchors.margins: 5
                    checkable: true
                    text: {
                        if(checked === false){
                            qsTr("打开")
                        } else {
                            qsTr("关闭")
                        }
                    }
                    onClicked: {
                        if(checked === true){
                            if(combo1.currentIndex < port.comCount){
                                port.open = true
                            } else if(combo1.currentIndex === port.comCount) {
                                console.log("tcps activated")
                            } else if(combo1.currentIndex === 1 + port.comCount) {
                                console.log("tcpc activated")
                            } else if(combo1.currentIndex === 2 + port.comCount) {
                                console.log("tcpc activated")
                            }
                        }
                        if(checked === false){
                            if(combo1.currentIndex < port.comCount){
                                port.open = false
                                console.log("portClosed")
                            } else if(combo1.currentIndex === port.comCount) {
                                console.log("tcps closed")
                            } else if(combo1.currentIndex === 1 + port.comCount) {
                                console.log("tcpc closed")
                            } else if(combo1.currentIndex === 2 + port.comCount) {
                                console.log("tcpc closed")
                            }
                        }
                    }
                }
            }
            Item {
                id: box2
                anchors.top: box1.bottom
                width: parent.width
                height: 150
                Rectangle {
                    color: "transparent"
                    border.width: 1
                    border.color: "lightblue"
                    anchors.fill: parent
                    z: -1000
                }
                Text {
                    id: textBox1
                    text: qsTr("接受设置:")
                    anchors.top: parent.top
                    anchors.left: parent.left
                    anchors.topMargin: 3
                    anchors.leftMargin: 5
                    font.pixelSize: 15
                }
                Column {
                    anchors.top: textBox1.bottom
                    anchors.topMargin: 3
                    spacing: 2
                    Repeater {
                        id: rep1
                        anchors.left: parent.left
                        anchors.leftMargin: 20
                        model: [
                            "将接受保存到文件", "十六进制显示", "自动断帧", "脚本"
                        ]
                        Text {
                            anchors.left: parent.left
                            anchors.leftMargin: 30
                            required property string modelData
                            text: modelData
                            font.pixelSize: 15
                        }
                    }

                }
                Column { //box2 left 4 buttons
                    id: buttonGroup
                    anchors.top: textBox1.bottom
                    anchors.left: parent.left
                    anchors.topMargin: 5
                    anchors.leftMargin: 5
                    spacing: 2
                    Repeater {
                        id: rep2
                        model: 4
                        Button {
                            required property int index
                            height: 20
                            width: 20
                            checkable: true
                            onCheckedChanged: {
                                if(index === 0){
                                    //open path finder
                                } else if(index === 1) {
                                    rehex = checked
                                } else if(index === 2) {
                                    autoStopFrame = checked
                                } else {
                                    rescript = checked
                                }
                            }
                        }
                    }
                }
                Column {
                    anchors.bottom: parent.bottom
                    anchors.right: parent.right
                    spacing: 3
                    Button {
                        anchors.right: parent.right
                        checkable: true
                        width: 50
                        height: 50
                        text: {
                            if(checked) {
                                qsTr("run")

                            } else {
                                qsTr("paused")
                            }
                        }
                        onCheckedChanged: {
                            pause = !checked
                        }
                    }

                    Row {
                        anchors.right: parent.right
                        TextField {
                            placeholderText: "20"
                            width: 75
                            height: 25
                            font.pixelSize: 16
                            Text {
                                text: qsTr("ms")
                                color: "gray"
                                anchors.right: parent.right
                                anchors.bottom: parent.bottom
                                anchors.bottomMargin: 3
                                anchors.rightMargin: 5
                            }
                            validator: IntValidator {
                                bottom: 0
                                top: 200
                            }
                            onTextChanged: {
                                gracePeriod = parseInt(displayText)
                            }
                        }
                        Button { //activate popUp
                            id: help
                            text: "?"

                        }
                    }
                    Row {
                        ComboBox {
                            height: 22
                            model: ["Add Timestamp", "Auto PostBack"]
                            onCurrentIndexChanged: {
                                timeStampOrPost = currentIndex
                            }
                        }

                        Button {
                            id: custom
                            text: "DIY"
                        }
                    }

                    Row {
                        spacing: 25
                        anchors.right: parent.right
                        anchors.rightMargin: 60
                        anchors.bottomMargin: 10
                        bottomPadding: 5
                        Button {
                            text: "保存数据"
                        }
                        Button {
                            text:  "清空数据"
                            onClicked: {
                                output = ""
                            }
                        }
                    }
                }
            }
            Item {
                id: box3
                anchors.top: box2.bottom
                width: parent.width
                height: 145
                Text {
                    id: box3word1
                    font.pixelSize: 15
                    anchors.top: parent.top
                    anchors.left: parent.left
                    anchors.topMargin: 3
                    anchors.leftMargin: 3
                    text: qsTr("发送设置:")
                }

                Column {
                    anchors.top: box3word1.bottom
                    spacing: 3
                    anchors.topMargin: 5
                    anchors.left: parent.left
                    anchors.leftMargin: 3
                    Repeater { // box 3 left 4 buttons
                        model: 4
                        Button {
                            checkable: true
                            width: 20
                            height: 20
                            onCheckedChanged: {
                                if(index === 0){
                                    //reserve for next time
                                } else if(index === 1){
                                    outHex = checked
                                    if(checked === true){
                                        var newIn = ""
                                        for(var i = 0; i<input.length; i++){
                                            newIn += input.charCodeAt(i).toString(16) + " "
                                        }
                                        input = newIn
                                    } else {
                                        var inp = ""
                                        for(var y = 0; y<input.length; y=y+3){
                                            if(y+1 <input.length){
                                                inp += String.fromCharCode(parseInt(input.substring(y,y+2), 16))
                                            }
                                        }
                                        input = inp
                                    }
                                } else if(index === 2){
                                    script = checked
                                } else {
                                    intervalSend = checked
                                }
                            }
                        }
                    }
                }

                Column {
                    id: neededCol
                    anchors.top: box3word1.bottom
                    anchors.left: parent.left
                    anchors.leftMargin: 30
                    spacing: 3
                    anchors.topMargin: 5
                    Repeater {
                        model: ["发送文件", "十六进制发送", "脚本", "定时发送"]
                        Text {
                            required property string modelData
                            font.pixelSize: 15
                            text: modelData
                        }
                    }
                }

                Button {
                    anchors.right: parent.right
                    anchors.top: parent.top
                    anchors.rightMargin: 25
                    anchors.topMargin: 20
                    text: qsTr("扩展命令")
                    font.pixelSize: 15
                }

                Column {
                    id: helperCol2
                    anchors.bottom: neededCol.bottom
                    anchors.right: parent.right
                    anchors.rightMargin: 5
                    Row {
                        anchors.right: parent.right
                        ComboBox {
                            width: 100
                            model: ["23123", "ADD-ASCII", "ADD16", "ADD8", "CRC16_Modbus"]
                            currentIndex: 1
                            onCurrentIndexChanged: {
                                scriptType = displayText
                            }
                        }
                        Button {
                            text: qsTr("DIY")
                            width: 30
                            height: 20
                        }
                    }

                    Row {
                        anchors.right: parent.right
                        spacing: 3
                        TextField {
                            height: 20
                            placeholderText: "1.0"
                            width: 75
                            font.pixelSize: 15
                            validator: IntValidator {
                                bottom: 0
                                top: 99999999
                            }
                            onTextChanged: {
                                intervalVal = parseInt(displayText)
                            }
                        }

                        Rectangle {
                            radius: 5
                            height: 20
                            width: 20
                            Text {
                                topPadding: 2
                                leftPadding: 5
                                anchors.fill: parent
                                anchors.centerIn: parent.Center
                                text: qsTr("秒")
                            }
                        }
                    }
                }
                Button {
                    id: lastButton
                    anchors.bottom: parent.bottom
                    anchors.left: parent.left
                    anchors.leftMargin: 3
                    anchors.bottomMargin: 6
                    width: 20
                    height: 20
                    checkable: true
                    onCheckedChanged: {
                        showHist = checked
                    }
                }

                Text {
                    id: lastWord
                    anchors.left: lastButton.right
                    anchors.top: lastButton.top
                    anchors.leftMargin: 7
                    text: "显示发送字符串"
                    font.pixelSize: 15
                }




            }

        }
    }
    Item {
        anchors.left: leftWindow.right
        height: parent.height
        anchors.right: parent.right
        ScrollView {
            id: topBox
            width: parent.width
            height: parent.height/1.5
            ScrollBar.horizontal.policy: ScrollBar.AlwaysOff
            clip: true
            contentWidth: parent.width
            TextEdit {
                id: topText
                textFormat: TextEdit.PlainText
                height: parent.height
                width: parent.width
                anchors.topMargin: 3
                anchors.leftMargin: 3
                anchors.rightMargin: 5
                // wrapMode: TextEdit.WordWrap
                wrapMode: Text.Wrap
                selectByMouse: true
                selectionColor: "lightblue"
                anchors.fill: parent
                font.pixelSize: 20
                font.family: "Arial"
                color: "black"
                onTextChanged: {
                    output = text
                }
            }
            background: Rectangle {
                anchors.rightMargin: 2
                anchors.fill: parent
                border.color: "gray"
                border.width: 1
                radius: 4
            }
        }
        ScrollView {
            id: botBox
            anchors.top: topBox.bottom
            height: parent.height/1.5
            ScrollBar.horizontal.policy: ScrollBar.AlwaysOff
            clip: true
            contentWidth: parent.width - 100
            TextEdit {
                id: inputBox
                textFormat: TextEdit.PlainText
                height: parent.height
                width: parent.width
                anchors.topMargin: 3
                anchors.leftMargin: 3
                anchors.rightMargin: 5
                // wrapMode: TextEdit.WordWrap
                wrapMode: Text.Wrap
                selectByMouse: true
                selectionColor: "lightblue"
                anchors.fill: parent
                font.pixelSize: 20
                font.family: "Arial"
                color: "black"
                onTextChanged: {
                    input = text
                }
            }
            background: Rectangle {
                anchors.rightMargin: 2
                anchors.fill: parent
                border.color: "gray"
                border.width: 1
                radius: 4
            }
        }
        Button {
            id: sendBox
            anchors.left: botBox.right
            anchors.right: parent.right
            width: 100
            anchors.bottom: parent.bottom
            anchors.top: botBox.top
            y: botBox.y
            x: botBox.x + botBox.width
            text: "send"
            onClicked: {
                //way to send the stuff
                if(port.open === true){
                    if(showHist === true){
                        output += ">> " + input + '\n'
                    }
                    port.write(input)
                } else {
                    notify.text = qsTr("端口未打开！")
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
            x: parent.width/2-75
            y: parent.height/2 - 75
            closePolicy: Popup.NoAutoClose
            width: 150
            height: 75
            background: Rectangle {
                radius: 5
                anchors.fill: parent
                color: "lightsteelblue"
            }
            Text {
                id: notify
                anchors.fill: parent
                horizontalAlignment: parent.width/2
                anchors.top: parent.top
                anchors.topMargin: parent.height/3.2
                text: qsTr("端口未打开！")
            }

        }
    }
    onInputChanged: {
        inputBox.text = input
    }
    onOutputChanged: {
        topText.text = output
    }
}
