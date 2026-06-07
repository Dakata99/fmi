-- I. За базата от данни MOVIES
USE MOVIES

-- 1. Напишете заявка, която извежда име на студио, адрес на студио, дължина и
-- заглавие на филм за тези филми, които са създадени след 1980 г. и името на
-- студиото започва с ‘M’.
SELECT s.NAME, s.ADDRESS, m.TITLE, m.LENGTH
FROM STUDIO s
    JOIN MOVIE m ON s.NAME = m.STUDIONAME
WHERE m.YEAR > 1980 AND s.NAME LIKE 'M%'

-- 2. Напишете заявка, която извежда име на актьор, адрес на актьор и заглавие на
-- филм за тези актьори, чието име започва с ‘J’ и са участвали във филми, създадени след 1990 г.
SELECT ms.NAME, ms.ADDRESS, s.MOVIETITLE
FROM MOVIESTAR ms
    JOIN STARSIN s ON s.STARNAME = ms.NAME
WHERE ms.NAME LIKE 'J%' AND s.MOVIEYEAR > 1990

-- 3. Да се напише заявка, която извежда имената и годините на всички филми,
-- които са по-дълги от 120 минути и са снимани преди 2000 г. Ако дължината на
-- филма е неизвестна, името и годината на този филм също да се изведат.
SELECT TITLE, YEAR, LENGTH
FROM MOVIE
WHERE LENGTH > 120 OR LENGTH IS NULL AND YEAR < 2000

-- 4. Да се напише заявка, която извежда имената и пола на всички актьори (мъже и жени), чието име започва 
-- с 'J' и са родени след 1948 година. Резултатът да бъде подреден по име в намаляващ ред.
SELECT ms.NAME, ms.GENDER
FROM MOVIESTAR ms
WHERE ms.NAME LIKE 'J%' AND YEAR(ms.BIRTHDATE) > 1948
ORDER BY ms.NAME DESC

-- 5. Напишете заявка, която извежда име на студио и брой на актьорите,
-- участвали във филми, които са създадени от това студио.
SELECT STUDIONAME, COUNT(DISTINCT s.STARNAME) AS #ACTORS
FROM MOVIE
    JOIN STARSIN s ON s.MOVIETITLE = TITLE AND s.MOVIEYEAR = YEAR
GROUP BY STUDIONAME

-- 6. Напишете заявка, която за всеки актьор извежда име на актьора и броя на
-- филмите, в които актьорът е участвал.
SELECT s.STARNAME, COUNT(s.MOVIETITLE) AS #FILMS
FROM MOVIE m
    JOIN STARSIN s ON s.MOVIETITLE = m.TITLE AND s.MOVIEYEAR = m.YEAR
GROUP BY s.STARNAME

-- 7. Напишете заявка, която за всяко студио извежда името на студиото и името
-- на филма, излязъл последно на екран за това студио.
-- CORRECT?
SELECT m.STUDIONAME, m.TITLE, m.YEAR
FROM MOVIE m
JOIN (  SELECT STUDIONAME, MAX(YEAR) AS YEAR
        FROM MOVIE
        GROUP BY STUDIONAME) res ON res.STUDIONAME = m.STUDIONAME AND res.YEAR = m.YEAR

-- 8. Да се напише заявка, която извежда имената на най-младия актьор (мъж).
SELECT NAME
FROM MOVIESTAR
WHERE BIRTHDATE = (SELECT MAX(BIRTHDATE)
                   FROM MOVIESTAR
                   WHERE GENDER = 'M')

-- 9. Напишете заявка, която извежда име на актьор и име на студио за тези
-- актьори, участвали в най-много филми на това студио.
-- ??
SELECT s.STARNAME, COUNT(s.STARNAME)
FROM MOVIE m
    JOIN STARSIN s ON m.TITLE = s.MOVIETITLE AND m.YEAR = s.MOVIEYEAR
GROUP BY s.STARNAME

-- 10. Да се напише заявка, която извежда името на филма, годината и броя на
-- актьорите, участвали в този филм за тези филми с повече от 2-ма актьори.
SELECT m.TITLE, m.YEAR, COUNT(s.STARNAME) AS #ACTORS
FROM MOVIE m
    JOIN STARSIN s ON m.TITLE = s.MOVIETITLE AND m.YEAR = s.MOVIEYEAR
GROUP BY m.TITLE, m.YEAR
HAVING COUNT(s.STARNAME) > 2

-- II. За базата от данни SHIPS
USE SHIPS

-- 1. Да се напише заявка, която извежда имената на всички кораби без повторения,
-- които са участвали в поне една битка и чиито имена започват с C или K.
SELECT DISTINCT SHIP
FROM OUTCOMES
WHERE SHIP LIKE 'C%' OR SHIP LIKE 'K%'
GROUP BY SHIP
HAVING COUNT(BATTLE) >= 1

