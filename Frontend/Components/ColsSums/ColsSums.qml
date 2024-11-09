// pragma ComponentBehavior: Bound

import QtQuick 6.5

ListView {
	id: root

	orientation: ListView.Vertical
	model: ["1", "2", "3", "4"]

	delegate: Rectangle {
		width: root.width
		height: root.height / root.model.length
		Text {
			anchors.centerIn: parent
			text: modelData
			font.pixelSize: 35
		}
	}
}
