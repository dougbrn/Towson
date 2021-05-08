SELECT city, MAX(citycount) FROM (SELECT city,COUNT(city) citycount FROM S
GROUP BY city) AS T
GROUP BY city ORDER BY citycount DESC; 