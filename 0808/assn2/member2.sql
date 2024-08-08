UPDATE friends 
SET age = 15 
WHERE id IN (2, 4);

DELETE FROM friends 
WHERE id = 1;

INSERT INTO friends (name, age) 
VALUES ('촉촉', 100);
