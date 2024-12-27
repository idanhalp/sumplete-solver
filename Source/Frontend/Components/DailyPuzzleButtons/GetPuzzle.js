function getDailyPuzzle(puzzleSize) {
	const validSizes = [5, 7];
	const sizeIsValid = validSizes.includes(puzzleSize);

	if (!sizeIsValid)
	{
		console.log("Requested daily puzzle size is not valid!");
		return;
	}

	// This code segment is taken from "sumplete.com".
	const today = Math.floor((new Date() - new Date("Mar 8 2023")) / (1000 * 60 * 60 * 24));
	const puzzleIndex = today - (((today - 1) % 100) + 1) + 1;

	let xhr = new XMLHttpRequest();
	xhr.open("GET", "https://data.sumplete.com/daily/" + puzzleSize + "/" + puzzleIndex + ".txt", true);

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

			const [grid, rowSums, colSums, _] = puzzleLine
				.split(';')
				.map(line => line.split(','));
		}
	};

	xhr.send();
}

// function generate(ns, day) {
//       let xhr = new XMLHttpRequest();
//       // let pf = day - (day % 100) + 1;
//       let pf = day - (((day - 1) % 100) + 1) + 1;
//       xhr.open('GET', 'https://data.sumplete.com/daily/' + ns + '/' + pf + '.txt', true);
//       xhr.onreadystatechange = function () {
//         if (xhr.readyState === 4 && xhr.status === 200) {
//           let puzzlelines = xhr.responseText.split(/\n/);
//           for (let i = 0; i < puzzlelines.length; i++) {
//             let z = puzzlelines[i].split(/\:/);
//             if (z[0] == day) {
//               let y = z[1].split(/;/);
//               let numberGrid = y[0].split(',');
//               let rowSums = y[1].split(',');
//               let colSums = y[2].split(',');
//               let statusGrid = y[3].split(',');
//               localStorage.setItem('dailytime', 0);
//               localStorage.setItem('dailylastplayed', day);
//               updateboard(day, ns, 1, numberGrid, statusGrid, rowSums, colSums);
//               break;
//             }
//           }
//         }
//       };
//       xhr.send();
//     }
