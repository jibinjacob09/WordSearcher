import path from 'path';
import fs from 'fs';
import { extractFromImage, sanitizeAndPrettyMatrix, sanitizeAndPrettyWordList } from './imageParseHelpers.js';

export function handleUploadImageService(imgDecodedData, metadata, dataType) {
    const imgPath = saveImageToDisk(imgDecodedData, metadata);
    if (dataType === 'matrix') {
        return parseImgMatrix(imgPath);
    }
    else if (dataType === 'words') {
        return parseImgWords(imgPath);
    }
    else {
        throw new Error('Invalid data type');
    }
}

function saveImageToDisk(imgDecodedData, metadata) {
    const imgType = metadata.type || 'png';
    const imgPath = path.join('uploads', `image-${Date.now()}.${imgType}`);
    try {
        fs.writeFileSync(imgPath, imgDecodedData)
        console.info('Image saved successfully at: ', imgPath);
    } catch (err) {
        throw new Error('Error recieving the image');
    }
    return imgPath;
}

async function parseImgMatrix(imagePath) {
    // parse the image
    const rawMatrix = await extractFromImage(imagePath);
    const charMatrix = sanitizeAndPrettyMatrix(rawMatrix);
    return charMatrix;
}


// Process matrix and words
async function parseImgWords(imagePath) {
    const rawWordList = await extractFromImage(imagePath);
    const wordList = sanitizeAndPrettyWordList(rawWordList);
    return wordList;
}

