<details> 
    <summary>BG</summary>

# Задачи
<ol>
    <li>За всяка филмова звезда да се изведе името, рождената дата и с кое студио е записвала най-много филми. (Ако има две студиа с еднакъв брой филми, да се изведе кое да е от тях)</li>
    <li>Да се изведат всички производители, за които средната цена на произведените компютри е по-ниска от средната цена на техните лаптопи.</li>
    <li> Един модел компютри може да се предлага в няколко конфигурации с евентуално различна цена. Да се изведат тези модели компютри, чиято средна цена (на различните му конфигурации) е по-ниска от най-евтиния лаптоп, произвеждан от същия производител.</li>
    <li>Битките, в които са участвали поне 3 кораба на една и съща страна.</li>
    <li>За всеки кораб да се изведе броят на битките, в които е бил увреден. Ако корабът не е участвал в битки или пък никога не е бил увреждан, в резултата да се вписва 0.</li>
    <li>За всеки клас да се изведе името, държавата и първата година, в която е пуснат кораб от този клас</li>
    <li>За всяка държава да се изведе броят на корабите и броят на потъналите кораби. Всяка от бройките може да бъде и нула.</li>
    <li>Намерете за всеки клас с поне 3 кораба броя на корабите от този клас, които са с резултат ok.</li>
    <li>За всяка битка да се изведе името на битката, годината на битката и броят на потъналите кораби, броят на повредените кораби и броят на корабите без промяна.</li>
    <li>Да се изведат имената на корабите, които са участвали в битки в продължение поне на две години.</li>
    <li>За всеки потънал кораб колко години са минали от пускането му на вода до потъването.</li>
    <li>Имената на класовете, за които няма кораб, пуснат на вода след 1921 г., но имат пуснат поне един кораб.</li>
    <li></li>
    <li></li>
    <li></li>
    <li></li>
</ol>
</details>

<details>
    <summary>DATA BASES</summary>

# MOVIES
<img src="../MOVIES.png"
     alt="Markdown Monster icon"
     style="float: left; margin-right: 10px;" />

# PRODUCTS
<img src="../PRODUCTS.png"
     alt="Markdown Monster icon"
     style="float: left; margin-right: 10px;" />

# SHIPS
<img src="../SHIPS.png"
     alt="Markdown Monster icon"
     style="float: left; margin-right: 10px;" />

</details>

USE MOVIES

1. За всеки актьор - броя различни студио, с които са записвали филми

SELECT ms.NAME, COUNT(DISTINCT m.STUDIONAME) FROM MOVIE m JOIN STARSIN si ON m.TITLE = si.MOVIETITLE AND m.YEAR = si.MOVIEYEAR RIGHT OUTER JOIN MOVIESTAR ms ON si.STARNAME = ms.NAME GROUP BY ms.NAME

SELECT ms.NAME, COUNT(DISTINCT m.STUDIONAME) FROM MOVIESTAR ms LEFT OUTER JOIN STARSIN si ON si.STARNAME = ms.NAME LEFT OUTER JOIN MOVIE m ON m.TITLE = si.MOVIETITLE AND m.YEAR = si.MOVIEYEAR GROUP BY ms.NAME

USE pc

 2. За производителите на поне 2 лазерни принтера - броя на произвежданите PC-та

SELECT p.maker, (SELECT COUNT() FROM product p2 JOIN pc pc2 ON p2.model = pc2.model WHERE p2.maker = p.maker) FROM product p JOIN printer r ON p.model = r.model WHERE r.type = 'Laser' GROUP BY p.maker HAVING COUNT() > 1

SELECT p1.maker, COUNT(pc1.code) FROM product p1 LEFT OUTER JOIN pc pc1 ON p1.model = pc1.model WHERE maker IN (SELECT p2.maker FROM product p2 JOIN printer pr2 ON p2.model = pr2.model WHERE pr2.type = 'Laser' GROUP BY p2.maker HAVING COUNT(*) > 1) GROUP BY p1.maker

USE ships

 3. За всяка година, в която е проведена битка - броя на корабите, които са пуснати на вода през тази година:

SELECT YEAR(b.DATE), COUNT(DISTINCT s.NAME) FROM BATTLES b LEFT OUTER JOIN SHIPS s ON YEAR(b.DATE) = s.LAUNCHED GROUP BY YEAR(b.DATE)

 4. Броя на потъналите американски кораби за всяка проведена битка с поне един потънал американски кораб

SELECT o.BATTLE, COUNT(s.NAME) FROM OUTCOMES o JOIN SHIPS s ON o.SHIP = s.NAME JOIN CLASSES c ON s.CLASS = c.CLASS WHERE o.RESULT = 'sunk' AND c.COUNTRY = 'USA' GROUP BY o.BATTLE

 5. Имената на битките, в които са участвали поне 3 кораба с под 9 оръдия и от тях поне 2 са победили (OUTCOMES.RESULT = 'ok')

SELECT o.BATTLE FROM OUTCOMES o JOIN SHIPS s ON o.SHIP = s.NAME JOIN CLASSES c ON s.CLASS = c.CLASS WHERE c.NUMGUNS < 9 GROUP BY o.BATTLE HAVING COUNT(*) >= 3 AND SUM(CASE o.RESULT WHEN 'ok' THEN 1 ELSE 0 END) >= 2

 6. Битките, в които са участвали поне 3 кораба на една и съща страна

SELECT DISTINCT o.BATTLE FROM OUTCOMES o JOIN SHIPS s ON o.SHIP = s.NAME JOIN CLASSES c ON s.CLASS = c.CLASS GROUP BY o.BATTLE, c.COUNTRY HAVING COUNT(*) >= 3