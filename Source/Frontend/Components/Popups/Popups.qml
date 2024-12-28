import QtQuick

Item {

	property alias errorPopup: errorPopup
	property alias incompleteInputPopup: incompleteInputPopup
	property alias loadingPopup: loadingPopup
	property alias noSolutionPopup: noSolutionPopup

	ErrorPopup {
		id: errorPopup

		anchors.centerIn: parent
	}

	IncompleteInputPopup {
		id: incompleteInputPopup

		anchors.centerIn: parent
	}

	LoadingPopup {
		id: loadingPopup

		anchors.centerIn: parent
	}

	NoSolutionPopup {
		id: noSolutionPopup

		anchors.centerIn: parent
	}
}
