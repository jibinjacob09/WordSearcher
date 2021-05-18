import { matrix, words } from "./halloween";
import { _ } from "lodash";

function wordSearchEngine(matxChars, lstWords) {
  let horiz = extractHorizChars(matxChars);
  let vert = extractVertChars(matxChars);
  console.log()
  console.log(vert.down)
}

function extractHorizChars(matxChars) {
  let horizR = "";
  let horizL = "";
  for (let row of matxChars) {
    horizR += row.join("") + "~";
    horizL += row.reverse().join("") + "~";
  }
  return { right: horizR, left: horizL };
}

function extractVertChars(matxChars) {
  let transposedMatx = _.zip(...matxChars);
  let vertU = "";
  let vertD = "";

  for (let row of transposedMatx) {
    vertD += row.join("") + "~";
    vertU += row.reverse().join("") + "~";
  }
  return { up: vertU, down: vertD };
}

wordSearchEngine(matrix, words);
