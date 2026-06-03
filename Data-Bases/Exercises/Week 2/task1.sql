USE MOVIES

-- 1
SELECT DISTINCT NAME
FROM MOVIESTAR
    JOIN STARSIN ON NAME = STARNAME
WHERE MOVIETITLE = 'Terms of Endearment' AND GENDER = 'M'

-- 2
SELECT DISTINCT STARNAME
FROM MOVIE
    JOIN STARSIN ON TITLE = MOVIETITLE AND YEAR = MOVIEYEAR
WHERE STUDIONAME = 'MGM' AND YEAR = 1995

-- 3
SELECT me.NAME
FROM STUDIO s
    JOIN MOVIEEXEC me ON s.PRESC# = me.CERT#
WHERE s.NAME = 'MGM'

-- 4
-- В таблицата MOVIE, може да има различни филми с едно и също име, ако са правени в различни години
-- Предвид, че в условието се говори за единствен филм - смятаме, че става въпрос за този, който е сниман през 1977 и го указваме в заявката.
SELECT m1.TITLE
FROM MOVIE m1
    JOIN MOVIE m2 ON m2.TITLE = 'Star Wars' AND m2.YEAR = 1977
WHERE m1.LENGTH > m2.LENGTH
