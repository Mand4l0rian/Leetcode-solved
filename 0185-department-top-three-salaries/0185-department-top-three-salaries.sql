# Write your MySQL query statement below
select d.name as Department, e.name as Employee, salary
from Employee e
join Department d
on e.departmentId=d.id
where (e.departmentId,e.salary) IN(
    select departmentId,salary
    from(
    select*,
    dense_rank() over(partition by departmentId order by salary desc) as dns_rnk
    from Employee)
    as x
    where dns_rnk<=3
)