-- Заявки в SQL върху две и повече релации - задачи

-- I.За базата от данни Movies
USE MOVIES

-- 1. Напишете заявка, която извежда имената на актьорите мъже, участвали в ‘Terms of Endearment’.
SELECT NAME
FROM STARSIN
    JOIN MOVIESTAR ON NAME = STARNAME
WHERE GENDER = 'M' AND MOVIETITLE = 'Terms of Endearment'

-- 2. Напишете заявка, която извежда имената на актьорите, участвали във филми,
-- продуцирани от студио ‘MGM’ през 1995 г.
SELECT STARNAME
FROM MOVIE
    JOIN STARSIN ON TITLE = MOVIETITLE
WHERE STUDIONAME = 'MGM' AND YEAR = 1995

-- 3. Напишете заявка, която извежда имената на продуцентите, които са продуцирали филми на студио ‘MGM’.
SELECT DISTINCT NAME
FROM MOVIE
    JOIN MOVIEEXEC ON PRODUCERC# = CERT#
WHERE STUDIONAME = 'MGM'

-- 4. Напишете заявка, която извежда имената на всички филми с дължина, по-голяма от дължината 
-- на филма ‘Star Wars’.
SELECT DISTINCT m1.TITLE
FROM MOVIE m1
    JOIN MOVIE m2 ON m2.TITLE = 'Star Wars' AND m2.YEAR = 1977 -- ако има 2 филма Star Wars през различни години
WHERE m1.LENGTH > m2.LENGTH

-- 5. Напишете заявка, която извежда имената на продуцентите с нетни активи
-- (networth) по-големи от тези на ‘Merv Griffin’.
SELECT me1.NAME
FROM MOVIEEXEC me1
    JOIN MOVIEEXEC me2 ON me2.NAME = 'Merv Griffin'
WHERE me1.NETWORTH > me2.NETWORTH

-- 6. Напишете заявка, която извежда имената на всички филми, които са
-- продуцирани от продуценти с нетни активи (networth) по-големи от тези на ‘Merv Griffin’.
SELECT DISTINCT TITLE
FROM MOVIE
    JOIN MOVIEEXEC me1 ON PRODUCERC# = CERT#
    JOIN MOVIEEXEC me2 ON me2.NAME = 'Merv Griffin'
WHERE me1.NETWORTH > me2.NETWORTH

-- II.За базата от данни PC
USE PC

-- 1. Напишете заявка, която извежда производителя и честотата (SPEED) на тези
-- лаптопи с размер на диска поне 9 GB.
SELECT MAKER, SPEED
FROM LAPTOP l
    JOIN PRODUCT p ON l.MODEL = p.MODEL
WHERE l.HD > 9

-- 2. Напишете заявка, която извежда номер на модел и цена на всички продукти,
-- произведени от производител с име ‘B’.
SELECT PC.MODEL, PC.PRICE
FROM PC PC
    JOIN PRODUCT p ON PC.MODEL = p.MODEL
WHERE p.MAKER = 'B'
UNION
SELECT l.MODEL, l.PRICE
FROM LAPTOP l
    JOIN PRODUCT p ON l.MODEL = p.MODEL
WHERE p.MAKER = 'B'
UNION
SELECT pr.MODEL, pr.PRICE
FROM PRINTER pr
    JOIN PRODUCT p ON pr.MODEL = p.MODEL
WHERE p.MAKER = 'B'

-- 3. Напишете заявка, която извежда размерите на тези дискове, които се предлагат
-- в поне два различни компютъра (два компютъра с различен код).
SELECT DISTINCT p1.HD
FROM PC p1
    JOIN PC p2 ON p1.CODE != p2.CODE
WHERE p1.HD = p2.HD

-- 4. Напишете заявка, която извежда всички двойки модели на компютри, които имат
-- еднаква честота и памет. Двойките трябва да се показват само по веднъж,
-- например само (i, j), но не и (j, i).
SELECT p1.MODEL, p2.MODEL
FROM PC p1
    JOIN PC p2 ON p1.MODEL < p2.MODEL
WHERE p1.RAM = p2.RAM AND p1.SPEED = p2.SPEED

SELECT p1.MODEL, p2.MODEL
FROM PC p1
    JOIN PC p2 ON p1.MODEL < p2.MODEL
WHERE p1.RAM = p2.RAM AND p1.SPEED = p2.SPEED

-- 5. Напишете заявка, която извежда производителите на поне два различни компютъра с честота поне 400.
SELECT DISTINCT p.MAKER
FROM PRODUCT p
    JOIN PC PC ON PC.MODEL = p.MODEL
WHERE PC.SPEED >= 400

-- III.За базата от данни SHIPS
USE SHIPS

-- 1. Напишете заявка, която извежда името на корабите с водоизместимост над 50000.
SELECT s.NAME
FROM SHIPS s
    JOIN CLASSES c ON c.CLASS = s.CLASS
WHERE c.DISPLACEMENT > 50000

-- 2. Напишете заявка, която извежда имената, водоизместимостта и броя оръдия на
-- всички кораби, участвали в битката при ‘Guadalcanal’.
SELECT s.NAME, c.DISPLACEMENT, c.NUMGUNS
FROM SHIPS s
    JOIN CLASSES c ON c.CLASS = s.CLASS
    JOIN OUTCOMES o ON s.NAME = o.SHIP
WHERE BATTLE = 'Guadalcanal'


-- 3. Напишете заявка, която извежда имената на тези държави, които имат кораби
-- от тип ‘bb’ и ‘bc’ едновременно.
SELECT DISTINCT c1.COUNTRY
FROM CLASSES c1
    JOIN CLASSES c2 ON c1.COUNTRY = c2.COUNTRY
WHERE c1.TYPE = 'bb' AND c2.TYPE = 'bc'

-- 4. Напишете заявка, която извежда имената на тези кораби, които са били
-- повредени в една битка, но по-късно са участвали в друга битка.
SELECT o1.SHIP
FROM OUTCOMES o1
    JOIN BATTLES b1 ON o1.BATTLE = b1.NAME
    JOIN OUTCOMES o2 ON o1.SHIP = o2.SHIP
    JOIN BATTLES b2 ON o2.BATTLE = b2.NAME
WHERE o1.RESULT = 'damaged' AND b1.DATE < b2.DATE