-- 2. Да се напише заявка, която извежда име и държава на всички кораби, които
-- никога не са потъвали в битка (може и да не са участвали).
SELECT s.NAME, c.COUNTRY
FROM SHIPS s
    JOIN CLASSES c ON c.CLASS = s.CLASS
WHERE s.NAME NOT IN (   SELECT NAME
                        FROM SHIPS s
                            JOIN OUTCOMES o ON s.NAME = o.SHIP
                        WHERE o.RESULT = 'sunk')

-- 3. Да се напише заявка, която извежда държавата и броя на потъналите кораби
-- за тази държава. Държави, които нямат кораби или имат кораб, но той не е
-- участвал в битка, също да бъдат изведени.
SELECT c.COUNTRY, COUNT(o.SHIP)
FROM OUTCOMES o
    FULL OUTER JOIN SHIPS s ON o.SHIP = s.NAME
    FULL OUTER JOIN CLASSES c ON c.CLASS = s.CLASS
WHERE o.RESULT = 'sunk' OR s.NAME IS NULL OR s.NAME IS NOT NULL AND o.BATTLE IS NULL
        -- sunked or country has no ships or country has ships, but not battles
GROUP BY c.COUNTRY    

-- 4. Напишете заявка, която извежда имената на битките, които са по-мащабни (с
-- повече участващи кораби) от битката при Guadalcanal.

SELECT BATTLE
FROM OUTCOMES
GROUP BY BATTLE
HAVING COUNT(SHIP) > (  SELECT COUNT(SHIP)
                        FROM OUTCOMES
                        WHERE BATTLE = 'Guadalcanal')

-- 5. Напишете заявка, която извежда имената на битките, които са по-мащабни (с
-- повече участващи страни) от битката при Guadalcanal.
-- CORRECT?
SELECT o.BATTLE
FROM OUTCOMES o
    JOIN SHIPS s ON s.NAME = o.SHIP
    JOIN CLASSES c ON c.CLASS = s.CLASS
WHERE BATTLE != 'Guadalcanal'
GROUP BY o.BATTLE
HAVING COUNT(DISTINCT c.COUNTRY) > (SELECT COUNT(DISTINCT c.COUNTRY)
                                    FROM OUTCOMES o
                                        JOIN SHIPS s ON s.NAME = o.SHIP
                                        JOIN CLASSES c ON c.CLASS = s.CLASS
                                    WHERE BATTLE = 'Guadalcanal')

-- 6. Да се напише заявка, която извежда имената на най-тежките кораби с най-малко оръдия.
-- CORRECT?
SELECT s.NAME
FROM CLASSES c
    JOIN SHIPS s ON c.CLASS = s.CLASS
WHERE c.DISPLACEMENT = (SELECT MAX(DISPLACEMENT) FROM CLASSES) AND c.NUMGUNS = (SELECT MIN(NUMGUNS) FROM CLASSES)


-- 7. Изведете броя на корабите, които са били увредени в битка, но са били
-- поправени и по-късно са победили в друга битка.
SELECT COUNT(o1.SHIP) AS #SHIPS
FROM OUTCOMES o1
    JOIN BATTLES b1 ON o1.BATTLE = b1.NAME
    JOIN OUTCOMES o2 ON o2.SHIP = o1.SHIP
    JOIN BATTLES b2 ON o2.BATTLE = b2.NAME

-- 8. Изведете имената на корабите, които са били увредени в битка, но са били
-- поправени и по-късно са победили в по-мащабна битка (с повече кораби).
---??

-- III. За базата от данни PC
USE PC

-- 1. Да се напише заявка, която извежда всички модели лаптопи, за които се
-- предлагат както разновидности с 15" екран, така и с 11" екран.
SELECT MODEL, CODE, SCREEN
FROM LAPTOP
WHERE SCREEN = 15 OR SCREEN = 11

-- 2. Да се изведат различните модели компютри, чиято цена е по-ниска от най-
-- евтиния лаптоп, произвеждан от същия производител.
SELECT DISTINCT pc.MODEL
FROM PC pc
    JOIN PRODUCT p1 ON pc.MODEL = p1.MODEL
WHERE pc.PRICE < (  SELECT MIN(l.PRICE)
                    FROM LAPTOP l
                        JOIN PRODUCT p2 ON p2.MODEL = l.MODEL
                    WHERE p1.MAKER = p2.MAKER)

-- 3. Да се напише заявка, която извежда за всеки компютър код на продукта,
-- производител и брой компютри, които имат цена, по-голяма или равна на неговата.

-- ???

-- 4. Един модел компютри може да се предлага в няколко разновидности с евентуално различна цена. 
-- Да се изведат тези модели компютри, чиято средна цена (на различните му разновидности) е по-ниска 
-- от най-евтиния лаптоп, произвеждан от същия производител.

-- ??
