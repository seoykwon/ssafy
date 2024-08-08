SELECT * 
FROM Orders 
WHERE CustomerID > 33 AND EmployeeID < 5;

SELECT * 
FROM Orders 
WHERE OrderID < 10000 OR ShipperID < 5;

SELECT * 
FROM OrderDetails 
WHERE ProductID > 14;

SELECT CustomerName, city 
FROM Customers 
WHERE CustomerID > 10 AND CustomerID <= 50;

SELECT * 
FROM Orders 
WHERE CustomerID BETWEEN 30 AND 39;

SELECT ProductName, ProductID 
FROM Products 
WHERE ProductID % 2 = 0 AND SupplierID % 2 = 1;
