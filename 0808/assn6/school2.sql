SELECT Address AS 주소, city AS 도시, PostalCode AS 우편번호
FROM Customers
ORDER BY PostalCode DESC;

SELECT * 
FROM OrderDetails
ORDER BY OrderDetailID DESC
LIMIT 5;

SELECT * 
FROM Orders
ORDER BY OrderID DESC
LIMIT 7 OFFSET 3;

SELECT 
    OrderDetailID AS 상세주문번호, 
    OrderID AS 주문번호, 
    ProductID AS 상품번호, 
    Quantity AS 수량
FROM OrderDetails
WHERE OrderID <= 10000 OR ProductID >= 50
ORDER BY OrderDetailID DESC
LIMIT 8;
