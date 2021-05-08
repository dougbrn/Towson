SELECT pname FROM P
WHERE p_num not in (
SELECT p_num FROM SPJ, J
WHERE J.j_num = SPJ.j_num
AND J.j_num = 'j3'
);