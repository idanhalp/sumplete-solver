import QtQuick
import QtQuick.Controls

ListView {
	id: root

	interactive: false
	orientation: ListView.Vertical
	model: mainModule.size

	delegate: Rectangle {
		width: root.width
		height: root.height / mainModule.size

		color: "#D3D3D3" // Light grey
		border.color: "black"

		TextField {
			anchors.fill: parent
			horizontalAlignment: TextField.AlignHCenter

			font.pixelSize: 25

			background: Rectangle {
				color: "transparent"
			}

			text: {
				switch (mainModule.rows_sums[index]) {
				case mainModule.NO_VALUE:
					return "";

				case undefined:
					return;

				default:
					return mainModule.rows_sums[index];
				}
			}

			onTextChanged: {
				if (text === "") {
					mainModule.update_row_sum(index, mainModule.NO_VALUE)
				}
				else {
					mainModule.update_row_sum(index, text)
				}
			}

			validator: IntValidator {
				bottom: -99
				top:    +99
			}
		}
	}
}
