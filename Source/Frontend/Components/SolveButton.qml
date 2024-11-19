import QtQuick
import QtQuick.Controls
import Parameters

Button {
	id: root

	width: 150
	height: 50

	Text {
		id: text

		anchors.centerIn: parent

		text: "solve"
		color: "black"
	}

	onClicked: {
		const solutionStatus = mainModule.display_solution()
//Params.CellStatus.UNKNOWN
// INCOMPLETE_INPUT,
// 		INCORRECT_NUMBER_OF_ROWS,
// 		INCORRECT_NUMBER_OF_COLUMNS,
// 		GRID_NOT_SQUARED,
// 		NO_SOLUTION,
// 		VALID_SOLUTION
// 	};
		switch (solutionStatus)
		{
			case Params.SolutionStatus.INCOMPLETE_INPUT:
				console.log("INCOMPLETE")
				break

			case Params.SolutionStatus.NO_SOLUTION:
				noSolutionPopup.open()
				break

			case Params.SolutionStatus.VALID_SOLUTION:
				console.log("Found solution!")
				break

			default:
				console.log("Something strange happened.")
		}
	}
}
