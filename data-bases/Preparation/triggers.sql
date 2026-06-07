-- 1.1. Добавете Брус Уилис в базата. Направете така, че при добавяне на филм, 
-- чието заглавие съдържа “save” или “world”, Брус save” или “save” или 
-- “world”, Брус world”, Брус Уилис автоматично да бъде добавен като актьор, играл във филма.

USE MOVIES GO

INSERT INTO MOVIESTAR
VALUES ('Bruce Willis', 'Hollywood', 'M', '1955-03-19')
GO

CREATE TRIGGER BruceWillis
ON MOVIE
AFTER INSERT
AS
    INSERT INTO STARSIN (MOVIETITLE, MOVIEYEAR, STARNAME)
    SELECT TITLE, YEAR, 'Bruce Willis'
    FROM inserted
    WHERE TITLE LIKE '%save%' AND TITLE LIKE '%world%'
GO

-- 1.2. Да се направи така, че да не е възможно средната стойност на Networth 
-- да е помалка от 500 000 (ако при промени в таблицата MovieExec тази стойност 
-- стане по-малка от 500 000, промените да бъдат отхвърлени).

USE MOVIES GO

CREATE TRIGGER NetworthEnforce
ON MOVIEEXEC
AFTER INSERT, UPDATE, DELETE
AS
    IF (SELECT AVG(NETWORTH) FROM MOVIEEXEC) < 500000
    BEGIN
        RAISERROR('Data Integrity Violation', 11, 1)
        ROLLBACK
    END
GO

-- 1.3. MS SQL не поддържа ON DELETE SET NULL. Да се реализира с тригер за външния 
-- ключ Movie.producerc#.

USE MOVIES GO

CREATE TRIGGER SetNullOnDelete
ON MOVIEEXEC
INSTEAD OF DELETE
AS
    UPDATE MOVIE 
    SET PRODUCERC# = NULL 
    WHERE PRODUCERC# IN (SELECT CERT# FROM deleted)

DELETE FROM MOVIEEXEC 
WHERE CERT# IN (SELECT CERT# FROM deleted)
GO

-- 1.4. При добавяне на нов запис в StarsIn, ако новият ред указва несъществуващ 
-- филм или актьор, да се добавят липсващите данни в съответната таблица 
-- (неизвестните данни да бъдат NULL). Внимание: има външни ключове!

USE MOVIES GO

CREATE TRIGGER AutoStarAndMovie
ON STARSIN
INSTEAD OF INSERT
AS
    INSERT INTO MOVIESTAR (NAME)
    SELECT DISTINCT STARNAME
    FROM inserted
    WHERE STARNAME NOT IN (SELECT NAME FROM MOVIESTAR)

INSERT INTO MOVIE (TITLE, YEAR)
    SELECT DISTINCT MOVIETITLE, MOVIEYEAR
    FROM inserted
    WHERE NOT EXISTS (  SELECT TITLE
                        FROM MOVIE
                        WHERE TITLE = MOVIETITLE AND YEAR = MOVIEYEAR)

INSERT INTO STARSIN
    SELECT * FROM inserted
GO

-- 2.1. Да се направи така, че при изтриване на лаптоп на производител D автоматично 
-- да се добавя PC със същите параметри в таблицата с компютри. Моделът на новите 
-- компютри да бъде ‘1121’, CD устройството да бъде ‘52x’, а кодът - със 100 
-- по-голям от кода на лаптопа.

USE PC GO

CREATE TRIGGER DeleteD
ON LAPTOP
AFTER DELETE
AS
    INSERT INTO PC
    SELECT CODE + 100, '1121', SPEED, RAM, HD, '52x', PRICE
    FROM deleted d
        JOIN PRODUCT p ON d.MODEL = p.MODEL
    WHERE p.MAKER = 'D'
GO

-- 2.2. При промяна на цената на някой компютър се уверете, че няма по-евтин компютър
-- със същата честота на процесора.

USE PC GO

CREATE TRIGGER PcPriceEnforce1
ON PC
AFTER UPDATE
AS
    IF EXISTS ( SELECT *
                FROM PC p
                JOIN inserted i ON p.SPEED = i.SPEED
                WHERE p.PRICE < i.PRICE)
    BEGIN
        RAISERROR('Data Integrity Violation', 11, 1)
        ROLLBACK
    END
GO

-- 2.3. Никой производител на компютри не може да произвежда и принтери.

USE PC GO

