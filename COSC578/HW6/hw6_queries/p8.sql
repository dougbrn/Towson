SELECT S.s_name FROM S,(SELECT s_num, SUM(qty) qty_sum FROM SPJ
GROUP BY s_num) as sold
WHERE sold.qty_sum > 1000
AND S.s_num = sold.s_num;