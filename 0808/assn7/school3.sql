SELECT *
FROM OrderDetails
WHERE ProductID LIKE '1%';

SELECT *
FROM OrderDetails
WHERE ProductID LIKE '%1_' OR '1_';
