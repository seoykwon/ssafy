SELECT * 
FROM city 
WHERE population < 1000 AND name LIKE 'A%';

SELECT name, countrycode 
FROM city 
WHERE countrycode = 'JPN' AND population BETWEEN 1000000 AND 2000000;

SELECT * 
FROM city 
WHERE name LIKE '%kim%';

SELECT COUNT(*) 
FROM city;

SELECT id, population 
FROM city 
ORDER BY population ASC 
LIMIT 5;

SELECT countrycode, SUM(population) AS total_population 
FROM city 
GROUP BY countrycode 
ORDER BY total_population DESC 
LIMIT 5;
