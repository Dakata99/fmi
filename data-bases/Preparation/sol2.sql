USE MOVIES

-- 1.1. Напишете заявка, която извежда имената на актрисите, които са също и 
-- продуценти с нетна стойност по-голяма от 10 милиона.

SELECT NAME
FROM MOVIESTAR
WHERE GENDER = 'F' AND NAME IN (SELECT NAME
                                FROM MOVIEEXEC
                                WHERE NETWORTH > 10000000)

-- 1.2. Напишете заявка, която извежда имената на тези актьори (мъже и жени), които не са продуценти.

SELECT NAME
FROM MOVIESTAR
WHERE NAME NOT IN (SELECT NAME FROM MOVIEEXEC)

-- 1.3. Напишете заявка, която извежда имената на всички филми с 
-- дължина по-голяма от дължината на филма 'Gone With the Wind'

-- TITLE не е достатъчно за уникално идентифициране на филм в таблицата MOVIE. 
-- Необходима е двойка стойности (име на филм, година).

-- Интерпретация 1: филмите с дължина по-голяма от дължината на 'Gone With The Wind', 
-- правен през 1938 
SELECT TITLE
FROM MOVIE
WHERE LENGTH > (SELECT LENGTH FROM MOVIE WHERE TITLE = 'Gone With the Wind' AND YEAR = 1938)

-- Интерпретация 2: филмите с дължина по-голяма от дължината всички филми със заглавие 'Gone With The Wind'

SELECT TITLE
FROM MOVIE
WHERE LENGTH > ALL (SELECT LENGTH FROM MOVIE WHERE TITLE = 'Gone With the Wind')

-- Това ще работи само когато в базата има само един филм с име 'Gone With the Wind'. 
-- Иначе ще връща грешка.
SELECT TITLE
FROM MOVIE
WHERE LENGTH > (SELECT LENGTH FROM MOVIE WHERE TITLE = 'Gone With the Wind')

-- 1.4. Напишете заявка, която извежда имената на продуцентите и имената на 
-- продукциите за които стойността им е по-голяма от продукциите на продуцента 'Merv Griffin'

-- В базата MOVIES няма стойност на продукции и затова интерпретираме това условие като: 
-- Имената на продуцентите и продукциите, правени от продуценти с NETWORTH 
-- по-голям от NETWORTH-a на 'Merv Griffin'

SELECT NAME, TITLE
FROM MOVIE m
    JOIN MOVIEEXEC me ON m.PRODUCERC# = me.CERT#
WHERE me.NETWORTH > (SELECT NETWORTH FROM MOVIEEXEC WHERE NAME = 'Merv Griffin')

USE PC

-- 2.1. Напишете заявка, която извежда производителите на персонални компютри с честота поне 500.

SELECT DISTINCT MAKER
FROM PRODUCT
WHERE MODEL IN (SELECT MODEL FROM PC WHERE SPEED >= 500)

-- 2.2. Напишете заявка, която извежда принтерите с най-висока цена.

SELECT *
FROM PRINTER
WHERE PRICE >= ALL (SELECT PRICE FROM PRINTER)

-- 2.3. Напишете заявка, която извежда лаптопите, чиято честота е по-ниска от 
-- честотата на който и да е персонален компютър (по-ниска от поне един).

SELECT *
FROM LAPTOP
WHERE SPEED < ANY (SELECT SPEED FROM PC)

-- по-ниска от тази на всички PC-та:

SELECT *
FROM LAPTOP
WHERE SPEED < ALL (SELECT SPEED FROM PC)

-- 2.4. Напишете заявка, която извежда модела на продукта (PC, лаптоп или принтер) с най-висока цена.

SELECT DISTINCT MODEL
FROM (  SELECT MODEL, PRICE
        FROM PC
        UNION
        SELECT MODEL, PRICE
        FROM LAPTOP
        UNION
        SELECT MODEL, PRICE
        FROM PRINTER) t
WHERE PRICE >= ALL (SELECT PRICE FROM PC
                    UNION
                    SELECT PRICE FROM LAPTOP
                    UNION
                    SELECT PRICE FROM PRINTER)

-- 2.5. Напишете заявка, която извежда производителя на цветния принтер с най-ниска цена.

SELECT DISTINCT MAKER
FROM PRODUCT
WHERE MODEL IN (SELECT MODEL
                FROM PRINTER
                WHERE color = 'y' AND PRICE <= ALL (SELECT PRICE FROM PRINTER WHERE color = 'y'))

SELECT DISTINCT MAKER
FROM PRODUCT p
    JOIN (  SELECT MODEL
            FROM PRINTER
            WHERE color = 'y' AND PRICE <= ALL (SELECT PRICE FROM PRINTER WHERE color = 'y') ) cm ON p.MODEL = cm.MODEL

-- 2.6. Напишете заявка, която извежда производителите на тези 
-- персонални компютри с най-малко RAM памет, които имат най-бързи процесори.

SELECT DISTINCT MAKER
FROM PRODUCT
WHERE MODEL IN (SELECT MODEL
                FROM PC p1
                WHERE RAM <= ALL (SELECT RAM FROM PC) AND SPEED >= ALL (SELECT SPEED
                                                                        FROM PC p2
                                                                        WHERE p1.RAM = p2.RAM))

USE SHIPS

-- 3.1. Напишете заявка, която извежда страните, чиито кораби са с най-голям брой оръжия.

SELECT DISTINCT COUNTRY
FROM CLASSES
WHERE NUMGUNS >= ALL (SELECT NUMGUNS FROM CLASSES)

-- 3.2. Напишете заявка, която извежда класовете, за които поне един от корабите им е потънал в битка.

SELECT DISTINCT CLASS
FROM SHIPS
WHERE NAME IN ( SELECT SHIP
                FROM OUTCOMES
                WHERE RESULT = 'sunk')

-- 3.3. Напишете заявка, която извежда имената на корабите с 16 инчови оръдия (bore).

SELECT NAME
FROM SHIPS
WHERE CLASS IN (SELECT CLASS
                FROM CLASSES
                WHERE BORE = 16)

-- 3.4. Напишете заявка, която извежда имената на битките, в които са участвали кораби от клас ‘Kongo’.

SELECT BATTLE
FROM OUTCOMES
WHERE SHIP IN ( SELECT NAME
                FROM SHIPS
                WHERE CLASS = 'Kongo')

-- 3.5. Напишете заявка, която извежда имената на корабите, чиито брой оръдия е 
-- най-голям в сравнение с корабите със същия калибър оръдия (bore).

SELECT NAME
FROM SHIPS s
    JOIN CLASSES c1 ON s.CLASS = c1.CLASS
WHERE c1.NUMGUNS >= ALL (   SELECT NUMGUNS
                            FROM CLASSES c2
                            WHERE c1.BORE = c2.BORE)

SELECT NAME FROM SHIPS
WHERE CLASS IN (SELECT CLASS
                FROM CLASSES c1
                WHERE c1.NUMGUNS >= ALL (   SELECT NUMGUNS
                                            FROM CLASSES c2
                                            WHERE c1.BORE = c2.BORE))