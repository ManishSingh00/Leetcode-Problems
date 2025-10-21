# Write your MySQL query statement below
-- SELECT DISTINCT a.num  AS consecutiveNums FROM Logs a
-- JOIN Logs b ON b.id = a.id+1 AND a.num = b.num
-- JOIN Logs C ON c.id = a.id+2 AND a.num = c.num


SELECT DISTINCT num  AS ConsecutiveNums
FROM(
    SELECT num,
    LEAD(num,1) OVER (ORDER BY id) AS next1,
    LEAD(num,2) OVER (ORDER BY id) AS next2
    FROM Logs
) t
WHERE num = next1 AND num = next2