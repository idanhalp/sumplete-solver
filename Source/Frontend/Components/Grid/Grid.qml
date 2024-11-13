pragma ComponentBehavior: Bound

import QtQuick

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
		color: "grey"
		border.color: "black"
	}
}
