# Write your MySQL query statement below
SELECT customer_id,COUNT(V.customer_id) as count_no_trans
FROM Visits V
WHERE V.visit_id NOT IN (SELECT T.visit_id FROM Transactions T) group by V.customer_id;