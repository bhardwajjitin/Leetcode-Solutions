# Write your MySQL query statement below
Select Person.email as Email From Person group by email having Count(email)>1;