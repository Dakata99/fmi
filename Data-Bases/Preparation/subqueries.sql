-- I.За базата от данни Movies
USE MOVIES

-- 1. Напишете заявка, която извежда имената на актрисите, които са също и
-- продуценти с нетни активи над 10 милиона.
SELECT NAME
FROM MOVIESTAR
WHERE GENDER = 'F' AND NAME IN (SELECT NAME
                                FROM MOVIEEXEC
                                WHERE NETWORTH > 10000000)

-- 2. Напишете заявка, която извежда имената на тези актьори (мъже и жени), които не са продуценти.
SELECT NAME
FROM MOVIESTAR
WHERE NAME NOT IN ( SELECT NAME
                    FROM MOVIEEXEC)

-- 3. Напишете заявка, която извежда имената на всички филми с дължина,
-- по-голяма от дължината на филма ‘Star Wars’
SELECT TITLE
FROM MOVIE
WHERE LENGTH > ALL(SELECT LENGTH
                   FROM MOVIE
                   WHERE TITLE = 'Star Wars')

-- 4. Напишете заявка, която извежда имената на продуцентите и имената
-- филмите за всички филми, които са продуцирани от продуценти с нетни
-- активи (networth) по-големи от тези на ‘Merv Griffin’.
SELECT 

