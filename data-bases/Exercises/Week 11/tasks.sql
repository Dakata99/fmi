USE DANAIL

GO

BEGIN TRANSACTION

-- 1
INSERT INTO MOVIESTAR
VALUES ('Bruce Willis', 'Hollywood', 'M', '1955-03-19')

GO

CREATE TRIGGER BRUCE_WILLIS
ON MOVIE
AFTER INSERT
AS INSERT INTO STARSIN(MOVIETITLE, MOVIEYEAR, STARNAME)
SELECT TITLE, YEAR, 'Bruce Willis'
FROM INSERTED
WHERE TITLE LIKE '%save%' OR TITLE LIKE '%world%'

DROP TRIGGER BRUCE_WILLIS

-- 2
CREATE TRIGGER NetworthEnforce
ON MOVIEEXEC
AFTER INSERT, UPDATE, DELETE
AS
    IF (SELECT AVG(NETWORTH)
       FROM MOVIEEXEC) < 500000
    BEGIN RAISERROR('Data Integrity Violation', 11, 1)
    ROLLBACK
    END
GO

-- 3
USE MOVIES
GO

CREATE TRIGGER SetNullOnDelete
ON MOVIEEXEC
INSTEAD OF DELETE
AS 
    UPDATE MOVIE
    SET PRODUCERC# = NULL
    WHERE PRODUCERC# IN (SELECT CERT#
                         FROM DELETED)

-- 4
CREATE TRIGGER AutoStarAndMovie
ON STARSIN
INSTEAD OF INSERT
AS INSERT INTO MOVIES(NAME)
SELECT DISTINCT STARNAME
FROM INSERTED
WHERE STARNAME NOT IN (SELECT NAME
                       FROM MOVIESTAR)


-- 5
CREATE TRIGGER ADD_PC_ON_DELETE_LAPTOP
ON LAPTOP
AFTER DELETE
AS
    INSERT INTO PC
    SELECT CODE + 100, '1121', SPEED, RAM, HD, '52x', PRICE
    FROM DELETED d
        JOIN PRODUCT p ON p.MODEL = d.MODEL
    WHERE p.MAKER = 'D'

-- 6
CREATE TRIGGER PcPriceEnforce1
ON PC
AFTER UPDATE
AS
    IF EXISTS (SELECT *
               FROM PC p
                   JOIN INSERTED i ON p.SPEED = i.SPEED
               WHERE p.PRICE < i.PRICE)
    BEGIN
        RAISERROR('Data Integrity Violation', 11, 1)
        ROLLBACK
    END

-- 7
CREATE TRIGGER MakerEnforcement1
ON PRODUCT 
AFTER INSERT, UPDATE
AS
    IF EXISTS ( SELECT *
                FROM PRODUCT p1
                    JOIN product p2 ON p1.MAKER = p2.MAKER
                WHERE p1.TYPE = 'PC' and p2.TYPE = 'Printer')
    BEGIN
        RAISERROR('Data Integrity Violation', 11, 1)
        ROLLBACK
    END

-- 8
-- Причината това решение да е толкова дълго, е че искаме да гарантираме интегритета на базата 
-- относно условието на задачата, независимо от това какви заявки се изпълняват от клиентите 
-- За решението ще създадеме три тригера: 
--      - pc (INSERT, UPDATE)
--      - laptop (UPDATE, DELETE)
--      - product (UPDATE)

CREATE TRIGGER PCTrigger1
ON PC
AFTER INSERT, UPDATE
AS 
    DECLARE @numFound int = (SELECT COUNT(DISTINCT i.CODE)
                             FROM INSERTED i
                                JOIN PRODUCT p1 ON i.MODEL = p1.MODEL
                                JOIN PRODUCT p2 ON p1.MAKER = p2.MAKER
                                JOIN LAPTOP l ON p2.MODEL = l.MODEL
                             WHERE i.SPEED <= l.SPEED)
    
-- ...

-- 9
CREATE TRIGGER LAPTOP_CHANGE
ON LAPTOP
AFTER INSERT, UPDATE, DELETE
AS
    IF EXISTS(  SELECT p.MAKER
                FROM LAPTOP l
                    JOIN PRODUCT p ON p.MODEL = l.MODEL
                    JOIN PRODUCT p2 ON p2.MAKER = p.MAKER
                WHERE p2.MODEL IN ( SELECT MODEL
                                    FROM INSERTED
                                    UNION
                                    SELECT MODEL
                                    FROM DELETED)
                GROUP BY p.MAKER
                HAVING AVG(l.PRICE) < 2000)
    BEGIN
        RAISERROR('Data Integrity Violation', 11, 1)
        ROLLBACK
    END

