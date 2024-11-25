# Write your MySQL query statement below
select Q.query_name,round(avg(rating/position),2) as quality,T.poor_query_percentage from Queries Q left join 
(select P.query_name,round(sum(case 
when rating<3 then 1
else 0
END)/count(*)*100,2) as poor_query_percentage from Queries P group by P.query_name) as T on Q.query_name=T.query_name where Q.query_name is not null group by Q.query_name;