
-- 1
CREATE DATABASE FURNITURE_COMPANY

CREATE TABLE CUSTOMER(
    ID INT IDENTITY(1, 1) PRIMARY KEY NOT NULL,
    NAME VARCHAR(50) NOT NULL,
    ADDRESS VARCHAR(50) NOT NULL,
    CITY VARCHAR(50) NOT NULL,
    CODE INT NOT NULL
)

CREATE TABLE PRODUCT2(
    ID INT PRIMARY KEY NOT NULL,
    DESCRIPTION VARCHAR(50),
    FINISH VARCHAR(50),
    PRICE INT NOT NULL,
    LINE_ID INT NOT NULL,
    CONSTRAINT ID_CHECK CHECK(ID > 0),
    CONSTRAINT PRICE_CHECK CHECK(PRICE > 0),
    CONSTRAINT FINISH_VALUES CHECK(FINISH IN ('cherry', 'natural ash', 'white ash', 'red oak', 'natural oak', 'walnut'))
)

CREATE TABLE ORDER_T(
    ID INT PRIMARY KEY NOT NULL,
    DATE DATE NOT NULL,
    CUSTOMER_ID INT NOT NULL,
    CONSTRAINT ID_CHECK CHECK(ID > 0),
    FOREIGN KEY (CUSTOMER_ID) REFERENCES CUSTOMER(ID),
)

CREATE TABLE ORDER_LINE(
    ID INT PRIMARY KEY NOT NULL,
    PRODUCT_ID INT NOT NULL,
    QUANTITY INT NOT NULL,
    CONSTRAINT ID_CHECK CHECK(ID > 0),
    FOREIGN KEY (ID) REFERENCES ORDER_T(ID),
    FOREIGN KEY (PRODUCT_ID) REFERENCES PRODUCT2(ID)
)

INSERT INTO CUSTOMER
VALUES
    ('Иван Петров', 'ул. Лавеле 8', 'София', '1000'),
    ('Камелия Янева', 'ул. Иван Шишман 3', 'Бургас', '8000'),
    ('Васил Димитров', 'ул. Абаджийска 87', 'Пловдив', '4000'),
    ('Ани Милева', 'бул. Владислав Варненчик 56', 'Варна','9000');

INSERT INTO PRODUCT2
VALUES
    (1000, 'офис бюро', 'череша', 195, 10),
    (1001, 'директорско бюро', 'червен дъб', 250, 10),
    (2000, 'офис стол', 'череша', 75, 20),
    (2001, 'директорски стол', 'естествен дъб', 129, 20),
    (3000, 'етажерка за книги', 'естествен ясен', 85, 30),
    (4000, 'настолна лампа', 'естествен ясен', 35, 40);

INSERT INTO ORDER_T
VALUES
    (100, '2013-01-05', 1),
    (101, '2013-12-07', 2),
    (102, '2014-10-03', 3),
    (103, '2014-10-08', 2),
    (104, '2015-10-05', 1),
    (105, '2015-10-05', 4),
    (106, '2015-10-06', 2),
    (107, '2016-01-06', 1);

INSERT INTO ORDER_LINE
VALUES
    (100, 4000, 1),
    (101, 1000, 2),
    (101, 2000, 2),
    (102, 3000, 1),
    (102, 2000, 1),
    (106, 4000, 1),
    (103, 4000, 1),
    (104, 4000, 1),
    (105, 4000, 1),
    (107, 4000, 1);

-- 2