// pragma ComponentBehavior: Bound

import QtQuick 6.5

ListView {
	id: root

	interactive: false
	orientation: ListView.Horizontal
	model: mainModule.size

	delegate: Rectangle {
		width: root.width / mainModule.size
		height: root.height

		Text {
			anchors.centerIn: parent
			text: modelData
			font.pixelSize: 35
		}
	}
}
