import { wordSearchEngine } from './wordSearchEngine'
import { charmatrix, words } from './halloween'
import fs from 'fs'

const outputMtx = wordSearchEngine(charmatrix, words)

const writeStream = fs.createWriteStream('solution.txt')
const pathName = writeStream.path

outputMtx.map((row) => writeStream.write(`${row}\n`))

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
