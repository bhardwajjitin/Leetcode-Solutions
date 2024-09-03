# Write your MySQL query statement below
Select Max(Salary) as SecondHighestSalary from Employee where Salary !=(Select Max(Salary) from Employee);