SELECT s_name FROM S
WHERE s_num in (
SELECT s_num FROM SPJ, J
WHERE J.j_num = SPJ.j_num
AND J.city = 'Athens'
);