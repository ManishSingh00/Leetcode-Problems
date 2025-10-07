# Write your MySQL query statement below
SELECT r.contest_id,ROUND(COUNT(DISTINCT r.user_id)/(SELECT COUNT(user_id) FROM Users)*100,2) AS percentage
FROM Register r
LEFT JOIN Users u
ON r.user_id = u.user_id
GROUP BY r.contest_id
ORDER BY percentage DESC, contest_id