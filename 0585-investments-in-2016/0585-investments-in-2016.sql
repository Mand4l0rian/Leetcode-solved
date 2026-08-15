# Write your MySQL query statement below
select round(sum(tiv_2016),2) as tiv_2016
from(select *
from Insurance
where tiv_2015 IN(
    select tiv_2015
    from Insurance 
    group by tiv_2015
    having count(*)>1)
intersect
select *
from insurance
group by lat,lon
having count(*)=1
) as x
