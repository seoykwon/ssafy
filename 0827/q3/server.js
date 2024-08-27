const express = require('express');
const app = express();
const port = 3000;

const infos = [
    {name: "나나", age: 12, },
    {name: "유진", age: 8, },
    {name: "재범", age: 40, },
];

app.get("/api/info", (req,res) => {
    return res.json(infos);
});

app.get('/api/info/names', (req, res) => {
    const names = infos.map((info) => info.name);
    res.json(names);
});

app.get('/api/info/ages', (req, res) => {
    const ages = infos.map((info) => info.age);
    res.json(ages);
});

app.get('/api/info/:id', (req, res) => {
    const id = parseInt(req.params.id, 10);
    if (id >= 0 && id < infos.length){
        res.json(infos[id]);
    }
    else {
        res.status(404).json({error: 'Index out of range'});
    }
});

app.listen(port, () => {
    console.log(`Server is running on http://localhost:${port}`);
});