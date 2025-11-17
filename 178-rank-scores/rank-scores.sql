# Write your MySQL query statement below
select s.score,
(
    select count(distinct score)
    from Scores
    where score >= s.score
) as 'rank'
from Scores s
order by s.score desc