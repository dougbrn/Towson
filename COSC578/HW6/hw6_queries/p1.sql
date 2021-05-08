SELECT S.s_num, S.s_name FROM S
INNER JOIN SPJ ON S.s_num =SPJ.s_num
WHERE SPJ.p_num='p3' and S.s_name LIKE 'A%';