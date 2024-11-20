import QtQuick

Item {

	property alias noSolutionPopup: noSolutionPopup
	property alias incompleteInputPopup: incompleteInputPopup

	NoSolutionPopup {
		id: noSolutionPopup

		anchors.centerIn: parent
	}

	IncompleteInputPopup {
		id: incompleteInputPopup

		anchors.centerIn: parent
	}
}
