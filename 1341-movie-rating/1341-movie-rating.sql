# Write your MySQL query statement below
select results
from( 
(select u.name as results,count(*) as num
from MovieRating r
join Users u
on r.user_id=u.user_id
group by r.user_id
order by num desc,u.name
limit 1)

UNION ALL

(select m.title as results, avg(rating) as avg_rating
from MovieRating r
join Movies m
on r.movie_id=m.movie_id
where r.created_at between '2020-02-1' and '2020-02-29'
group by r.movie_id
order by avg_rating desc, m.title
limit 1
)
) as x