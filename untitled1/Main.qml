import QtQuick
import QtQuick.Window
import QtQuick.Controls
ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("串口调试助手")
    menuBar: TabBar {
        id: tab
        TabButton {
            text: qsTr("send")
        }
        TabButton {
            text: qsTr("graph")
        }
        TabButton {
            text: qsTr("pre")
        }
        TabButton {
            text: qsTr("help")
        }
        TabButton {
            text: qsTr("about")
        }
    }
    SwipeView {
        interactive: false
        id: swipe
        anchors.fill: parent
        currentIndex: tab.currentIndex

        MySendPage {
            absWindowWidth: parent.width
            absWindowHeight: parent.height
        }

        MyGraphPage {

        }

        MyPrePage {

        }

        MyHelpPage {

        }

        MyAboutPage {

        }
    }
}
