USE PC

-- 1
SELECT DISTINCT MAKER
FROM PRODUCT
WHERE MODEL IN (SELECT MODEL
                FROM PC
                WHERE SPEED >= 500)

-- 2
SELECT *
FROM PRINTER
WHERE PRICE >= ALL (SELECT PRICE
                    FROM PRINTER)

-- 3
SELECT *
FROM LAPTOP
WHERE SPEED < ANY (SELECT SPEED
                    FROM PC)

-- по-ниска от тази на всички PC-та:

SELECT *
FROM LAPTOP
WHERE SPEED < ALL (SELECT SPEED
                    FROM PC)

-- 4
SELECT MODEL
FROM PC
WHERE PRICE >= ALL (SELECT PRICE
                    FROM PRINTER
                    UNION
                    SELECT PRICE
                    FROM PC
                    UNION
                    SELECT PRICE
                    FROM LAPTOP)
UNION
SELECT MODEL
FROM LAPTOP
WHERE PRICE >= ALL (SELECT PRICE
                    FROM PRINTER
                    UNION
                    SELECT PRICE
                    FROM PC
                    UNION
                    SELECT PRICE
                    FROM LAPTOP)
UNION
SELECT MODEL
FROM PRINTER
WHERE PRICE >= ALL (SELECT PRICE
                    FROM PRINTER
                    UNION
                    SELECT PRICE
                    FROM PC
                    UNION
                    SELECT PRICE
                    FROM LAPTOP)

--

SELECT DISTINCT MODEL
FROM (SELECT MODEL, PRICE
      FROM PC
      UNION
      SELECT MODEL, PRICE
      FROM LAPTOP
      UNION
      SELECT MODEL, PRICE
      FROM PRINTER) t
WHERE PRICE >= ALL (SELECT PRICE
                    FROM PC
                    UNION
                    SELECT PRICE
                    FROM LAPTOP
                    UNION
                    SELECT PRICE
                    FROM PRINTER)

-- 5
SELECT DISTINCT MAKER
FROM PRODUCT
WHERE MODEL IN (SELECT MODEL
                FROM PRINTER
                WHERE COLOR = 'y' AND PRICE <= ALL (SELECT PRICE
                                                    FROM PRINTER
                                                    WHERE COLOR = 'y'))

--

SELECT DISTINCT MAKER
FROM PRODUCT p 
    JOIN (SELECT MODEL
          FROM PRINTER
          WHERE COLOR = 'y' AND PRICE <= ALL (SELECT PRICE
                                              FROM PRINTER
                                              WHERE COLOR = 'y') ) cm ON p.MODEL = cm.MODEL

-- 6 
SELECT DISTINCT MAKER
FROM PRODUCT
WHERE MODEL IN (SELECT MODEL
                FROM PC
                WHERE RAM <= ALL (SELECT RAM
                                  FROM PC)
                UNION
                SELECT MODEL
                FROM PC
                WHERE SPEED >= ALL (SELECT SPEED
                                    FROM PC))

SELECT DISTINCT MAKER
FROM PRODUCT
WHERE MODEL IN (SELECT MODEL
                FROM PC p1
                WHERE RAM <= ALL (SELECT RAM
                                  FROM PC)
                AND SPEED >= ALL (SELECT SPEED
                                  FROM PC p2
                                  WHERE p1.RAM = p2.RAM))
