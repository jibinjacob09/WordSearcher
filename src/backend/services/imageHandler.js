import path from 'path';
import fs from 'fs';

export function recieveImageDecoded (imgDecodedData, metadata) {
    const imgType = metadata.type || 'png';
    const imgPath = path.join('uploads', `image-${Date.now()}.${imgType}`);
    fs.writeFile(imgPath, imgDecodedData, err => {
        if (err) {
            throw new Error ('Error recieving the image');
        }
    });
}
