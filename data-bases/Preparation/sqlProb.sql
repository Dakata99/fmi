-- 1. Без повторение заглавията и годините на всички филми, заснети преди 1982, в които е играл
-- поне един актьор (актриса), чието име не съдържа нито буквата 'k', нито 'b'. Първо да се изведат
-- най-старите филми.

SELECT DISTINCT TITLE, YEAR
FROM MOVIE
    JOIN STARSIN sin ON sin.MOVIETITLE = TITLE
WHERE YEAR < 1982 AND sin.STARNAME NOT LIKE '%k%' AND sin.STARNAME NOT LIKE '%b%'
ORDER BY YEAR DESC

-- 2. Заглавията и дължините в часове (length е в минути) на всички филми, които са от същата
-- година, от която е и филмът Terms of Endearment, но дължината им е по-малка или неизвестна.
SELECT DISTINCT m1.TITLE, m1.LENGTH / 60 AS HOURS
FROM MOVIE m1
    JOIN MOVIE m2 ON m2.TITLE = 'Terms of Endearment'
WHERE m1.LENGTH < m2.LENGTH OR m1.LENGTH IS NULL

-- 3. Имената на всички продуценти, които са и филмови звезди и са играли в поне един филм
-- преди 1980 г. и поне един след 1985 г.
SELECT NAME
FROM MOVIEEXEC
    JOIN STARSIN ON NAME = STARNAME
WHERE MOVIEYEAR < 1980 AND MOVIEYEAR > 1985

-- TODO: check all above

-- 4. Всички черно-бели филми, записани преди най-стария цветен филм (InColor='y'/'n') на същото студио.
SELECT DISTINCT *
FROM MOVIE
WHERE INCOLOR = 'n' AND YEAR > (SELECT MIN(YEAR)
                                FROM MOVIE
                                WHERE INCOLOR = 'y')

SELECT *
FROM MOVIE m1

-- 5. Имената и адресите на студиата, които са работили с по-малко от 5 различни филмови звезди.
-- (напр. ако студиото има два филма, като в първия са играли A, B и C, а във втория - C, D и Е, то
-- студиото е работило с 5 звезди общо)
-- Студиа, за които няма посочени филми или има, но не се знае кои актьори са играли в тях, също
-- да бъдат изведени. Първо да се изведат студиата, работили с най-много звезди.


-- 6. За всеки кораб, който е от клас с име, несъдържащо буквите i и k, да се изведе името
-- на кораба и през коя година е пуснат на вода (launched). Резултатът да бъде сортиран
-- така, че първо да се извеждат най-скоро пуснатите кораби.
SELECT DISTINCT s.NAME, s.LAUNCHED
FROM CLASSES c
    JOIN SHIPS s ON c.CLASS = s.CLASS
WHERE c.CLASS NOT LIKE '%i%' AND c.CLASS NOT LIKE '%k%'
ORDER BY s.LAUNCHED DESC

-- 7. Да се изведат имената на всички битки, в които е повреден (damaged) поне един японски кораб.
SELECT *
FROM OUTCOMES
    JOIN SHIPS s ON s.NAME = SHIP
    JOIN CLASSES c ON s.CLASS = c.CLASS
WHERE RESULT = 'damaged' AND c.COUNTRY = 'Japan'

-- 8. Да се изведат имената и класовете на всички кораби, пуснати на вода една година след
-- кораба 'Rodney' и броят на оръдията им е по-голям от средния брой оръдия на
-- класовете, произвеждани от тяхната страна.

-- 9. Да се изведат американските класове, за които всички техни кораби са пуснати на вода
-- в рамките на поне 10 години (например кораби от клас North Carolina са пускани в
-- периода от 1911 до 1941, което е повече от 10 години, докато кораби от клас Tennessee
-- са пуснати само през 1920 и 1921 г.).

-- 10. За всяка битка да се изведе средният брой кораби от една и съща държава (например в
-- битката при Guadalcanal са участвали 3 американски и един японски кораб, т.е.
-- средният брой е 2).

-- 11. За всяка държава да се изведе: броят на корабите от тази държава; броя на битките, в
-- които е участвала; броя на битките, в които неин кораб е потънал ('sunk') (ако някоя от
-- бройките е 0 – да се извежда 0).

-- 12. За всеки актьор/актриса изведете броя на различните студиа, с които са записвали филми.

-- 13. За всеки актьор/актриса изведете броя на различните студиа, с които са записвали филми,
-- включително и за тези, за които нямаме информация в какви филми са играли.

-- 14. Изведете имената на актьорите, участвали в поне 3 филма след 1990 г.
SELECT STARNAME
FROM STARSIN
WHERE MOVIEYEAR > 1990
GROUP BY STARNAME
HAVING COUNT(*) >= 3

-- 15. Да се изведат различните модели компютри, подредени по цена на най-скъпия конкретен
-- компютър от даден модел.

-- 16. Изведете броя на потъналите американски кораби за всяка проведена битка с поне един
-- потънал американски кораб.

-- 17. Битките, в които са участвали поне 3 кораба на една и съща страна.
USE SHIPS

SELECT DISTINCT BATTLE
FROM SHIPS s
    JOIN CLASSES c ON c.CLASS = s.CLASS
    JOIN OUTCOMES o ON s.NAME = o.SHIP
GROUP BY BATTLE, c.COUNTRY
HAVING COUNT(*) >= 3

-- 18. Имената на класовете, за които няма кораб, пуснат на вода след 1921 г., но имат пуснат поне
-- един кораб.
SELECT CLASS
FROM SHIPS
GROUP BY CLASS
HAVING MAX(LAUNCHED) <= 1921

-- 19. (*) За всеки кораб намерете броя на битките, в които е бил увреден. Ако корабът не е
-- участвал в битки или пък никога не е бил увреждан, в резултата да се вписва 0.
SELECT s.NAME, COUNT(o.RESULT)
FROM SHIPS s
    LEFT OUTER JOIN OUTCOMES o ON s.NAME = o.SHIP AND o.RESULT = 'damaged'
GROUP BY s.NAME

-- 20. (*) Намерете за всеки клас с поне 3 кораба броя на корабите от този клас, които са победили
-- в битка.
SELECT s.CLASS, COUNT(o.RESULT) AS WINS
FROM SHIPS s
    LEFT JOIN (SELECT * FROM OUTCOMES WHERE RESULT = 'ok') o ON o.SHIP = s.NAME
GROUP BY s.CLASS
HAVING COUNT(s.CLASS) > 3
ORDER BY CLASS