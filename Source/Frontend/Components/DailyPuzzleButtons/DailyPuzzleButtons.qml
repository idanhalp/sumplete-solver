import QtQuick
import QtQuick.Layouts

Row {
	id: root

	Layout.alignment: Qt.AlignHCenter
	spacing: 40

	DailyPuzzleButton {
		id: fiveOnFiveDailyPuzzleButton

		text: "Daily 5x5"
	}

	DailyPuzzleButton {
		id: sevenOnSevenDailyPuzzleButton

		text: "Daily 7x7"
	}
}
