const express = require('express');
const bodyParser = require('body-parser');
const todosRoutes = require('./routes/todos');

const app = express();
const PORT = 3000;

// Middleware
app.use(bodyParser.json());

// Routes
app.use('/api/todos', todosRoutes);

// Start server
app.listen(PORT, () => {
    console.log(`Server is running on http://localhost:${PORT}`);
});
