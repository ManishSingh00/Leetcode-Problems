# Write your MySQL query statement below
SELECT emp.name FROM Employee emp
JOIN(
    SELECT managerId FROM Employee
    WHERE managerId IS NOT NULL
    GROUP BY managerId
    HAVING COUNT(*) >= 5
) temp
ON emp.id = temp.managerId