SELECT s_num, s_name FROM S where status > (SELECT MAX(status) from S
WHERE city='Paris');