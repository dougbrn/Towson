DELETE FROM SPJ
WHERE j_num in (SELECT j_num FROM J
WHERE city = 'Rome');

DELETE FROM J
WHERE city = 'Rome';

SELECT * FROM J;