# Write your MySQL query statement below
select max(salary) as SecondHighestSalary
from(
    select *, 
    dense_rank() over(order by salary desc) as dns_rnk
    from Employee
) as x
where dns_rnk=2