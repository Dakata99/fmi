-- I.За базата от данни Movies
USE MOVIES

-- 1. Напишете заявка, която извежда адреса на студио ‘MGM’
SELECT DISTINCT ADDRESS
FROM STUDIO
WHERE NAME = 'MGM'

-- 2. Напишете заявка, която извежда рождената дата на актрисата Sandra Bullock
SELECT BIRTHDATE
FROM MOVIESTAR
WHERE NAME = 'Sandra Bullock'

-- 3. Напишете заявка, която извежда имената на всички актьори, които са
-- участвали във филм през 1980 в заглавието, на който има думата ‘Empire’
SELECT STARNAME
FROM STARSIN
WHERE MOVIETITLE LIKE '%Empire%' AND MOVIEYEAR = 1980

-- 4. Напишете заявка, която извежда имената всички продуценти на филми с
-- нетни активи (networth) над 10 000 000 долара
SELECT NAME
FROM MOVIEEXEC
WHERE NETWORTH > 10000000

-- 5. Напишете заявка, която извежда имената на всички актьори, които са мъже или живеят на Prefect Rd.
SELECT NAME
FROM MOVIESTAR
WHERE GENDER = 'M' OR ADDRESS = 'Prefect Rd.'

-- II.За базата от данни PC
USE PC

-- 1. Напишете заявка, която извежда номер на модел, честота (SPEED) и размер
-- на диска за всички компютри с цена по-малка от 1200 долара. Задайте
-- псевдоними за атрибутите честота и размер на диска, съответно MHz и GB
SELECT MODEL, SPEED AS MHz, HD AS GB
FROM PC
WHERE PRICE < 1200

-- 2. Напишете заявка, която извежда всички производители на принтери без повторения.
SELECT DISTINCT MAKER
FROM PRODUCT
WHERE TYPE = 'Printer'

-- 3. Напишете заявка, която извежда номер на модел, размер на паметта,
-- размер на екран за лаптопите, чиято цена е по-голяма от 1000 долара
SELECT MODEL, HD, SCREEN
FROM LAPTOP
WHERE PRICE > 1000

-- 4. Напишете заявка, която извежда всички цветни принтери
SELECT *
FROM PRINTER
WHERE COLOR = 'y'

-- 5. Напишете заявка, която извежда номер на модел, честота и размер на диска
-- за тези компютри със CD 12x или 16x и цена по-малка от 2000 долара.
SELECT MODEL, SPEED, HD
FROM PC
WHERE CD = '12x' OR CD = '16x' AND PRICE < 2000

-- III.За базата от данни SHIPS
USE SHIPS

-- 1. Напишете заявка, която извежда името на класа и страната за всички
-- класове с брой на оръдията по-малък от 10.
SELECT CLASS, COUNTRY
FROM CLASSES
WHERE NUMGUNS < 10

-- 2. Напишете заявка, която извежда имената на всички кораби, пуснати на вода
-- преди 1918. Задайте псевдоним на колоната shipName.
SELECT NAME AS SHIPNAME
FROM SHIPS
WHERE LAUNCHED < 1918

-- 3. Напишете заявка, която извежда имената на корабите потънали в битка и
-- имената на битките, в които са потънали.
SELECT SHIP, BATTLE
FROM OUTCOMES
WHERE RESULT = 'sunk'

-- 4. Напишете заявка, която извежда имената на корабите с име, съвпадащо с името на техния клас.
SELECT NAME
FROM SHIPS
WHERE NAME = CLASS

-- 5. Напишете заявка, която извежда имената на всички кораби, започващи с буквата R.
SELECT NAME
FROM SHIPS
WHERE NAME LIKE 'R%'