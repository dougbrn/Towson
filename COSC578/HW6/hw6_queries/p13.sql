UPDATE S as S1
INNER JOIN (SELECT city FROM S WHERE s_name = 'Adams') as S2
SET S1.city = S2.city
WHERE S1.s_name = 'Smith';

SELECT * FROM S;