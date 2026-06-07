# Задачи без номер

<details>
    <summary>Задача</summary>

Данните *homeprices* съдържат информация за цените (в хиляди) на къщите в New Jersey, през 2001 година в колоната *list* и броя на всички стаи в колоната *rooms*. Напишете скрипт, с който да моделирате зависимостта на цената от броя на всички стаи. Ако резултатът от направения аналиц е:

```
Residuals:
    Min   1Q   Median  3Q    Max
-145.54 -54.16 -19.54 64.65 223.46

Coefficients:
            Estimate Std. Error t value Pr(>|t|)
(Intercept) -54.10          87.20 -0.964 0.343355 ***
rooms        49.81          11.85 4.204 0.000257 *
Signif. codes: 0 '***' 0.001 '**' 0.01 '*' 0.05 '.' 0.1 ' ' 1
Residual standard error: 65.34 on 27 degrees of freedom
Multiple R-squared: 0.3956, Adjusted R-squared: 0.3752
F-statistic: 17.67 on 1 and 27 DF, p-value: 0.0002575
```
напишете уравнението на регресия. Напишете скрипт, с който да пресметнете очакваната цена на жилище с 1 стая.

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

Напишете за всяка една от колоните качествени или каличествени данни съдържа. Напишете скрипт в R, с който да се изведе честотна таблица на пола на студентите и направете подходяща графика.
</details>

<details>
    <summary>Задача</summary>

Наблюдавани са средните месечни разходи на жените и мъжете за облекло. Резултатите от наблюдението са записани съответно в променливите female и male. Напишете скрипт в R, с който да се провери дали полът оказва статистически значимо влияние на разходите за облекло. Формулирайте хипотезите. Използвайте риск за грешка от първи род 5%. Ако е получен следния резултат:

```
data: female and male
t = 5.0633, df = 401.05, p-value = 6.295e-07
alternative hypothesis: true difference in means is not equal to 0
94 percent confidence interval:
    2.843915    6.451946
sample estimates:
mean of x   mean of y
40.34272    35.69524
```

Анализирайте го.
</details>

<details>
    <summary>Задача</summary>

```
Sigin. codes: 0 '\*\*\*' 0.001 '\*\*' 0.01 '\*' 0.05 '.' 0.1 ' ' 1
Residual standard error: 37.97 on 23 degree of freedom
Multiple R-squared: 0.9183, Adjusted R-squared: 0.9006
F-statistics: 51.74 on 5 and 23 DF, p-value: 9.358e-12
```

Кои са статистически значимите фактори за цената? Ако е направен и следният модел:

```
Call:
lm(formula = list - full + half + bedrooms + neighborhood, data = homeprice)
Residuals:
    Min     1Q      Median      3Q      Max
-57.757     -30.942 4.129       27.084  58.609
Coefficients:
                Estimate Std.   Error   t value     Pr(>|t|)
(Intercept)     -133.404        32.096  -4.156      0.000355 ***
full            33.355          13.177  2.531       0.018328 *
half            48.094          11.748  4.094       0.000416 ***
bedrooms        28.094          9.775   2.910       0.007675 **
neighborhood    79.057          9.366   8.441       1.2e-08  ***
Signif. codes: 0 '\*\*\*' 0.001 '\*\*' 0.01 '\*' 0.05 '.' 0.1 ' ' 1
Residual standard error: 37.57 on 24 degree of freedom
Multiple R-squared: 0.9166, Adjusted R-squared: 0.9026
F-statistics: 65.91 on 4 and 24 DF, p-value: 1.367e-12
```

Кой от двата модела е по-добър и защо? Моделите адекватни ли са?

```
И в двата случая най-значим е meighborhood, защото t value е най-високо и стандартната грешка е най-малка.
И стойностите на pr са значими, защото имат ***. Вторият модел е по-добър, защото adjusted r-squared е по-голяма.
Да, адекватни са.
```

</details>