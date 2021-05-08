SELECT SPJ.j_num, P.p_num, P.pname, qty FROM SPJ, P,(SELECT j_num,MAX(qty) max_qty FROM SPJ
GROUP BY j_num) as P_qty
WHERE SPJ.j_num = P_qty.j_num
AND SPJ.qty = P_qty.max_qty
AND SPJ.p_num = P.p_num;