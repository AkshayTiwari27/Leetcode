# Write your MySQL query statement below
WITH cte AS
(SELECT customer_number, COUNT(order_number) AS num
FROM Orders
GROUP BY customer_number)

SELECT customer_number
FROM cte
WHERE num = (SELECT MAX(num) FROM cte)