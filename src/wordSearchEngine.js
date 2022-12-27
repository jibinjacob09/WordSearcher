function populateCharLocObj(mtx) {
    var obj = {}
    for (let i = 65; i <= 90; i++) {
        obj[String.fromCharCode(i)] = []
    }

    for (var row = 0; row < mtx.length; row++) {
        for (let col = 0; col < mtx[row].length; col++) {
            const letter = mtx[row][col].toUpperCase()
            obj[letter].push({ r: row, c: col })
        }
    }
    return obj
}

export function wordSearchEngine(mtx, lstWords) {
    const locInfo = populateCharLocObj(mtx)
    console.log(locInfo)
    for (let word of lstWords) {
        console.log(word.toUpperCase())
    }
}
