pragma ComponentBehavior: Bound

import QtQuick

GridView {
	id: root

	required property int measurements // Length of the width and height
	required property int size         // Number of rows and columns.

	width: measurements
	height: measurements
	cellWidth: measurements / root.size
	cellHeight: measurements / root.size
	model: size * size // Number of cells.
	boundsBehavior: Flickable.StopAtBounds

	// Properties for the cells.
	delegate: Rectangle {
		width: root.cellWidth
		height: root.cellHeight
		color: "grey"
		border.color: "black"
	}
}
