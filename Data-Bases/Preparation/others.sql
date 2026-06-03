-- 1. За всяка филмова звезда да се изведе името, рождената дата и с кое 
-- студио е записвала най-много филми. (Ако има две студиа с еднакъв 
-- брой филми, да се изведе кое да е от тях)

USE MOVIES

SELECT ms.NAME, ms.BIRTHDATE, ( SELECT TOP 1 m.STUDIONAME
                                FROM STARSIN si
                                    JOIN MOVIE m ON si.MOVIETITLE = m.TITLE AND si.MOVIEYEAR = m.YEAR
                                WHERE si.STARNAME = ms.NAME
                                GROUP BY m.STUDIONAME
                                ORDER BY COUNT(*) DESC) AS STUDIO
FROM MOVIESTAR ms

-- 2. Да се изведат всички производители, за които средната цена на 
-- произведените компютри е по-ниска от средната цена на техните лаптопи.

USE PC

SELECT p.MAKER
FROM PRODUCT p
    JOIN PC pc1 ON p.MODEL = pc1.MODEL
GROUP BY p.MAKER
HAVING AVG(pc1.PRICE) < (SELECT AVG(l.PRICE)
                        FROM PRODUCT p2
                            JOIN LAPTOP l ON p2.MODEL = l.MODEL
                        WHERE p2.MAKER = p.MAKER)

-- 3. Един модел компютри може да се предлага в няколко конфигурации 
-- с евентуално различна цена. Да се изведат тези модели компютри, 
-- чиято средна цена (на различните му конфигурации) е по-ниска 
-- от най-евтиния лаптоп, произвеждан от същия производител.

SELECT p.MODEL
FROM PRODUCT p
    JOIN PC pc1 ON p.MODEL = pc1.MODEL
GROUP BY p.MODEL, p.MAKER
HAVING AVG(pc1.PRICE) < (   SELECT MIN(l.PRICE)
                            FROM PRODUCT p2
                                JOIN LAPTOP l ON p2.MODEL = l.MODEL
                            WHERE p2.MAKER = p.MAKER)

USE SHIPS

-- 4. Битките, в които са участвали поне 3 кораба на една и съща страна.

SELECT DISTINCT o.BATTLE
FROM OUTCOMES o
    JOIN SHIPS s ON o.SHIP = s.NAME
    JOIN CLASSES c ON c.CLASS = s.CLASS
GROUP BY o.BATTLE, c.COUNTRY
HAVING COUNT(*) >= 3

-- 5. За всеки кораб да се изведе броят на битките, в които е бил увреден. 
-- Ако корабът не е участвал в битки или пък никога не е бил 
-- увреждан, в резултата да се вписва 0.

SELECT s.NAME, COUNT(o.RESULT)
FROM SHIPS s
    LEFT OUTER JOIN OUTCOMES o ON s.NAME = o.SHIP AND o.RESULT = 'damaged'
GROUP BY s.NAME

-- 6. За всеки клас да се изведе името, държавата и първата година, в която 
-- е пуснат кораб от този клас

SELECT c.CLASS, c.COUNTRY, MIN(s.LAUNCHED) AS FIRST_YEAR
FROM CLASSES c
    LEFT OUTER JOIN SHIPS s ON c.CLASS = s.CLASS
GROUP BY c.CLASS, c.COUNTRY

-- 6.1. но да извличаме и името на корабите

SELECT c.CLASS, s.NAME, s.LAUNCHED
FROM CLASSES c
    LEFT OUTER JOIN SHIPS s ON c.CLASS = s.CLASS
    LEFT OUTER JOIN (SELECT CLASS, MIN(LAUNCHED) MINLAUNCHED
                    FROM SHIPS GROUP BY CLASS) y ON c.CLASS = y.CLASS
WHERE s.LAUNCHED IS NULL OR s.LAUNCHED = y.MINLAUNCHED

-- 7. За всяка държава да се изведе броят на корабите и броят на потъналите 
-- кораби. Всяка от бройките може да бъде и нула.

SELECT c.COUNTRY, COUNT(s.NAME), COUNT(o.RESULT)
FROM CLASSES c
    LEFT OUTER JOIN SHIPS s ON c.CLASS = s.CLASS
    LEFT OUTER JOIN OUTCOMES o ON o.SHIP = s.NAME AND o.RESULT = 'sunk'
GROUP BY c.COUNTRY

-- 8. Намерете за всеки клас с поне 3 кораба броя на корабите от този клас, които са с резултат ok.

SELECT s.CLASS, COUNT(DISTINCT o.SHIP)
FROM SHIPS s
    LEFT OUTER JOIN OUTCOMES o ON s.NAME = o.SHIP AND o.RESULT = 'ok'
GROUP BY s.CLASS
HAVING COUNT(DISTINCT s.NAME) >= 3

-- 9. За всяка битка да се изведе името на битката, годината на 
-- битката и броят на потъналите кораби, броят на повредените 
-- кораби и броят на корабите без промяна.

SELECT o.BATTLE, YEAR(b.DATE) BATTLE_YEAR, SUM(CASE o.RESULT WHEN 'sunk' THEN 1 ELSE 0 END) AS SUNK_COUNT, 
                                        SUM(CASE o.RESULT WHEN 'damaged' THEN 1 ELSE 0 END) AS DAMAGED_COUNT, 
                                        SUM(CASE o.RESULT WHEN 'ok' THEN 1 ELSE 0 END) AS OK_COUNT
FROM OUTCOMES o
    JOIN BATTLES b ON o.BATTLE = b.NAME
GROUP BY o.BATTLE, b.DATE

-- 10. Да се изведат имената на корабите, които са участвали в битки в продължение поне на две години.

SELECT o.SHIP
FROM BATTLES b
    JOIN OUTCOMES o ON b.NAME = o.BATTLE
GROUP BY o.SHIP
HAVING YEAR(MAX(b.DATE)) - YEAR(MIN(b.DATE)) >= 1

-- 11. За всеки потънал кораб колко години са минали от пускането му на вода до потъването.

SELECT o.SHIP, YEAR(b.DATE) - s.LAUNCHED AS YEARS_PASSED
FROM OUTCOMES o
    JOIN BATTLES b ON o.BATTLE = b.NAME
    JOIN SHIPS s ON s.NAME = o.SHIP
WHERE o.RESULT = 'sunk'

-- В базата има дефектни данни за Hood и "Yamashiro

-- 12. Имената на класовете, за които няма кораб, пуснат на вода след 1921 г., 
-- но имат пуснат поне един кораб.

SELECT CLASS
FROM SHIPS
GROUP BY CLASS
HAVING MAX(LAUNCHED) <= 1921