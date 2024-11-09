// pragma ComponentBehavior: Bound

import QtQuick 6.5

ListView {
	id: root

	interactive: false
	orientation: ListView.Horizontal
	model: ["1", "2", "3", "4"]

	delegate: Rectangle {
		width: root.width / root.model.length
		height: root.height

		Text {
			anchors.centerIn: parent
			text: modelData
			font.pixelSize: 35
		}
	}
}
