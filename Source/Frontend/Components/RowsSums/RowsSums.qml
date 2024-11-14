// pragma ComponentBehavior: Bound

import QtQuick
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

			onTextChanged: {
				mainModule.update_row_sum(index, text)
			}

			validator: IntValidator {
				bottom: -99
				top:    +99
			}
		}
	}
}
