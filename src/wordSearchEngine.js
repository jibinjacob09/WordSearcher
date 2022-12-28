export function wordSearchEngine(mtx, lstWords) {
    var outputMatx = mtx.map((row) => {
        return row.map((col) => {
            return '*'
        })
    })

    // checking every row
    for (let rn = 0; rn < mtx.length; rn++) {
        for (let word of lstWords) {
            // checking each row in left-right ->  and right-left <-  direction
            var wordLoc = getWordLocationInMtxSeg(word, mtx[rn]) || getWordLocationInMtxSeg(word, mtx[rn], true)
            if (wordLoc) {
                outputMatx[rn].splice(wordLoc[0], word.length, ...mtx[rn].slice(wordLoc[0], wordLoc[1]))
            }
        }
    }
    console.log(outputMatx)
}

const getWordLocationInMtxSeg = (word, mtxSegment, reverse = false) => {
    const rowStr = mtxSegment.join('')
    const wordToLook = reverse ? word.split('').reverse().join('') : word
    if (rowStr.includes(wordToLook)) {
        const loc = rowStr.search(wordToLook)
        const wordLoc = [loc, loc + word.length]
        return wordLoc
    }
    return null
}