CREATE TRIGGER MakerEnforcement1
ON PRODUCT 
AFTER INSERT, UPDATE
AS
    IF EXISTS ( SELECT *
                FROM PRODUCT p1
                    JOIN PRODUCT p2 ON p1.MAKER = p2.MAKER
                WHERE p1.TYPE = 'PC' AND p2.TYPE = 'Printer')
    BEGIN
        RAISERROR('Data Integrity Violation', 11, 1)
        ROLLBACK
    END
GO

-- 2.4. Всеки производител на компютър трябва да произвежда и лаптоп, който да има същата 
-- или по-висока честота на процесора.

-- Причината това решение да е толкова дълго, е че искаме да гарантираме интегритета на базата 
-- относно условието на задачата, независимо от това какви заявки се изпълняват от клиентите 
-- За решението ще създадеме три тригера: 
-- - PC (INSERT, UPDATE) 
-- - LAPTOP (UPDATE, DELETE) 
-- - PRODUCT (UPDATE)

-- Тригер за PC -- Вариант 1

CREATE TRIGGER PcTrigger1
ON PC
AFTER INSERT, UPDATE
AS
    DECLARE @numFound INT = (   SELECT COUNT(DISTINCT i.CODE)
                                FROM inserted i
                                    JOIN PRODUCT p1 ON i.MODEL = p1.MODEL
                                    JOIN PRODUCT p2 ON p1.MAKER = p2.MAKER
                                    JOIN LAPTOP l ON p2.MODEL = l.MODEL
                                WHERE i.SPEED <= l.SPEED)

    IF @numFound != (SELECT COUNT(*) FROM inserted)
    BEGIN
        RAISERROR('Data Integrity Violation', 11, 1)
        ROLLBACK
    END
GO

-- Тригер за PC -- Вариант 2

CREATE TRIGGER PcTrigger2
ON PC
AFTER INSERT, UPDATE
AS
    IF EXISTS ( SELECT *
                FROM inserted i
                    JOIN PRODUCT p1 ON i.MODEL = p1.MODEL
                WHERE NOT EXISTS (  SELECT *
                                    FROM LAPTOP l2
                                    WHERE l2.SPEED >= i.SPEED AND l2.MODEL IN ( SELECT MODEL
                                                                                FROM PRODUCT p2
                                                                                WHERE p2.MAKER = p1.MAKER)))
    BEGIN
        RAISERROR('Data Integrity Violation', 11, 1)
        ROLLBACK
    END
GO

-- 2. Тригер за LAPTOP

-- Ако на някой лаптоп му е сменен модела, то той ще се озове при друг производител, 
-- но там проблем не може да възникне. 
-- Проблем може да има само със стария производител, за който имаме премахнат лаптоп 
-- Затова е достатъчно да направим проверка за всички производители на лаптопи в 
-- таблицата deleted дали след модификацията всичко е наред. 
-- Тоест дали за всички PC-та от такива производители има лаптоп с по-голяма 
-- честота от същия производител 
-- Тоест дали има PC от такъв производител, за което няма лаптоп с по-голяма честота

-- Вариант 1

CREATE TRIGGER LaptopTrigger1
ON LAPTOP
AFTER UPDATE, DELETE
AS
    IF EXISTS (SELECT * 
            FROM PC p
                JOIN PRODUCT p1 ON p.MODEL = p1.MODEL
                JOIN PRODUCT p2 ON p1.MAKER = p2.MAKER
                JOIN deleted d ON d.MODEL = p2.MODEL
            WHERE NOT EXISTS (SELECT *
                                FROM LAPTOP l2
                                WHERE l2.SPEED >= p.SPEED
                                    AND l2.MODEL IN (SELECT MODEL
                                                    FROM PRODUCT p3
                                                    WHERE p3.MAKER = p1.MAKER)))
    BEGIN
        RAISERROR('Data Integrity Violation', 11, 1)
        ROLLBACK
    END
    GO

-- Вариант 2

-- Тук смятаме максималната цена на лаптоп за всеки афектиран производител и гледаме
-- дали има PC, чиято цена е по-малка от най-високата на лаптоп от същия производител.

