USE MOVIES

-- 1. Да се добави информация за актрисата Nicole Kidman. За нея знаем само, че е родена на 20-и юни 1967.

INSERT INTO MOVIESTAR (NAME, GENDER, BIRTHDATE)
VALUES ('Nicole Kidman', 'F', '1967-06-20')

-- 2. Да се изтрият всички продуценти с печалба (networth) под 10 милиона.

DELETE FROM MOVIEEXEC
WHERE NETWORTH < 10000000

-- 3. Да се изтрие информацията за всички филмови звезди, за които не се знае адреса.

DELETE FROM MOVIESTAR
WHERE ADDRESS IS NULL

USE PC

-- 4. Използвайки две INSERT заявки, съхранете в базата данни факта, че персонален компютър модел 1100 
-- е направен от производителя C, има процесор 2400 MHz, RAM 2048 MB, твърд диск 500 GB, 52x DVD 
-- устройство и струва $299. Нека новият компютър има код 12. Забележка: моделът и CD са от тип низ.

INSERT INTO PRODUCT
VALUES ('C', '1100', 'PC')

INSERT INTO PC
VALUES (12, '1100', 2400, 2048, 500, '52x', 299)

-- 5. Да се изтрие всичката налична информация за компютри модел 1100.

DELETE FROM PC
WHERE MODEL = '1100'

DELETE FROM PRODUCT
WHERE MODEL = '1100'

-- 6. За всеки персонален компютър се продава и 15-инчов лаптоп със същите параметри, но с $500 по-скъп. 
-- Кодът на такъв лаптоп е със 100 по-голям от кода на съответния компютър. Добавете тази информация в базата.

INSERT INTO LAPTOP (CODE, MODEL, SPEED, RAM, HD, PRICE, SCREEN) 
SELECT CODE + 100 AS CODE, MODEL, SPEED, RAM, HD, PRICE + 500 AS PRICE, 15 
FROM PC

-- 7. Да се изтрият всички лаптопи, направени от производител, който не произвежда принтери.

DELETE FROM LAPTOP
WHERE MODEL IN (SELECT MODEL
                FROM PRODUCT
                WHERE TYPE = 'Laptop' AND MAKER NOT IN (SELECT MAKER
                                                        FROM PRODUCT
                                                        WHERE TYPE = 'Printer'))

-- 8. Производител А купува производител B. На всички продукти на В променете производителя да бъде А.

UPDATE PRODUCT
SET MAKER = 'A'
WHERE MAKER = 'B'

-- 9. Да се намали два пъти цената на всеки компютър и да се добавят по 20 GB към всеки твърд диск.

UPDATE PC
SET PRICE = PRICE / 2, HD = HD + 20

-- 10. За всеки лаптоп от производител B добавете по един инч към диагонала на екрана.

UPDATE LAPTOP
SET SCREEN = SCREEN + 1
WHERE MODEL IN (SELECT MODEL FROM PRODUCT WHERE MAKER = 'B')

USE SHIPS

-- 11. Два британски бойни кораба от класа Nelson - Nelson и Rodney - са били пуснати на вода едновременно 
-- през 1927 г. Имали са девет 16-инчови оръдия (bore) и водоизместимост от 34 000 тона (displacement). 
-- Добавете тези факти към базата от данни.

INSERT INTO CLASSES
VALUES ('Nelson', 'bb', 'Gt.Britain', 9, 16, 34000)

INSERT INTO SHIPS
VALUES ('Nelson', 'Nelson', 1927)

INSERT INTO SHIPS
VALUES ('Rodney', 'Nelson', 1927)

-- 12. Изтрийте от Ships всички кораби, които са потънали в битка.

DELETE FROM SHIPS
WHERE NAME IN (SELECT SHIP FROM OUTCOMES WHERE RESULT = 'sunk')

-- 13. Променете данните в релацията Classes така, че калибърът (bore) да се измерва в сантиметри (в момента 
-- е в инчове, 1 инч ~ 2.5 см) и водоизместимостта да се измерва в метрични тонове (1 м.т. = 1.1 т.)

UPDATE CLASSES
SET BORE = BORE * 2.54, DISPLACEMENT = DISPLACEMENT / 1.1

-- 14. Изтрийте всички класове, от които има по-малко от три кораба.

DELETE FROM CLASSES
WHERE CLASS NOT IN (SELECT CLASS FROM SHIPS
                    GROUP BY CLASS
                    HAVING COUNT(*) >= 3)

-- 15. Променете калибъра на оръдията и водоизместимостта на класа Iowa, така че да са същите като тези на -- класа Bismarck.

UPDATE CLASSES
SET BORE = (SELECT BORE FROM CLASSES
            WHERE CLASS = 'Bismarck'), DISPLACEMENT = ( SELECT DISPLACEMENT FROM CLASSES
                                                        WHERE CLASS ='Bismarck')
WHERE CLASS = 'Iowa'