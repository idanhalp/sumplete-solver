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
		color: "red"
		border.color: "black"

		Text {
			text: "Input is incomplete!"
			anchors.centerIn: parent

			font {
				bold: true
				pixelSize: 30
			}
		}
	}
}
