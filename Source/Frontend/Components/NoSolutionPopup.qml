import QtQuick
import QtQuick.Controls

Popup {
	id: root

	width: 300
	height: 250

	closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside

	Rectangle {
		width: parent.width
		height: parent.height
		color: "#FFFFC5" // light yellow
		border.color: "black"

		Text {
			text: "NO SOLUTION!"
			anchors.centerIn: parent

			font {
				bold: true
				pixelSize: 30
			}
		}
	}
}
