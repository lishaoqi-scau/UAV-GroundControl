import QtQuick 2.5

ListView {
    id: list_area
    anchors.fill: parent
    orientation : ListView.Vertical
    ScrollBar.vertical: ScrollBar {
        id: scrollBar
        onActiveChanged: {
            active = true;
        }
        Component.onCompleted: {
            scrollBar.handle.color = "#686A70";
            scrollBar.active = true;
            scrollBar.handle.width = 10;
        }
    }
}
