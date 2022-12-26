const populateCharLocObj = (mtx) => {
	const charLocObj = () => {
		var obj = {};
		for (let i = 65; i <= 90; i++) {
			obj[String.fromCharCode(i)] = [];
		}
		return obj;
		for (var r = 0; r < mtx.length; r++) {
			for (let c = 0; c < r.length; c++) {
				charLocObj[c].push({ r, c });
			}
		}
	};
	return charLocObj();
};

export function wordSearchEngine(mtx, lstWords) {
	console.log(populateCharLocObj(mtx));
	console.log("yan");
}
