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
					const lightGreen = "#99EE99"
					return lightGreen

				case Params.CellStatus.DELETE:
					const lightRed = "#FF7F7F"
					return lightRed

				case Params.CellStatus.UNKNOWN:
					const lightGrey = "#D3D3D3"
					return lightGrey

				// After resizing there is a moment when `cell_statuses`'s
				// size might be incompatible with the grid's size.
				// This is needed to prevent undefined behavior.
				default:
					return "black"
			}
		}

		TextField {
            anchors.fill: parent
            horizontalAlignment: TextField.AlignHCenter

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
