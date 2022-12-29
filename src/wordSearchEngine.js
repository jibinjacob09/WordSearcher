import _ from 'lodash'

export function wordSearchEngine(mtx, lstWords) {
    var outputMatx = mtx.map((row) => {
        return row.map((_) => {
            return '*'
        })
    })
    const tposeMtx = _.zip(...mtx)

    for (let word of lstWords) {
        // checking every row
        for (let rn = 0; rn < mtx.length; rn++) {
            // checking each row in left-right ->  and right-left <-  directions
            var wordLoc = getWordLocationInMtxSeg(word, mtx[rn]) || getWordLocationInMtxSeg(word, mtx[rn], true)
            if (wordLoc) {
                outputMatx[rn].splice(wordLoc[0], word.length, ...mtx[rn].slice(wordLoc[0], wordLoc[1]))
            }
        }

        // checking every column
        for (let rn = 0; rn < tposeMtx.length; rn++) {
            // checking each column up-down and down-up directions
            var wordLoc =
                getWordLocationInMtxSeg(word, tposeMtx[rn]) || getWordLocationInMtxSeg(word, tposeMtx[rn], true)
            if (wordLoc) {
                for (let ln = wordLoc[0]; ln < wordLoc[1]; ln++) {
                    outputMatx[ln][rn] = mtx[ln][rn]
                }
            }
        }
    }
    return outputMatx
}

/*
 * Look for the word in a segment, and if exist return the start and end position
 */
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
