-- 1. Създайте нова база от данни с име test

CREATE DATABASE test GO

USE test

-- 2. Дефинирайте следните релации: 
-- а) PRODUCT(MAKER, MODEL, TYPE), където моделът е низ от точно 4 символа, MAKER - един символ, 
--      а TYPE - низ до 7 символа 

-- б) PRINTER(CODE, MODEL, color, PRICE), където CODE е цяло число, color е 'y' или 'n' и по 
--      подразбиране е 'n', PRICE - цена с точност до два знака след десетичната запетая 

-- в) Classes(class, TYPE), където class е до 50 символа, а TYPE може да бъде 'bb' или 'bc'

CREATE TABLE PRODUCT (
    MAKER CHAR(1), 
    MODEL CHAR(4), 
    TYPE VARCHAR(7) )

CREATE TABLE PRINTER (
    CODE INT,
    MODEL CHAR(4),
    COLOR CHAR(1) DEFAULT 'n',
    PRICE DECIMAL(9,2) )

CREATE TABLE CLASSES (
    CLASS VARCHAR(50),
    TYPE CHAR(2) CHECK (TYPE IN ('bb', 'bc')) )

-- 2. Добавете кортежи с примерни данни към новосъздадените релации. Добавете информация за принтер, 
-- за когото знаем само кода и модела.

INSERT INTO PRODUCT
VALUES ('a', 'abcd', 'PRINTER')

INSERT INTO PRINTER (CODE, MODEL) VALUES (1, 'abcd')

INSERT INTO CLASSES
VALUES ('Bismark', 'bb')

-- 3. Добавете към Classes атрибут bore - число с плаваща запетая.

ALTER TABLE CLASSES ADD bore float

-- 4. Напишете заявка, която премахва атрибута PRICE от PRINTER.

ALTER TABLE PRINTER DROP COLUMN PRICE

-- 5. Изтрийте всички таблици, които сте създали в това упражнение.

DROP TABLE CLASSES
DROP TABLE PRINTER
DROP TABLE PRODUCT

-- 6. Изтрийте базата test

USE master GO

DROP DATABASE test GO