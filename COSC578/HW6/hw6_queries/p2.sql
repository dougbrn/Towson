SELECT S.s_num, S.s_name FROM S, SPJ, P
WHERE S.s_num = SPJ.s_num AND P.p_num = SPJ.p_num AND
s_name LIKE 'A%' AND
pname LIKE 'S%';