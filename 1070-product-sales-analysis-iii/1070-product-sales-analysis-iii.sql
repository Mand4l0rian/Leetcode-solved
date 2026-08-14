# Write your MySQL query statement below
select s1.product_id,s2.first_year, s1.quantity,s1.price 
from Sales s1
join (
    select product_id, MIN(year) as first_year
    from Sales
    group by product_id
) s2
on s1.product_id=s2.product_id
and s1.year=s2.first_year