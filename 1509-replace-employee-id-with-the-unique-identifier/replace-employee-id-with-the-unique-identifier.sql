# Write your MySQL query statement below
Select EmployeeUNI.unique_id as unique_id,Employees.name as name from Employees left join EmployeeUNI on EmployeeUNI.id=Employees.id;
