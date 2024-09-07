# Write your MySQL query statement below
select w2.id as Id from Weather w2 where w2.temperature>(Select w1.temperature from Weather w1 where DATEDIFF(w2.recordDate,w1.recordDate)=1);

