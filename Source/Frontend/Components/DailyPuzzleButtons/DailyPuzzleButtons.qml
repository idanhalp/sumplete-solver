import QtQuick
import QtQuick.Layouts

Row {
	id: root

	Layout.alignment: Qt.AlignHCenter
	spacing: 40

	DailyPuzzleButton {
		id: fiveOnFiveDailyPuzzleButton
		value: 5
	}

	DailyPuzzleButton {
		id: sevenOnSevenDailyPuzzleButton
		value: 7
	}
}
