USE PC

-- 1.1. Напишете заявка, която извежда средната честота на компютрите

SELECT AVG(SPEED)
FROM PC

-- 1.2. Напишете заявка, която извежда средния размер на екраните на
-- лаптопите за всеки производител

SELECT MAKER, AVG(SCREEN)
FROM LAPTOP
    JOIN PRODUCT ON LAPTOP.MODEL = PRODUCT.MODEL
GROUP BY MAKER

-- 1.3. Напишете заявка, която извежда средната честота на лаптопите с цена над 1000

SELECT AVG(SPEED)
FROM LAPTOP
WHERE PRICE > 1000

-- 1.4. Напишете заявка, която извежда средната цена на компютрите 
-- произведени от производител ‘A’

SELECT AVG(PRICE) AveragePrice
FROM PC
    JOIN PRODUCT ON PC.MODEL = PRODUCT.MODEL
WHERE MAKER = 'A'

-- 1.5. Напишете заявка, която извежда средната цена на компютрите 
-- и лаптопите за производител ‘B’

SELECT AVG(PRICE) AveragePrice
FROM (  SELECT PRICE
        FROM PRODUCT p
            JOIN PC ON p.MODEL = PC.MODEL
        WHERE MAKER = 'B'
        UNION ALL
        SELECT PRICE
        FROM PRODUCT p
            JOIN LAPTOP ON p.MODEL = LAPTOP.MODEL
        WHERE MAKER = 'B') u

-- 1.6. Напишете заявка, която извежда средната цена на компютрите
-- според различните им честоти

SELECT SPEED, AVG(PRICE)
FROM PC
GROUP BY SPEED

-- 1.7. Напишете заявка, която извежда производителите, които са
-- произвели поне по 3 различни модела компютъра

SELECT MAKER
FROM PRODUCT
WHERE TYPE = 'PC'
GROUP BY MAKER
HAVING COUNT(*) >= 3

-- 1.8. Напишете заявка, която извежда производителите на компютрите с най-висока цена

SELECT DISTINCT MAKER
FROM PRODUCT
    JOIN PC ON PRODUCT.MODEL = PC.MODEL
WHERE PRICE = (SELECT MAX(PRICE) FROM PC)

-- 1.9. Напишете заявка, която извежда средната цена на компютрите 
-- за всяка честота по-голяма от 800

SELECT SPEED, AVG(PRICE) AveragePrice
FROM PC
WHERE SPEED > 800
GROUP BY SPEED

-- 1.10. Напишете заявка, която извежда средния размер на диска на 
-- тези компютри произведени от производители, които произвеждат -- и принтери

SELECT AVG(HD) AverageHD
FROM PRODUCT
    JOIN PC ON PRODUCT.MODEL = PC.MODEL
WHERE MAKER IN (SELECT MAKER
                FROM PRODUCT
                WHERE TYPE = 'Printer')

-- 1.11. Напишете заявка, която за всеки размер на лаптоп намира разликата 
-- в цената на най-скъпия и най-евтиния лаптоп със същия размер

SELECT SCREEN, MAX(PRICE) - MIN(PRICE) AS PriceDiff
FROM LAPTOP
GROUP BY SCREEN

USE SHIPS

-- 2.1. Напишете заявка, която извежда броя на класовете кораби

SELECT COUNT(*) AS ClassCount
FROM CLASSES

-- 2.2. Напишете заявка, която извежда средния брой на оръжия за 
-- всички кораби, пуснати на вода

SELECT AVG(NUMGUNS) AgerageGuns
FROM CLASSES c
    JOIN SHIPS s ON c.CLASS = s.CLASS

-- 2.3. Напишете заявка, която извежда за всеки клас първата и 
-- последната година, в която кораб от съответния клас е пуснат на вода

SELECT CLASS, MIN(LAUNCHED) AS FirstYear, MAX(LAUNCHED) AS LastYear
FROM SHIPS
GROUP BY CLASS

-- 2.4. Напишете заявка, която извежда броя на корабите потънали в битка -- според класа

-- ако не се интересуваме от класовете без потънали кораби и класовете без кораби

SELECT s.CLASS, COUNT(*) AS SunkCount
FROM SHIPS s
    JOIN OUTCOMES o ON s.NAME = o.SHIP
WHERE o.RESULT = 'sunk'
GROUP BY s.CLASS

-- ако се интересуваме от класовете без потънали кораби и класовете без кораби

-- решение 1

SELECT s.CLASS, COUNT(o.SHIP) AS SunkCount
FROM CLASSES c
    LEFT OUTER JOIN SHIPS s ON c.CLASS = s.CLASS
    LEFT OUTER JOIN OUTCOMES o ON s.NAME = o.SHIP AND o.RESULT = 'sunk'
GROUP BY s.CLASS

-- решение 2

SELECT c.CLASS, SUM(CASE o.RESULT WHEN 'sunk' THEN 1 ELSE 0 END) AS SunkCount
FROM CLASSES c
    LEFT OUTER JOIN SHIPS s ON c.CLASS = s.CLASS
    LEFT OUTER JOIN OUTCOMES o ON s.NAME = o.SHIP
GROUP BY c.CLASS

-- 2.5. Напишете заявка, която извежда броя на корабите потънали в битка 
-- според класа, за тези класове с повече от 4 пуснати на вода кораба

-- решение 1

SELECT s.CLASS, COUNT(s.NAME) ShipCount
FROM SHIPS s
    JOIN OUTCOMES o ON s.NAME = o.SHIP
WHERE o.RESULT = 'sunk' AND s.CLASS IN (SELECT CLASS
                                        FROM SHIPS
                                        GROUP BY CLASS
                                        HAVING COUNT(*) > 4)
GROUP BY s.CLASS

-- решение 2

SELECT s.CLASS, SUM(CASE o.RESULT WHEN 'sunk' THEN 1 ELSE 0 END) ShipCount
FROM SHIPS s
    LEFT OUTER JOIN OUTCOMES o ON s.NAME = o.SHIP
GROUP BY s.CLASS
HAVING COUNT(DISTINCT s.NAME) > 4

-- 2.6. Напишете заявка, която извежда средното тегло на корабите, за всяка страна.

SELECT COUNTRY, AVG(DISPLACEMENT) AVG_WEIGHT
FROM CLASSES
GROUP BY COUNTRY