-- 10
CREATE TRIGGER EnforcePriceForPC
ON PC
AFTER INSERT, UPDATE
AS
    IF EXISTS(  SELECT *
                FROM INSERTED
                    JOIN LAPTOP ON INSERTED.RAM < LAPTOP.RAM
                WHERE PC.PRICE >= INSERTED.PRICE)
    BEGIN
        RAISERROR('Data Integrity Violation', 11, 1)
        ROLLBACK
    END

CREATE TRIGGER EnforePriceForLaptop
ON LAPTOP
AFTER INSERT, UPDATE 
AS
    IF EXISTS ( SELECT *
                FROM PC
                    JOIN INSERTED ON PC.RAM < INSERTED.RAM
                WHERE PC.PRICE >= INSERTED.PRICE)
    BEGIN
        RAISERROR('Data Integrity Violation', 11, 1)
        ROLLBACK
    END

-- 11
CREATE TRIGGER MATRIX_FILTER
ON PRINTER
INSTEAD OF INSERT
AS
    INSERT INTO PRINTER 
    SELECT *
    FROM INSERTED
    WHERE TYPE != 'Matrix' OR COLOR != 'y'

-- 12

-- Variant 1
CREATE TRIGGER DISPLACEMENT_CAP1
ON CLASSES
AFTER INSERT
AS
    INSERT INTO CLASSES
    SELECT CLASS, TYPE, COUNTRY, NUMGUNS, BORE, CASE WHEN DISPLACEMENT > 3500 THEN 3500 ELSE DISPLACEMENT END AS DISPLACEMENT
    FROM INSERTED

-- Variant 2
CREATE TRIGGER DISPLACEMENT_CAP2
ON CLASSES
AFTER INSERT
AS
    INSERT INTO CLASSES
    SELECT CLASS, TYPE, COUNTRY, NUMGUNS, BORE, DISPLACEMENT
    FROM INSERTED
    WHERE DISPLACEMENT <= 35000

    INSERT INTO CLASSES
    SELECT CLASS, TYPE, COUNTRY, NUMGUNS, BORE, 35000 AS DISPLACEMENT
    FROM INSERTED
    WHERE DISPLACEMENT > 35000

-- 13
CREATE VIEW SHIP_COUNT
AS
    SELECT c.CLASS, COUNT(s.NAME) AS SHIPS
    FROM CLASSES c
        LEFT OUTER JOIN SHIPS s ON s.CLASS = c.CLASS
    GROUP BY c.CLASS

CREATE TRIGGER SHIPS_COUNT_PROCESS
ON SHIP_COUNT
INSTEAD OF DELETE
AS
    DELETE FROM SHIPS
    WHERE CLASS IN (SELECT CLASS
                    FROM DELETED)

-- 14
CREATE TRIGGER SHIP_COUNT_ENFORCER
ON SHIPS
AFTER INSERT, UPDATE
AS
    IF EXISTS(  SELECT CLASS
                FROM SHIPS
                GROUP BY CLASS
                HAVING COUNT(*) > 2)
    BEGIN
        RAISERROR('Data Integrity Violation', 11, 1)
        ROLLBACK
    END

-- 15
CREATE TRIGGER OUTCOMES_ENFORCE
ON OUTCOMES
AFTER INSERT, UPDATE
AS
    IF EXISTS(  SELECT o1.BATTLE
                FROM OUTCOMES o1
                    JOIN OUTCOMES o2 ON o1.BATTLE = o2.BATTLE AND o1.SHIP != o2.SHIP
                    JOIN SHIPS s1 ON s1.NAME = o1.SHIP
                    JOIN SHIPS s2 ON s2.NAME = o2.SHIP
                    JOIN CLASSES c1 ON c1.CLASS = s1.CLASS
                    JOIN CLASSES c2 ON c2.CLASS = s2.CLASS
                WHERE c1.NUMGUNS > 9 AND c2.NUMGUNS < 9 AND o1.BATTLE IN (  SELECT BATTLE
                                                                            FROM inserted))
    BEGIN
        RAISERROR('Data Integrity Violation', 11, 1)
        ROLLBACK
    END

-- 16
CREATE TRIGGER OUTCOMES_DATE_ENFORCE
ON OUTCOMES
AFTER INSERT, UPDATE
AS
    IF EXISTS ( SELECT *
                FROM OUTCOMES o1
                    JOIN BATTLES b1 ON o1.BATTLE = b1.NAME
                    JOIN OUTCOMES o2 ON o1.SHIP = o2.SHIP
                    JOIN BATTLES b2 ON o2.BATTLE = b2.NAME
                WHERE o1.RESULT = 'sunk' AND b1.DATE < b2.DATE AND o1.SHIP IN ( SELECT SHIP
                                                                                FROM inserted))
    BEGIN
        RAISERROR('Data Integrity Violation', 11, 1)
        ROLLBACK
    END

ROLLBACK