# Write your MySQL query statement below
-- SELECT emp.name FROM Employee emp
-- JOIN(
--     SELECT managerId FROM Employee
--     WHERE managerId IS NOT NULL
--     GROUP BY managerId
--     HAVING COUNT(*) >= 5
-- ) temp
-- ON emp.id = temp.managerId

SELECT emp1.name 
FROM Employee emp1
JOIN Employee emp2
ON emp1.id = emp2.managerId
GROUP BY emp2.managerId
HAVING COUNT(*)>=5