CREATE TRIGGER LaptopTrigger2
ON LAPTOP
AFTER UPDATE, DELETE
AS
    IF EXISTS ( SELECT *
                FROM deleted d
                    JOIN PRODUCT p1 ON d.MODEL = p1.MODEL -- външното свързване и проверката за IS NULL по-долу е за случая, когато изтриваме всички лаптопи от даден модел
                    LEFT OUTER JOIN (   SELECT px.MAKER, MAX(SPEED) AS maxspeed
                                        FROM PRODUCT px
                                            JOIN LAPTOP lx ON px.MODEL = lx.MODEL
                                        GROUP BY px.MAKER) t ON t.MAKER = p1.MAKER
                    JOIN PRODUCT p2 ON p1.MAKER = p2.MAKER
                    JOIN PC ON PC.MODEL = p2.MODEL
                    WHERE PC.SPEED > t.maxspeed OR t.maxspeed IS NULL)
    BEGIN
        RAISERROR('Data Integrity Violation', 11, 1)
        ROLLBACK
    END
GO

-- 3. Тригер за PRODUCT

-- Той е само за UPDATE. Няма как да се изтрие модел, без преди 
-- това да се изтрият съответните записи от LAPTOP/PC/printeр 
-- (заради FOREIGN KEY ограниченията). 
-- Ако тяхното изтриване е минало - значи няма какво да се проверява

CREATE TRIGGER ProductTrigger
ON PRODUCT 
AFTER UPDATE
AS 
-- Правиме проверка за всички производители от deleted
    IF EXISTS ( SELECT *
                FROM deleted d
                    LEFT OUTER JOIN (SELECT px.MAKER, MAX(SPEED) AS maxspeed
                                    FROM PRODUCT px
                                    JOIN LAPTOP lx ON px.MODEL = lx.MODEL
                                    GROUP BY px.MAKER) t ON t.MAKER = d.MAKER
                    JOIN PRODUCT p2 ON d.MAKER = p2.MAKER
                    JOIN PC ON PC.MODEL = p2.MODEL
                WHERE PC.SPEED > t.maxspeed OR t.maxspeed IS NULL)
    BEGIN
        RAISERROR('Data Integrity Violation', 11, 1)
        ROLLBACK
    END
GO

-- 2.5. При промяна на данните в таблицата Laptop се уверете, че средната цена на лаптопите 
-- за всеки производител е поне 2000.

USE PC GO

CREATE TRIGGER LaptopTriggerAvgPrice
ON LAPTOP
AFTER INSERT, UPDATE, DELETE
AS
    IF EXISTS(  SELECT p.MAKER
                FROM LAPTOP l
                    JOIN PRODUCT p ON l.MODEL = p.MODEL
                    JOIN PRODUCT p2 ON p2.MAKER = p.MAKER
                WHERE p2.MODEL IN ( SELECT MODEL
                                    FROM inserted
                                    UNION
                                    SELECT MODEL
                                    FROM deleted)
                GROUP BY p.MAKER
                HAVING AVG(l.PRICE) < 2000)
    BEGIN
        RAISERROR('Data Integrity Violation', 11, 1)
        ROLLBACK
    END
GO

-- 2.6. Ако някой лаптоп има повече памет от някой компютър, трябва да бъде и по-скъп от него.

USE PC GO

CREATE TRIGGER EnforePriceForPC
ON PC
AFTER INSERT, UPDATE
AS
    IF EXISTS ( SELECT *
                FROM inserted
                    JOIN LAPTOP ON inserted.RAM < LAPTOP.RAM
                WHERE inserted.PRICE >= LAPTOP.PRICE)
    BEGIN
        RAISERROR('Data Integrity Violation', 11, 1)
        ROLLBACK
    END
GO

CREATE TRIGGER EnforePriceForLaptop
ON LAPTOP
AFTER INSERT, UPDATE
AS
    IF EXISTS ( SELECT *
                FROM PC
                    JOIN inserted ON PC.RAM < inserted.RAM
                WHERE PC.PRICE >= inserted.PRICE)
    BEGIN
        RAISERROR('Data Integrity Violation', 11, 1)
        ROLLBACK
    END
GO

-- 2.7. Да приемем, че цветните матрични принтери (TYPE = 'Matrix') са забранени за продажба. 
-- При добавяне на принтери да се игнорират цветните матрични. Ако с една заявка се добавят 
-- няколко принтера, да се добавят само тези, които не са забранени, а другите да се игнорират.

USE PC GO

CREATE TRIGGER MatrixFilter
ON PRINTER
INSTEAD OF INSERT
AS
    INSERT INTO PRINTER
    SELECT *
    FROM inserted
    WHERE TYPE != 'Matrix' OR color != 'y'
GO

-- 3.1. Ако бъде добавен нов клас с водоизместимост по-голяма от 35000, класът да бъде добавен 
-- в таблицата, но да му се зададе водоизместимост 35000.

USE SHIPS GO

