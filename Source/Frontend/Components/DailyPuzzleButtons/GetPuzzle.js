// Tries to retrieve the daily puzzle of the requested size.
// If successful, uploads it to the grid.
function loadDailyPuzzle(puzzleSize) {
	popups.loadingPopup.open();
	popups.loadingPopup.isLoading = true;

	const validSizes = [5, 7];
	const sizeIsValid = validSizes.includes(puzzleSize);

	if (!sizeIsValid) {
		console.log("Requested daily puzzle size is not valid!");
		popups.loadingPopup.close();
		popups.loadingPopup.isLoading = false;
		return;
	}

	// This code segment is taken from "sumplete.com".
	const today = Math.floor((new Date() - new Date("Mar 8 2023")) / (1000 * 60 * 60 * 24));
	const puzzleIndex = today - (((today - 1) % 100) + 1) + 1;

	const xhr = new XMLHttpRequest();
	xhr.open("GET", `https://data.sumplete.com/daily/${puzzleSize}/${puzzleIndex}.txt`, true);

	xhr.onreadystatechange = function() {
		const requestIsSuccessful = xhr.readyState === 4 && xhr.status === 200;

		if (!requestIsSuccessful) {
			return;
		}

		const inputLines = xhr.responseText.split('\n');

		for (const inputLine of inputLines) {
			const [puzzleDay, puzzleLine] = inputLine.split('\:');
			const foundTodaysPuzzle = Number(puzzleDay) === today;

			if (!foundTodaysPuzzle) {
				continue;
			}

			const [gridBuffer, rowSums, colSums, _] = puzzleLine
				.split(';')
				.map(line => line.split(','));

			mainModule.load_grid(gridBuffer, rowSums, colSums);
			popups.loadingPopup.close();
			popups.loadingPopup.isLoading = false;
			return;
		}
	};

	xhr.send();
}
