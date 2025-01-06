import { createWorker } from 'tesseract.js';

// Constants for regex patterns
const WHITESPACE_AND_PIPE = /\s|\|/g;
const WHITESPACE_AND_NEWLINE = /\s+|\n/g;

// OCR Function
/* 
    Function to extract text from image using Tesseract.js
    @param {string} imgPath - Path to image file
    @returns {string} - Extracted text from image
*/
async function ocr(imgPath) {
    const worker = await createWorker();

    try {
        const { data: { text } } = await worker.recognize(imgPath);
        return text;
    } catch (error) {
        console.error('Error during OCR:', error);
        throw new Error('Error during OCR');
    } finally {
        await worker.terminate();
    }
}


// Sanitize and format character matrix
export function sanitizeAndPrettyMatrix(rawCharMatrix) {
    return rawCharMatrix
        .split('\n')
        .map(row => row.replace(WHITESPACE_AND_PIPE, '').toUpperCase());
}

// Sanitize and format word list
export function sanitizeAndPrettyWordList(rawWordList) {
    return rawWordList
        .split(WHITESPACE_AND_NEWLINE)
        .map(word => word.toUpperCase())
        .filter(Boolean);  // Removes empty strings in case of extra whitespace
}

// Extract text from image source
/* @param {string} imgPath - Path to image file
* @returns {string} - Extracted text from image
*/
export async function extractFromImage(imgPath) {
    const rawText = await ocr(imgPath);
    if (typeof rawText !== 'string' || !rawText.trim()) {
        console.error('Error: OCR failed or returned empty text');
        return null;
    }
    return rawText;
}

