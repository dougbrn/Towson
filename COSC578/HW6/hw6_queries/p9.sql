SELECT j_num FROM J
WHERE city in (SELECT MIN(city) FROM J);