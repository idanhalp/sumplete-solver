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

	Row {
		id: solveButtonAndSizeDropdown

		anchors {
			horizontalCenter: grid.horizontalCenter
			top: grid.bottom
			topMargin: 20
		}

		spacing: 20

		GridSizeDropdown {
			id: gridSizeDropdown
		}

		SolveButton {
			id: solveButton
		}
	}
}
