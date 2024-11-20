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
				popups.incompleteInputPopup.open()
				break

			case Params.SolutionStatus.NO_SOLUTION:
				popups.noSolutionPopup.open()
				break

			case Params.SolutionStatus.VALID_SOLUTION:
				break

			default: // Should really not happen.
				popups.errorPopup.open()
				break
		}
	}
}
