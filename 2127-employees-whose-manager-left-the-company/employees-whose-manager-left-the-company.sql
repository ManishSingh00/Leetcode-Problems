# Write your MySQL query statement below
SELECT e1.employee_id 
FROM Employees e1
WHERE e1.salary < 30000
AND e1.manager_id IS NOT null
AND e1.manager_id NOT IN (select employee_id FROM Employees)
ORDER BY employee_id