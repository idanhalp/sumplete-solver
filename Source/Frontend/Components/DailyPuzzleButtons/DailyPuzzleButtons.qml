import QtQuick
import QtQuick.Layouts
import "GetPuzzle.js" as GetPuzzle

Row {
	id: root

	Layout.alignment: Qt.AlignHCenter
	spacing: 40

	DailyPuzzleButton {
		id: fiveOnFiveDailyPuzzleButton

		text: "Daily 5x5"

		onClicked: GetPuzzle.getDailyPuzzle(5)
	}

	DailyPuzzleButton {
		id: sevenOnSevenDailyPuzzleButton

		text: "Daily 7x7"

		onClicked: GetPuzzle.getDailyPuzzle(7)
	}
}
