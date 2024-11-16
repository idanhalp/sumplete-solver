// pragma ComponentBehavior: Bound

import QtQuick 6.5
import QtQuick.Controls

ListView {
	id: root

	interactive: false
	orientation: ListView.Horizontal
	model: mainModule.size

	delegate: Rectangle {
		width: root.width / mainModule.size
		height: root.height

		color: "white"
		border.color: "black"

		TextField {
			anchors.centerIn: parent

			font.pixelSize: 25

			background: Rectangle {
				color: "transparent"
			}

			onTextChanged: {
				mainModule.update_col_sum(index, text)
			}

			validator: IntValidator {
				bottom: -99
				top:    +99
			}
		}
	}
}
