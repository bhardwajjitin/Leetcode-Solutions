# Write your MySQL query statement below
select DATE_FORMAT(trans_date, '%Y-%m') as month,T.country,count(*) as trans_count,COALESCE(B.approved_count,0) AS approved_count,sum(T.amount) as trans_total_amount,COALESCE(B.approved_total,0) AS approved_total_amount from Transactions T left join 
(select month(P.trans_date) as approved_month ,year(P.trans_date) as approved_year,P.country AS approved_country,count(*) as approved_count,sum(P.amount) as approved_total from Transactions P where P.state='approved' group by month(P.trans_date),year(P.trans_date),P.country) as B on MONTH(T.trans_date) = B.approved_month and year(T.trans_date)=B.approved_year AND T.country = B.approved_country or (T.country is null and B.approved_country is null) group by month(T.trans_date),year(T.trans_date),T.country;

        



