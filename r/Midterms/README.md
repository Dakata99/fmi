<details>
    <summary>Тест 1</summary>

<details>
    <summary>Задача 1</summary>

Кои от следните разпределения са симетрични?

a) t(10)  
b) Chi ^ 2(5)  
c) Exp(3)  
d) N(5, 2)

Отговор: а)?
</details>

<details>
    <summary>Задача 2</summary>

В променливата delivery са дадени данните за времената на доставка на пица на 100 клиента. Ако то няма крайна дисперсия, напишете скрипт в R, с който да построите 93% доверителен интервал за средно време на доставка.

Отговор: t.test(delivery)
</details>

<details>
    <summary>Задача 3</summary>

Първите 6 реда на дейтасета "statistics" изглеждат така:

|   |  gender | maritualStatus | workingStatus | age |
|---|---------|----------------|---------------|---- |
| 1 |  Male   | Married        | Working       | 45  |
| 2 |  Female | Unmarried      | Working       | 22  |
| 3 |  Female | Married        | Not working   | 36  |
| 4 |  Male   | Unmarried      | Working       | 32  |
| 5 |  Female | Married        | Working       | 42  |
| 6 |  Male   | Unmarried      | Not working   | 28  |

Напишете скрипт в R, който да покаже класа на всяка от колоните.
</details>

<details>
    <summary>Задача 4</summary>

Нека x <- c(5, 1, 5, 3, 2, 5, 3, 5) да са резултатите от подхвърляне на несиметричен 6 стенен зар. Напишете израз, който извежда само втория различен от 3 елемент на х. Напишете израз, който оценява елемент да е по-голям от 3?
</details>

<details>
    <summary>Задача 5</summary>

За данните "survey" от пакета "MASS", съдържащи височината на студентите "Height". Напишете ф-я, с която да направите Шапира-Уилк теста за проверка дали данните за височината на студентите са нормално разпределени. Получени са следните резултати. Анализирайте ги.
```
    Shapiro-Wilk normality test
data: survey$Height
W = 0.98841, p-value = 0.08844
```

Отговор:
```
shapiro.test(survey$Height)
Можем да кажем, че данните са нормално разпределени, ако p е над 0.05.
```
</details>

<details>
    <summary>Задача 7</summary>

Първите 6 реда на дейтасета "students" изглеждат така:

|   |  Sex    | Pulse | Exer | Smoke | Height |   Age  |
|---|---------|-------|--------------|--------|--------|
| 1 |  Female |  92   | Some | Never | 173.00 | 18.250 |
| 2 |  Male   |  104  | None | Regul | 177.80 | 17.583 |
| 3 |  Male   |  87   | None | Occas | NA     | 16.917 |
| 4 |  Male   |  NA   | None | Never | 160.00 | 20.333 |
| 5 |  Male   |  75   | Some | Never | 165.00 | 23.667 |
| 6 |  Female |  64   | Some | Never | 172.72 | 21.000 |

Напишете скрипт в R, който въз основа на данните да оцени вероятността случайно избран, понякога спортуващ човек, да се окаже с пулс между 60 и 70 удара в минута включително. Начертайте хистограми на разпределението на студентите според пулса им, ако е известно колко често спортуват.
</details>

<details>
    <summary>Задача 8</summary>

Нека х е броя на пиките, паднали се при случайно изтегляне на 10 карти с връщане от колода от 52 карти. Използвайте вградени ф-ии в R, за да:  
a) Генерирате 100 наблюдения над х. - rbinom(100, 10, 13 / 52)  
b) Пресметнете теоретичната вероятност да има по-малко от 5 пики? - pbinom(4, 10, 13 / 52)  
c) Пресметнете теоретичната вероятност броят на изтеглените пики да попадне в интервала [2, 7]? - pbinom(7, 10, 13 / 52) - pbinom(1, 10, 13 / 52)  
</details>

<details>
    <summary>Задача 9</summary>

Машина за пакетиране разсипва препарат в кутии. Теглото на препарата (в грама) във всяка кутия е нормално разпределена случайна величина N(200, 25).  
a) Симулирайте теглата на съдържанието на 500 опаковки. - rnorm(500, 200, 5)  
b) Намерете вероятността кутията да съдържа по-малко от 205 грама препарат. - pnorm(205, 200, 5)  
c) Кое е минималното тегло на препарата, което ще се съдържа в кутиите с вероятност поне 0.92. - qnorm(0.92, 200, 5)  
</details>

<details>
    <summary>Задача 10</summary>

