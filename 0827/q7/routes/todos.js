const express = require('express');
const router = express.Router();

// Temporary in-memory data store
let todos = [
    { id: 1, title: 'Complete MySQL project', is_completed: false, author: 'Alice' },
    { id: 2, title: 'Review AWS architecture', is_completed: true, author: 'Bob' },
    { id: 3, title: 'Write unit tests', is_completed: false, author: 'Alice' },
];

// Existing routes...

// GET /api/todos - Get all todos
router.get('/', (req, res) => {
    res.json(todos);
});

// GET /api/todos/:id - Get a todo by ID
router.get('/:id', (req, res) => {
    const todoId = parseInt(req.params.id, 10);
    const todo = todos.find(t => t.id === todoId);
    if (todo) {
        res.json(todo);
    } else {
        res.status(404).json({ error: 'Todo not found' });
    }
});

// POST /api/todos - Create a new todo
router.post('/', (req, res) => {
    const { title, is_completed, author } = req.body;
    const newTodo = {
        id: todos.length + 1,
        title,
        is_completed: Boolean(is_completed),
        author,
    };
    todos.push(newTodo);
    res.status(201).json(newTodo);
});

// PATCH /api/todos/:id - Update a todo by ID
router.patch('/:id', (req, res) => {
    const todoId = parseInt(req.params.id, 10);
    const todo = todos.find(t => t.id === todoId);
    if (todo) {
        const { title, is_completed, author } = req.body;
        if (title) todo.title = title;
        if (typeof is_completed !== 'undefined') todo.is_completed = Boolean(is_completed);
        if (author) todo.author = author;
        res.json(todo);
    } else {
        res.status(404).json({ error: 'Todo not found' });
    }
});

// DELETE /api/todos/:id - Delete a todo by ID
router.delete('/:id', (req, res) => {
    const todoId = parseInt(req.params.id, 10);
    const todoIndex = todos.findIndex(t => t.id === todoId);
    if (todoIndex !== -1) {
        const deletedTodo = todos.splice(todoIndex, 1);
        res.json(deletedTodo[0]);
    } else {
        res.status(404).json({ error: 'Todo not found' });
    }
});

// NEW ROUTE: GET /api/author/:name - Get todos by author name
router.get('/author/:name', (req, res) => {
    const authorName = req.params.name;
    const filteredTodos = todos.filter(todo => todo.author.toLowerCase() === authorName.toLowerCase());
    if (filteredTodos.length > 0) {
        res.json(filteredTodos);
    } else {
        res.status(404).json({ error: 'No todos found for the specified author' });
    }
});

// NEW ROUTE: GET /api/completed - Get completed todos
router.get('/completed', (req, res) => {
    const completedTodos = todos.filter(todo => todo.is_completed == 1);
    if (completedTodos.length > 0) {
        res.json(completedTodos);
    } else {
        res.status(404).json({ error: 'No completed todos found' });
    }
});

module.exports = router;