-- Вариант 1

CREATE TRIGGER DisplacementCap1
ON CLASSES
AFTER INSERT
AS
    INSERT INTO CLASSES
    SELECT CLASS, TYPE, COUNTRY, NUMGUNS, BORE, CASE WHEN DISPLACEMENT > 35000 THEN 35000 ELSE DISPLACEMENT END AS DISPLACEMENT
    FROM inserted
GO

-- Вариант 2

CREATE TRIGGER DisplacementCap2
ON CLASSES
AFTER INSERT
AS
    INSERT INTO CLASSES
    SELECT CLASS, TYPE, COUNTRY, NUMGUNS, BORE, DISPLACEMENT
    FROM inserted
    WHERE DISPLACEMENT <= 35000

    INSERT INTO CLASSES 
    SELECT CLASS, TYPE, COUNTRY, NUMGUNS, BORE, 35000 AS DISPLACEMENT 
    FROM inserted
    WHERE DISPLACEMENT > 35000
GO

-- 3.2. Създайте изглед, който показва за всеки клас името му и броя кораби (евентуално 0). 
-- Направете така, че при изтриване на ред да се изтрие класът и всички негови кораби.

USE SHIPS GO

CREATE VIEW ShipsCount
AS
    SELECT c.CLASS, COUNT(s.NAME) AS SHIPS
    FROM CLASSES c
        LEFT OUTER JOIN SHIPS s ON c.CLASS = s.CLASS
    GROUP BY c.CLASS
GO

CREATE TRIGGER ShipsCountProcess
ON ShipsCount
INSTEAD OF DELETE
AS
    DELETE FROM SHIPS
    WHERE CLASS IN (SELECT CLASS FROM deleted)

DELETE FROM CLASSES 
WHERE CLASS IN (SELECT CLASS FROM deleted)
GO

-- 3.3. Никой клас не може да има повече от два кораба.

USE SHIPS GO

CREATE TRIGGER ShipCountEnforcer
ON SHIPS
AFTER INSERT, UPDATE
AS
    IF EXISTS ( SELECT CLASS
                FROM SHIPS
                GROUP BY CLASS
                HAVING COUNT(*) > 2)
    BEGIN
        RAISERROR('Data Integrity Violation', 11, 1)
        ROLLBACK
    END
GO

-- 3.4. Кораб с повече от 9 оръдия не може да участва в битка с кораб, който е с по-малко от 9 
-- оръдия. Напишете тригер за Outcomes.

-- ако приемеме, че след създаване на клас в таблицата CLASSES може да се модифицират 
-- атрибутите на класовете (в нашия случай - броя оръдия), то тогава би следвало и за там 
-- да се направи тригер за UPDATE в случая приемаме, че за класове имаме само INSERT/DELETE операции (в практическия 
-- случай - при нови параметри - имаме нов клас кораби)

-- за битките, за които имаме добавени/обновени кораби, проверяваме дали има двойки, 
-- нарушаващи условието

USE SHIPS GO

CREATE TRIGGER OutcomesEnforce
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
                WHERE c1.NUMGUNS > 9 AND c2.NUMGUNS < 9 AND o1.BATTLE IN (SELECT BATTLE FROM inserted))
    BEGIN
        RAISERROR('Data Integrity Violation', 11, 1) 
        ROLLBACK
    END
GO

-- 3.5. Кораб, който вече е потънал, не може да участва в битка, чиято дата е след датата 
-- на потъването му. Напишете тригери за всички таблици, за които е необходимо.

-- ако приемеме, че след създаване на битка в таблицата BATTLES може да се модифицира 
-- датата на битката - тогава трябва и за там да се направи тригер за UPDATE. 
-- в случая приемаме, че за BATTLES имаме само INSERT/DELETE операции

USE SHIPS GO

CREATE TRIGGER OutcomeDateEnforce
ON OUTCOMES
AFTER INSERT, UPDATE
AS
    IF EXISTS ( SELECT *
                FROM OUTCOMES o1
                    JOIN BATTLES b1 ON o1.BATTLE = b1.NAME
                    JOIN OUTCOMES o2 ON o1.SHIP = o2.SHIP
                    JOIN BATTLES b2 ON o2.BATTLE = b2.NAME
                WHERE o1.RESULT = 'sunk' AND b1.DATE < b2.DATE AND o1.SHIP IN (SELECT SHIP FROM inserted))
    BEGIN
        RAISERROR('Data Integrity Violation', 11, 1)
        ROLLBACK
    END
GO