В променливата *rat* са дадени данните за времето на преживяване на 20 плъха, облъчени с радиация. Ако времето за преживяване е приблизително нормално разпределено, напишете скрипт в R за проверка на хипотезата, че средното време на живот на плъховете след облъчване с радиация е повече от 100 дни. Формулирайте хипотезите. Работете с риск за грешка от първи род 0,97. Ако резултатът е:

```
data: rat
t = 1.6807, df = 19, p-value = 0.0544
alternative hypothesis: true mean is greater than 100
97 percent confidence interval:
97.44429    inf
sample estimates:
mean of x
113.45
```

Анализирайте го.

```
H0: L <= 100
H1: L > 100
t.test(x = rat, mu = 100, conf.level = 0.97, alternativa = "greater")
Ниво на съгласие: 0.03
p-value = 0.0546 > 0.03 => не отхвърляме нулевата, приемема я за вярна
```
</details>

<details>
    <summary>Задача 11</summary>

Нека х е броя на пиките, паднали се при случайно изтегляне на 10 карти с връщане от колода от 52 карти. Използвайте вградени ф-ии в R, за да:
a) Генерирате 200 наблюдения над х.
b) Пресметнете теоретичната вероятност да има поне 5 пики включително?
c) Пресметнете теоретичната вероятност броят на изтеглените пики да попадне в интервала [2, 7)?
</details>

<details>
    <summary>Задача 12</summary>
Първите 6 реда на дейтасета "statistics" изглеждат така:

|   |  gender | maritualStatus | workingStatus | age |
|---|---------|----------------|---------------|---- |
| 1 |  Male   | Married        | Working       | 45  |
| 2 |  Female | Unmarried      | Working       | 22  |
| 3 |  Female | Married        | Not working   | 36  |
| 4 |  Male   | Unmarried      | Working       | 32  |
| 5 |  Female | Married        | Working       | 42  |
| 6 |  Male   | Unmarried      | Not working   | 28  |

Коя/Кои от следните ф-ии в R ще добавят нова колона, съдържаща нормализираната възраст.

a) statistics$normalized <- scale(age)  
b) statistics$normalized <- age / sd(age)  
c) statistics$normalized <- age - mean(age) / sd(age)  
d) statistics$normalized <- age - mean(age)

</details>

<details>
    <summary>Задача 13</summary>

Първите 6 реда на data frame-a "statistics" изглеждат така:

|   |  gender | maritualStatus | workingStatus | age |
|---|---------|----------------|---------------|---- |
| 1 |  Male   | Married        | Working       | 45  |
| 2 |  Female | Unmarried      | Working       | 22  |
| 3 |  Female | Married        | Not working   | 36  |
| 4 |  Male   | Unmarried      | Working       | 32  |
| 5 |  Female | Married        | Working       | 42  |
| 6 |  Male   | Unmarried      | Not working   | 28  |

Напишете код в R, който да конвертира пола във факторна променлива.
</details>

<details>
    <summary>Задача 15</summary>
Първите 6 реда на дейтасета "statistics" изглеждат така:

|   |  gender | maritualStatus | workingStatus | age |
|---|---------|----------------|---------------|---- |
| 1 |  Male   | Married        | Working       | 45  |
| 2 |  Female | Unmarried      | Working       | 22  |
| 3 |  Female | Married        | Not working   | 36  |
| 4 |  Male   | Unmarried      | Working       | 32  |
| 5 |  Female | Married        | Working       | 42  |
| 6 |  Male   | Unmarried      | Not working   | 28  |

Напишете скрипт в R, който да изведе 0.25 квантил на възрастта на мъжете.
</details>

<details>
    <summary>Задача</summary>

Данните *homeprices* съдържат информация за цените (в хиляди) на къщите в New Jersey, през 2001 година в колоната *list* и броя на отделните бани в колоната *half*. Напишете скрипт, с който да моделирате зависимостта на цената от броя на отделните бани. Ако резултатът от направения аналиц е:

```
Residuals:
    Min   1Q   Median  3Q    Max
-185.63 -77.23 -24.17 60.37 259.37

Coefficients:
            Estimate Std. Error t value Pr(>|t|)
(Intercept) 228.63   29.56 7.733 2.57e-08 ***
half        70.54    31.84 2.215 0.0354 *
Signif. codes: 0 '***' 0.001 '**' 0.01 '*' 0.05 '.' 0.1 ' ' 1
Residual standard error: 112.8 on 27 degrees of freedom
Multiple R-squared: 0.1538, Adjusted R-squared: 0.1225
F-statistic: 4.907 on 1 and 27 DF, p-value: 0.03536
```
напишете уравнението на регресия. Напишете скрипт, с който да пресметнете очакваната цена на жилище с 1 отделна баня.

