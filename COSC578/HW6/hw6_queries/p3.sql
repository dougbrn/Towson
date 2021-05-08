SELECT S.s_name FROM S
WHERE s_num in (
SELECT s_num FROM SPJ
WHERE SPJ.j_num = 'j2'
);