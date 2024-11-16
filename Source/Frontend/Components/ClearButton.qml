import QtQuick 6.5
import QtQuick.Controls

Button {
	id: root

	width: 150
	height: 50

	Text {
		id: text

		anchors.centerIn: parent

		text: "clear"
		color: "black"
	}

	onClicked: mainModule.clear()
}
