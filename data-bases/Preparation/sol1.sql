USE MOVIES

-- 1.1. Напишете заявка, която извежда имената на актьорите мъже, участвали в ‘Terms of Endearment’

SELECT DISTINCT NAME
FROM MOVIESTAR
    JOIN STARSIN ON NAME = STARNAME
WHERE MOVIETITLE = 'Terms of Endearment' AND GENDER = 'M'

-- 1.2. Напишете заявка, която извежда имената на актьорите, участвали във филми, продуцирани от ‘MGM’ през 1995 г.

SELECT DISTINCT STARNAME
FROM MOVIE
    JOIN STARSIN ON TITLE = MOVIETITLE AND YEAR = MOVIEYEAR
WHERE STUDIONAME = 'MGM' AND YEAR = 1995

-- 1.3. Напишете заявка, която извежда името на президента на ‘MGM’

SELECT me.NAME
FROM STUDIO s
    JOIN MOVIEEXEC me ON s.PRESC# = me.CERT#
WHERE s.NAME = 'MGM'

-- 1.4. Напишете заявка, която извежда имената на всички филми с дължина, по-голяма
-- от дължината на филма ‘Star Wars’

-- (В таблицата MOVIE, може да има различни филми с едно и също име, ако са правени
-- в различни години). Предвид, че в условието се говори за единствен филм - смятаме,
-- че става въпрос за този, който е сниман през 1977 и го указваме в заявката.

SELECT m1.TITLE
FROM MOVIE m1
    JOIN MOVIE m2 ON m2.TITLE = 'Star Wars' AND m2.YEAR = 1977
WHERE m1.LENGTH > m2.LENGTH

USE PC

-- 2.1. Напишете заявка, която извежда производителя и честотата на процесора на тези
-- лаптопи с размер на диска поне 9 GB

SELECT MAKER, SPEED
FROM PRODUCT p
    JOIN LAPTOP l ON p.MODEL = l.MODEL
WHERE HD >= 9

-- 2.2. Напишете заявка, която извежда номер на модел и цена на всички продукти,
-- произведени от производител с име ‘B’. Сортирайте резултата така, че първо да
-- се изведат най-скъпите продукти

SELECT u.MODEL, u.PRICE
FROM PRODUCT p 
    JOIN (  SELECT MODEL, PRICE
            FROM PC
            UNION
            SELECT MODEL, PRICE
            FROM LAPTOP
            UNION
            SELECT MODEL, PRICE
            FROM PRINTER) u ON p.MODEL = u.MODEL
WHERE p.MAKER = 'B'
ORDER BY PRICE DESC

SELECT PC.MODEL, PRICE
FROM PC
    JOIN PRODUCT ON PC.MODEL = PRODUCT.MODEL
WHERE PRODUCT.MAKER = 'B'
UNION
SELECT LAPTOP.MODEL, PRICE
FROM LAPTOP
    JOIN PRODUCT ON LAPTOP.MODEL = PRODUCT.MODEL
WHERE PRODUCT.MAKER = 'B'
UNION
SELECT PRINTER.MODEL, PRICE
FROM PRINTER
    JOIN PRODUCT ON PRINTER.MODEL = PRODUCT.MODEL
WHERE PRODUCT.MAKER = 'B'
ORDER BY PRICE DESC

-- 2.3. Напишете заявка, която извежда размерите на тези дискове, които се предлагат в 
-- поне два компютъра

SELECT DISTINCT p1.HD
FROM PC p1
    JOIN PC p2 ON p1.CODE != p2.CODE
WHERE p1.HD = p2.HD

-- 2.4. Напишете заявка, която извежда всички двойки модели на компютри, които имат
-- еднаква честота и памет. Двойките трябва да се показват само по веднъж,
-- например само (i, j), но не и (j, i)

SELECT p1.MODEL, p2.MODEL
FROM PC p1
    JOIN PC p2 ON p1.MODEL < p2.MODEL
WHERE p1.RAM = p2.RAM AND p1.SPEED = p2.SPEED

-- 2.5. Напишете заявка, която извежда производителите на поне два различни
-- компютъра с честота на процесора поне 500 MHz.

SELECT DISTINCT p1.MAKER
FROM PC pc1
    JOIN PC pc2 ON pc1.CODE != pc2.CODE
    JOIN PRODUCT p1 ON pc1.MODEL = p1.MODEL
    JOIN PRODUCT p2 ON pc2.MODEL = p2.MODEL
WHERE pc1.SPEED >= 500 AND pc2.SPEED >= 500 AND p1.MAKER = p2.MAKER

USE SHIPS

-- 3.1. Напишете заявка, която извежда името на корабите, по-тежки (displacement) от 35000

SELECT s.NAME 
FROM SHIPS s
    JOIN CLASSES c ON s.CLASS = c.CLASS
WHERE c.DISPLACEMENT > 35000

-- 3.2. Напишете заявка, която извежда имената, водоизместимостта и броя оръдия на 
-- всички кораби, участвали в битката при ‘Guadalcanal’

SELECT s.NAME, c.DISPLACEMENT, c.NUMGUNS
FROM SHIPS s
    JOIN CLASSES c ON s.CLASS = c.CLASS
    JOIN OUTCOMES o ON s.NAME = o.SHIP
WHERE o.BATTLE = 'Guadalcanal'

-- 3.3. Напишете заявка, която извежда имената на тези държави, които имат класове 
-- кораби от тип ‘bb’ и ‘bc’ едновременно

SELECT DISTINCT c1.COUNTRY
FROM CLASSES c1
    JOIN CLASSES c2 ON c1.COUNTRY = c2.COUNTRY
WHERE c1.TYPE = 'bb' AND c2.TYPE = 'bc'

-- 3.4. Напишете заявка, която извежда имената на тези кораби, които са били 
-- повредени в една битка, но по-късно са участвали в друга битка.

SELECT o1.SHIP
FROM OUTCOMES o1
    JOIN BATTLES b1 ON o1.BATTLE = b1.NAME
    JOIN OUTCOMES o2 ON o1.SHIP = o2.SHIP
    JOIN BATTLES b2 ON o2.BATTLE = b2.NAME
WHERE o1.RESULT = 'damaged' AND b1.DATE < b2.DATE