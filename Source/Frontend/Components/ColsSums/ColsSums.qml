// pragma ComponentBehavior: Bound

import QtQuick 6.5

ListView {
	id: root

	interactive: false
	orientation: ListView.Vertical
	model: mainModule.size

	delegate: Rectangle {
		width: root.width
		height: root.height / mainModule.size
		Text {
			anchors.centerIn: parent
			text: modelData
			font.pixelSize: 35
		}
	}
}
