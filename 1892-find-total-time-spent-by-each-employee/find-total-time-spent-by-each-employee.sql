/* Write your T-SQL query statement below */
SELECT event_day as day , emp_id , SUM((out_time-in_time)) as total_time from employees
group by event_day, emp_id;