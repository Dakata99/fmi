USE MOVIES

-- 1
SELECT ms.NAME, ms.BIRTHDATE, (SELECT TOP 1 m.STUDIONAME
                               FROM STARSIN si
                                    JOIN MOVIE m ON si.MOVIETITLE = m.TITLE AND si.MOVIEYEAR = m.YEAR
                               WHERE si.STARNAME = ms.NAME
                               GROUP BY m.STUDIONAME
                               ORDER BY COUNT(*) DESC) AS STUDIO
FROM MOVIESTAR ms

-- 2