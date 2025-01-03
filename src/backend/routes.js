// express routes
import { Router } from 'express';
import { wordSearchSolverService } from './services/wordSearchSolverService.js';
import { recieveImageDecoded } from './services/imageHandler.js';

const router = Router();

router.get('/', (req, res) => {
    res.send('Hello World from routers');
});


router.post('/upload', (req, res) => {
    const { imgData, metadata } = req.body;
    if ((!imgData) || (!metadata)) {
        res.status(400).send('Bad Request');
    }
    const buffer = Buffer.from(imgData, 'base64');
    recieveImageDecoded(buffer, metadata);
    res.send('Image uploaded successfully');
})

router.post('/solve', (req, res) => {
    const { matrix, words } = req.body;
    if (!matrix || !words) {
        res.status(400).send('Bad Request');
    }
    // call the service to solve the problem
    const result = wordSearchSolverService(
        matrix.map((row) => row.map((c) => c.toUpperCase())),
        words.map((word) => word.toUpperCase())
    )
    res.send(result);

})


export default router;
