import { charmatrix, words } from "./halloween";
import { _ } from "lodash";

function wordSearchEngine(matxChars, lstWords) {
  let horiz = extractHorizChars(matxChars);
  let vert = extractVertChars(matxChars);

  const _rowCount = matxChars.length;
  const _colCount = matxChars[0].length;

  let outputMatx = [];
  for (let i = 0; i < _rowCount; i++) {
    outputMatx.push(Array(_colCount).fill("*"));
  }

  for (let word of lstWords) {
    word = word.toLocaleLowerCase();
    outputMatx = findHorizontalRight(horiz.right, word, matxChars, outputMatx);
    outputMatx = findHorizontalLeft(horiz.left, word, matxChars, outputMatx);
  }
  console.log(outputMatx);
}

function findHorizontalRight(horizCharsR, word, charMatx, outputMatx) {
  const newRowIndex = horizCharsR.indexOf("~");
  const wordIndex = horizCharsR.indexOf(word);
  if (wordIndex > -1) {
    const row = Math.floor(wordIndex / newRowIndex);
    const col = wordIndex % (newRowIndex + 1);

    for (let l = 0; l < word.length; l++) {
      outputMatx[row][col + l] = charMatx[row][col + l];
    }
  }
  return outputMatx;
}

function findHorizontalLeft(horizCharsL, word, charMatx, outputMatx) {
  const newRowIndex = horizCharsL.indexOf("~");
  const wordIndex = horizCharsL.indexOf(word);
  const _colCount = charMatx[0].length;

  if (wordIndex > -1) {
    const row = Math.floor(wordIndex / (newRowIndex + 1));
    const col = _colCount - 1 - (wordIndex % (newRowIndex + 1));

    console.log(`word: ${word} row:${row}, col:${col}`);
    for (let l = 0; l < word.length; l++) {
      outputMatx[row][col - l] = charMatx[row][col - l];
    }
  }
  return outputMatx;
}

function extractHorizChars(matxChars) {
  let horizR = "";
  let horizL = "";
  for (let row = 0; row < matxChars.length; row++) {
    horizR += matxChars[row].join("") + "~";
    const _l = _.clone(matxChars[row]);
    horizL += _l.reverse().join("") + "~";
  }

  return {
    right: horizR.toLocaleLowerCase(),
    left: horizL.toLocaleLowerCase(),
  };
}

function extractVertChars(matxChars) {
  const _mtx = _.cloneDeep(matxChars);
  let transposedMatx = _.zip(..._mtx);
  let vertU = "";
  let vertD = "";

  for (let row of transposedMatx) {
    vertD += row.join("") + "~";
    vertU += row.reverse().join("") + "~";
  }
  return { up: vertU.toLocaleLowerCase(), down: vertD.toLocaleLowerCase() };
}

wordSearchEngine(charmatrix, words);