```
Скрипт:
model <- lm(list - half, data = homeprices)

Уравнение на регресия:
y = 228.63 + 70.54 * half

Очаквана цена на жилище с 1 отделна баня:
y = 228.63 + 70.54 * t (или е по 1)
```

</details>

<details>
    <summary>Задача </summary>

Първите 6 реда на дейтасета "statistics" изглеждат така:

|   |  gender | maritualStatus | workingStatus | age |
|---|---------|----------------|---------------|---- |
| 1 |  Male   | Married        | Working       | 45  |
| 2 |  Female | Unmarried      | Working       | 22  |
| 3 |  Female | Married        | Not working   | 36  |
| 4 |  Male   | Unmarried      | Working       | 32  |
| 5 |  Female | Married        | Working       | 42  |
| 6 |  Male   | Unmarried      | Not working   | 28  |

Напишете код в R, който да добави нова колона, съдържаща центрираната в 0-лата възраст.
</details>


<details>
    <summary>Задача </summary>

Първите 6 реда на data frame-a "countries" изглеждат така:

|   | country  | population2020 | landarea | density |
|---|----------|----------------|----------|---------|
| 1 | Austria  | 9006398        | 82409    | 109     |
| 2 | Bhutan   | NA             | NA       | 20      |
| 3 | Canada   | 37742154       | 9093510  | 4       |
| 4 | Ethiopia | NA             | 1000000  | NA      |
| 5 | Finland  | 5540720        | NA       | NA      |
| 6 | Honduras | NA             | 111890   | 89      |

Кои/Коя от следните ф-ии няма да върне броя на липсващите стойности за популацията на ... ната година.

a) table(is.na(countries))  
b) sum(is.na(countries([2,])))  
c) sum(is.na(countries[,2]))  
d) colSums(is.na(countries))[2]
</details>

<details>
    <summary>Задача </summary>

Клиентите на даден интернет доставчик създават нови акаунти със средна интензивност от 10 акаунта на ден. Нека Х е поансово разпределена случайна величина, която моделира броя на акаунтите, които ще бъдат създадени през утрешния ден.  
a) Симулирайте 200 реализации на Х. - rpois(200, 10)
b) Пресметнете вероятността да бъдат създадени точно 13 акаунта. - dpois(13, 10)
c) Намерете минималния брой акаунти, които ще бъдат създадени утре с вероятност поне 0.95. - qpois(0.95, 10)
</details>

<details>
    <summary>Задача</summary>

Първите 6 реда на дейтасета "statistics" изглеждат така:

|   |  gender | maritualStatus | workingStatus | age |
|---|---------|----------------|---------------|---- |
| 1 |  Male   | Married        | Working       | 45  |
| 2 |  Female | Unmarried      | Working       | 22  |
| 3 |  Female | Married        | Not working   | 36  |
| 4 |  Male   | Unmarried      | Working       | 32  |
| 5 |  Female | Married        | Working       | 42  |
| 6 |  Male   | Unmarried      | Not working   | 28  |

Колоната с възрастта по погрешка е прочетена като факторна променлива. Напишете код в R, който да конвертира колоната, съдържаща възрастта, в числова променлива.

Отговор: ```statistics[4] <- as.numeric(statistics[4]) ```
</details>

<details>
    <summary>Задача </summary>

Първите 6 реда на дейтасета "statistics" изглеждат така:

|   |  gender | maritualStatus | workingStatus | age |
|---|---------|----------------|---------------|---- |
| 1 |  Male   | Married        | Working       | 45  |
| 2 |  Female | Unmarried      | Working       | 22  |
| 3 |  Female | Married        | Not working   | NA  |
| 4 |  Male   | Unmarried      | Working       | 32  |
| 5 |  Female | Married        | Working       | 42  |
| 6 |  Male   | Unmarried      | Not working   | 28  |

Имаме една липсваща стойност за възрастта на една от жените. Напишете скрипт в R, който да попълни тази липсваща стойност със средната възраст на жените.
</details>

<details>
    <summary>Задача </summary>

Никола измервал температурата в един и същ час в продължение на 10 дни, но в някои от дните, приятелите му го разсейвали и не могъл да запише изверванията си. Получил следните резултати:
```weather <- c(9, 11, NA, 12, 9, 7, NA, 9, 11, NA)```
Помогнете му да напише код на R, с който да намери среднотоаритметично на температурите за тези 10 дни.

Отговор: mean(weather)
</details>
</details>

