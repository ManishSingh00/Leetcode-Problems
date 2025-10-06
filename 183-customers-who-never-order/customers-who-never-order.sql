# Write your MySQL query statement below
SELECT Customers.name AS Customers FROM Customers
LEFT JOIN orders ON Customers.id = Orders.customerId
WHERE Orders.customerId IS NULL