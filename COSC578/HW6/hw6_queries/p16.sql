CREATE TABLE supplier_shipment AS
SELECT S.s_num,S.s_name, SUM(qty) tot_qty FROM SPJ,S
WHERE SPJ.s_num = S.s_num
GROUP BY s_num;