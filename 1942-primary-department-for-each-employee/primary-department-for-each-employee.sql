# Write your MySQL query statement below
select e.employee_id,case
    when count(*)=1 then e.department_id
    when count(*)>1 then (select e1.department_id from Employee e1 where e1.employee_id=e.employee_id and e1.primary_flag='Y')
    end as department_id from Employee e group by e.employee_id;