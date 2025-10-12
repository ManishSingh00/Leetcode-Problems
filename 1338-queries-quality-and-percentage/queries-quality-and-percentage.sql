# Write your MySQL query statement below
SELECT q.query_name, ROUND(AVG(rating/position),2) AS quality,
ROUND(
    (
        (SELECT COUNT(*)
        FROM Queries q2
        WHERE q2.query_name = q.query_name AND q2.rating<3)
        /
        (SELECT COUNT(*)
        FROM Queries q3
        WHERE q3.query_name = q.query_name
        )
    )*100    
,2) AS poor_query_percentage
FROM Queries q
GROUP BY q.query_name