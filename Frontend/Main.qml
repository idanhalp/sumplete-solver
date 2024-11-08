import QtQuick
import "Components/Grid"

Window {
	id: root

	title: qsTr("Sumplete solver")
	width: 640
	height: 480
	visible: true

	Grid {
		anchors.centerIn: parent
		measurements: 400
		size: 3
	}
}
