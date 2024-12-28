import QtQuick
import QtQuick.Controls
import "GetPuzzle.js" as GetPuzzle

Button {
	required property int value // The size of the daly puzzle grid.

	id: root

	width: 150
	height: 50

	Text {
		id: text

		anchors.centerIn: parent

		text: `Daily ${value}x${value}`
	}

	onClicked: {
		GetPuzzle.loadDailyPuzzle(value);
		gridSizeDropdown.currentIndex = gridSizeDropdown.indexOfValue(value);
	}
}
