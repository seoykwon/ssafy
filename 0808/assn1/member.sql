SELECT * 
FROM friends 
WHERE id IN (3, 5);

SELECT id, age 
FROM friends 
WHERE id >= 2 AND id <= 5;

SELECT * 
FROM friends 
WHERE age BETWEEN 20 AND 29;

SELECT name 
FROM friends 
WHERE id % 2 = 0 AND age % 2 = 1;

SELECT id AS 번호, name AS 성함, age AS 나이 
FROM friends 
ORDER BY age ASC;

SELECT age, name 
FROM friends 
ORDER BY name ASC;
