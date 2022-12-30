import { wordSearchEngine } from './wordSearchEngine'
import { charmatrix, words } from './Puzzles/christmas'
import fs from 'fs'

const result = wordSearchEngine(
    charmatrix.map((row) => row.map((c) => c.toUpperCase())),
    words.map((word) => word.toUpperCase())
)

const writeStream = fs.createWriteStream('solution.txt')
const pathName = writeStream.path

result.outputMatx.map((row) => writeStream.write(`${row}\n`))
writeStream.write('\n')

if (result.wordsNotFound.length) {
    writeStream.write(`Words not found:  ${result.wordsNotFound} \n`)
} else {
    writeStream.write(`All words have been found!! \n`)
}

// the finish event is emitted when all data has been flushed from the stream
writeStream.on('finish', () => {
    console.log(`wrote all the array data to file ${pathName}`)
})

// handle the errors on the write process
writeStream.on('error', (err) => {
    console.error(`There is an error writing the file ${pathName} => ${err}`)
})

// close the stream
writeStream.end()
