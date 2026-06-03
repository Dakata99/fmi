USE PC

-- 1
SELECT p.MAKER, p.MODEL, p.TYPE
FROM PRODUCT p
    LEFT OUTER JOIN (SELECT MODEL
                     FROM PC
                     UNION
                     SELECT MODEL
                     FROM LAPTOP
                     UNION
                     SELECT MODEL
                     FROM PRINTER) ct ON p.MODEL = ct.MODEL
WHERE ct.MODEL IS NULL

--

SELECT MAKER, MODEL, TYPE
FROM PRODUCT
WHERE MODEL NOT IN (SELECT MODEL
                    FROM PC) AND 
      MODEL NOT IN (SELECT MODEL
                    FROM LAPTOP) AND 
      MODEL NOT IN (SELECT MODEL
                    FROM PRINTER)
