// express routes
import { Router } from 'express';

const router = Router();

router.get('/', (req, res) => {
    res.send('Hello World from routers');
});

router.post('/parse-input', (req, res) => {
    const {srcMatrix, srcWords} = req.body;
    if (!srcMatrix || !srcWords) {
        res.status(400).send('Bad Request');
    }
    res.send('Images recieved');
})

export default router;
