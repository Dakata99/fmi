USE SHIPS
-- За всяка държава - имената на корабите, които никога не са участвали в битка.

SELECT c.COUNTRY, s.NAME
FROM SHIPS s
    JOIN CLASSES c ON s.CLASS = c.CLASS
WHERE NAME NOT IN (SELECT SHIP FROM OUTCOMES)

SELECT c.COUNTRY, s.NAME
FROM CLASSES c
    JOIN SHIPS s ON c.CLASS = s.CLASS
    LEFT OUTER JOIN OUTCOMES o ON s.NAME = o.SHIP
WHERE o.SHIP IS NULL

-- За всеки клас - име, държава, имена на всички негови кораби, пуснати през 1916 г.
-- Ако някой клас няма такива кораби, също да присъстват в резултата с NULL
SELECT c.CLASS, c.COUNTRY, s.*
FROM CLASSES c
    LEFT OUTER JOIN SHIPS s ON c.CLASS = s.CLASS AND s.LAUNCHED = 1916

-- За всеки клас британски кораби - името на класа и имената на 
-- всички битки, в които са участвали кораби от този клас
-- Ако няма - да ги има в резултата със стойност NULL за битка
SELECT c.CLASS, o.BATTLE
FROM OUTCOMES o
    JOIN SHIPS s ON o.SHIP = s.NAME
    RIGHT OUTER JOIN CLASSES c ON s.CLASS = c.CLASS
WHERE c.COUNTRY = 'Gt.Britain'

USE MOVIES

-- NAME, BIRTHDATE, NETWORTH



