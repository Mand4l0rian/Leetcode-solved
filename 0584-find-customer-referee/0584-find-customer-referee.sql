# Write your MySQL query statement below
select c.name
from customer c left join customer r
on c.referee_id=r.id
where c.referee_id is NULL or c.referee_id!= 2

