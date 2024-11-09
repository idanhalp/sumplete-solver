import QtQuick
import "Components/Grid"
import "Components/GridSizeDropdown"
import "Components/SolveButton"

Window {
	id: root

	title: qsTr("Sumplete solver")
	width: 640
	height: 480
	visible: true

	Grid {
		id: grid
		anchors.centerIn: parent
		measurements: 400
		size: 3
	}

	SolveButton {
		id: solveButton

		anchors {
			top: grid.bottom
			horizontalCenter: grid.horizontalCenter
			topMargin: 10
		}
	}

	GridSizeDropdown {
		id: gridSizeDropdown

		anchors {
			verticalCenter: solveButton.verticalCenter
			right: solveButton.left
			rightMargin: 10
		}
	}
}
