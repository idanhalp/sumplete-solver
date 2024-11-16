import QtQuick
import SumpleteSolverQt
import "Components"

Window {
	id: root

	title: qsTr("Sumplete solver")
	width: 640
	height: 480
	color: "#63666A"
	visible: true

	MainModule {
		id: mainModule
	}

	Grid {
		id: grid
		anchors.centerIn: parent
		measurements: 600
	}

	Description {
		id: description

		anchors {
			horizontalCenter: grid.horizontalCenter
			bottom: grid.top
			bottomMargin: 40
		}
	}

	ColsSums {
		id: rowsSums

		anchors {
			horizontalCenter: grid.horizontalCenter
			top: grid.bottom
			topMargin: 20
		}

		width: grid.width
		height: 50
	}

	RowsSums {
		id: colsSums

		anchors {
			verticalCenter: grid.verticalCenter
			left: grid.right
			leftMargin: 20
		}

		width: 100
		height: grid.height
	}

	Row {
		id: solveButtonAndSizeDropdown

		anchors {
			horizontalCenter: rowsSums.horizontalCenter
			top: rowsSums.bottom
			topMargin: 20
		}

		spacing: 20

		GridSizeDropdown {
			id: gridSizeDropdown
		}

		SolveButton {
			id: solveButton
		}

		ClearButton {
			id: clearButton
		}
	}
}
