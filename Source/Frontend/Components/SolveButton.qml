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

		switch (solutionStatus)
		{
			case Params.SolutionStatus.INCOMPLETE_INPUT:
				incompleteInputPopup.open()
				break

			case Params.SolutionStatus.NO_SOLUTION:
				noSolutionPopup.open()
				break

			case Params.SolutionStatus.VALID_SOLUTION:
				break

			default: // Should really not happen.
				console.log("Something strange happened.")
		}
	}
}
