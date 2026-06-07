USE MOVIES

-- 1
SELECT ms.NAME
FROM MOVIESTAR ms
    JOIN MOVIEEXEC me ON ms.NAME = me.NAME
WHERE ms.GENDER = 'F' AND me.NETWORTH > 10000000

--
SELECT NAME
FROM MOVIESTAR
WHERE GENDER= 'F' AND NAME IN (SELECT NAME
                               FROM MOVIEEXEC 
                               WHERE NETWORTH > 10000000)

-- 2
SELECT NAME
FROM MOVIESTAR
WHERE NAME NOT IN (SELECT NAME
                   FROM MOVIEEXEC)

-- 3
-- TITLE не е достатъчно за уникално идентифициране на филм в таблицата MOVIE. 
-- Необходима е двойка стойности (име на филм, година).

-- Интерпретация 1: филмите с дължина по-голяма от дължината на 'Gone With The Wind', правен през 1938
SELECT TITLE
FROM MOVIE
WHERE LENGTH > (SELECT LENGTH
                FROM MOVIE 
                WHERE TITLE = 'Gone With the Wind' AND YEAR = 1938)

-- Интерпретация 2: филмите с дължина по-голяма от дължината всички филми със заглавие 'Gone With The Wind'
SELECT TITLE
FROM MOVIE
WHERE LENGTH > ALL (SELECT LENGTH
                    FROM MOVIE
                    WHERE TITLE = 'Gone With the Wind')

-- Това ще работи само когато в базата има само един филм с име 'Gone With the Wind'. Иначе ще връща грешка.
SELECT TITLE
FROM MOVIE
WHERE LENGTH > (SELECT LENGTH
                FROM MOVIE
                WHERE TITLE = 'Gone With the Wind')

-- 4
-- В базата MOVIES няма стойност на продукции и затова интерпретираме това условие като:
-- Имената на продуцентите и продукциите, правени от продуценти с NETWORTH по-голям от NETWORTH-a на 'Merv Griffin'
SELECT NAME, TITLE
FROM MOVIEEXEC me
    JOIN MOVIE m ON m.PRODUCERC# = me.CERT#
WHERE NETWORTH > (SELECT NETWORTH
                 FROM MOVIEEXEC
                 WHERE NAME = 'Merv Griffin')
