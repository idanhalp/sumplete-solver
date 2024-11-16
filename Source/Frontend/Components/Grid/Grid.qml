import QtQuick
import QtQuick.Controls
import Parameters

GridView {
	id: root

	required property int measurements // Length of the width and height

	width: measurements
	height: measurements
	cellWidth: measurements / mainModule.size
	cellHeight: measurements / mainModule.size

	model: mainModule

	boundsBehavior: Flickable.StopAtBounds

	// Properties for the cells.
	delegate: Rectangle {
		width: root.cellWidth
		height: root.cellHeight

		border.color: "black"

		color: {
			const cellStatus = mainModule.cell_statuses[index]

			switch (cellStatus) {
				case Params.CellStatus.KEEP:
					return "green"

				case Params.CellStatus.DELETE:
					return "red"

				case Params.CellStatus.UNKNOWN:
					return "grey"
			}
		}

		TextField {
			anchors.centerIn: parent

			font.pixelSize: 25

			background: Rectangle {
				color: "transparent"
			}

			onTextChanged: {
				mainModule.update_grid(index, text)
			}

			validator: IntValidator {
				bottom: -99
				top:    +99
			}
		}
	}
}
