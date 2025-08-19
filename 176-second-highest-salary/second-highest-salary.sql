# Write your MySQL query statement below
SELECT MAX(salary) AS secondhighestsalary FROM Employee
WHERE salary < (SELECT MAX(salary) FROM Employee)