// pragma ComponentBehavior: Bound

import QtQuick 6.5
import QtQuick.Controls

ListView {
	id: root

	interactive: false
	orientation: ListView.Vertical
	model: mainModule.size

	delegate: Rectangle {
		width: root.width
		height: root.height / mainModule.size

		color: "white"
		border.color: "black"

		TextField {
			anchors.centerIn: parent

			font.pixelSize: 25

			background: Rectangle {
				color: "transparent"
			}
		}
	}
}
