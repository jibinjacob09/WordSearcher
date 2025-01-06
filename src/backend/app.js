import express from 'express';
import router from './routes.js';
import bodyParser from 'body-parser';

const app = express();
const PORT = 3000;

app.use(bodyParser.json({ limit: '5mb' })); 
app.use('/', router);

app.listen(PORT, () => {
  console.log(`app listening on port ${PORT}!`);
});
