import _ from 'lodash'

export function wordSearchEngine(mtx, lstWords) {
    var outputMatx = mtx.map((row) => {
        return row.map((_) => {
            return '*'
        })
    })
    const tposeMtx = _.zip(...mtx)
    const diagonalStrs = getDiagonals(mtx)

    for (let word of lstWords) {
        var isWordFound = false

        // checking every row
        if (!isWordFound) {
            for (let rn = 0; rn < mtx.length; rn++) {
                // checking each row in left-right ->  and right-left <-  directions
                var wordLoc = getWordLocationInMtxSeg(word, mtx[rn]) || getWordLocationInMtxSeg(word, mtx[rn], true)
                if (wordLoc) {
                    outputMatx[rn].splice(wordLoc[0], word.length, ...mtx[rn].slice(wordLoc[0], wordLoc[1]))
                    isWordFound = true
                    break
                }
            }
        }

        // checking every column
        if (!isWordFound) {
            for (let rn = 0; rn < tposeMtx.length; rn++) {
                // checking each column up-down and down-up directions
                var wordLoc =
                    getWordLocationInMtxSeg(word, tposeMtx[rn]) || getWordLocationInMtxSeg(word, tposeMtx[rn], true)
                if (wordLoc) {
                    for (let ln = wordLoc[0]; ln < wordLoc[1]; ln++) {
                        outputMatx[ln][rn] = mtx[ln][rn]
                    }
                    isWordFound = true
                    break
                }
            }
        }

        // checking diagonal down, top left to bottom right
        if (!isWordFound) {
            const diag1 = diagonalStrs[0]
            for (let sn = 0; sn < diag1.length; sn++) {
                var wordLoc = getWordLocationInMtxSeg(word, diag1[sn]) || getWordLocationInMtxSeg(word, diag1[sn], true)
                if (wordLoc) {
                    for (let ln = wordLoc[0]; ln < 1 * (word.length + wordLoc[0]); ln++) {
                        outputMatx[sn + ln][ln] = mtx[sn + ln][ln]
                    }
                    isWordFound = true
                    break
                }
            }
        }

        // checking diagonal down, top left to top right
        if (!isWordFound) {
            const diag2 = diagonalStrs[1]
            for (let sn = 0; sn < diag2.length; sn++) {
                var wordLoc = getWordLocationInMtxSeg(word, diag2[sn]) || getWordLocationInMtxSeg(word, diag2[sn])
                if (wordLoc) {
                    for (let ln = wordLoc[0]; ln < wordLoc[1]; ln++) {
                        outputMatx[ln][sn + ln] = mtx[ln][sn + ln]
                    }
                    isWordFound = true
                    break
                }
            }
        }

        // checking diagonal up, bottom left to top left
        if (!isWordFound) {
            const diag3 = diagonalStrs[2]
            for (let sn = 0; sn < diag3.length; sn++) {
                var wordLoc = getWordLocationInMtxSeg(word, diag3[sn]) || getWordLocationInMtxSeg(word, diag3[sn])
                if (wordLoc) {
                    for (let ln = wordLoc[0]; ln < wordLoc[1]; ln++) {
                        outputMatx[mtx.length - 1 - sn - ln][ln] = mtx[mtx.length - 1 - sn - ln][ln]
                    }
                    isWordFound = true
                    break
                }
            }
        }

        // checking diagonal up, bottom left to bottom right
        if (!isWordFound) {
            const diag4 = diagonalStrs[3]
            for (let sn = 0; sn < diag4.length; sn++) {
                var wordLoc = getWordLocationInMtxSeg(word, diag4[sn]) || getWordLocationInMtxSeg(word, diag4[sn], true)
                if (wordLoc) {
                    for (let ln = wordLoc[0]; ln < wordLoc[1]; ln++) {
                        outputMatx[mtx.length - 1 - ln][sn + ln] = mtx[mtx.length - 1 - ln][sn + ln]
                    }
                    isWordFound = true
                    break
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
    const rowStr = typeof mtxSegment !== 'string' ? mtxSegment.join('') : mtxSegment
    const wordToLook = reverse ? word.split('').reverse().join('') : word
    if (rowStr.includes(wordToLook)) {
        const loc = rowStr.search(wordToLook)
        const wordLoc = [loc, loc + word.length]
        return wordLoc
    }
    return null
}

/*
 * Parses diagonal strings from the matrix.
 *   returns [
 *   	diagonal strings down from top left corner to bottom left corner
 *   	diagonal strings down from top left corner to top right corner
 *   	diagonal strings up from bottom left corner to top left corner
 *   	diagonal strings up from bottom left corner to bottom right corner
 *
 *   ]
 */
const getDiagonals = (mtx) => {
    const maxRows = mtx.length

    const diagStrDown1 = []
    const diagStrDown2 = []
    const diagStrUp1 = []
    const diagStrUp2 = []
    for (let r = 0; r < maxRows; r++) {
        var sd1 = ''
        var sd2 = ''
        var su1 = ''
        var su2 = ''
        for (let p = 0; p < maxRows - r; p++) {
            sd1 = sd1 + mtx[p + r][p]
            sd2 = sd2 + mtx[p][p + r]

            su1 = su1 + mtx[maxRows - r - p - 1][p]
            su2 = su2 + mtx[maxRows - p - 1][p + r]
        }
        diagStrDown1.push(sd1)
        diagStrDown2.push(sd2)
        diagStrUp1.push(su1)
        diagStrUp2.push(su2)
    }
    return [diagStrDown1, diagStrDown2, diagStrUp1, diagStrUp2]
}
