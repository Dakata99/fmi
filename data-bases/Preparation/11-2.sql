-- За базата от данни Movies:
USE DANAIL
GO

-- 6. Създайте изглед RichExec, който извежда името, адреса, сертификационния номер и
-- нетните активи на всеки продуцент с нетни активи поне 10000000.
CREATE VIEW RichExec
AS
    SELECT NAME, ADDRESS, CERT#, NETWORTH
    FROM MOVIEEXEC
    WHERE NETWORTH > 10000000
GO

-- 7. Създайте изглед Executivestar, който извежда името, адреса, пола, рождената дата,
-- сертификационния номер и нетните активи на всички звезди, които са и продуценти.
CREATE VIEW Executivestar
AS
    SELECT DISTINCT m.NAME, m.ADDRESS, m.GENDER, m.BIRTHDATE, me.CERT#, me.NETWORTH
    FROM MOVIESTAR m
        JOIN MOVIEEXEC me ON m.NAME = me.NAME
GO

-- 8. Кои от тези изгледи са updateable (т.е. върху тях могат да се изпълняват DML оператори).
-- Напишете всяка от заявките по-долу, като използвате един или повече от изгледите от
-- горните задачи и не използвате директно таблици от схемата Movies

-- 9. Изведете имената на актрисите, които са също и продуценти.
SELECT NAME
FROM Executivestar
WHERE GENDER = 'F'

-- 10. Изведете имената на продуцентите, които са също и президенти на студио и нетните им
-- активи са поне 10000000.
SELECT DISTINCT NAME
FROM RichExec

-- 11. Изведете имената на продуцентите, които са също и звезди и имат нетни активи поне 50000000.
SELECT NAME
FROM Executivestar
WHERE NETWORTH > 50000000

-- 12. Изтрийте създадените изгледи.
DROP VIEW RichExec
DROP VIEW Executivestar



-- Индекси

-- 13. Създайте подходящ индекс/ индекси върху таблицата Product (maker, model, type)
-- 14. Създайте подходящ индекс/ индекси върху таблиците:
-- a) Classes (class,type,country, numGuns,bore, displacement)
-- b) Ships (name,class,launched)
-- c) Battles (name, date)
-- d) Outcomes (ship,battle,result)
-- 15. Изтрийте създадените индекси.