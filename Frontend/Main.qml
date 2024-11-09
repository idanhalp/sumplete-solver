import QtQuick
import "Components/Grid"
import "Components/GridSizeDropdown"
import "Components/RowsSums"
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
		size: 4
	}

	RowsSums {
		id: rowsSums

		anchors {
			horizontalCenter: grid.horizontalCenter
			top: grid.bottom
			topMargin: 20
		}

		width: grid.width
		height: 50
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
	}
}
