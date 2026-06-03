# Missing Data

## NA - missing value

```{r}
#| collapse: true
x <- c(1, 2, NA, 3, NA, 4); x
is.na(x)
sum(x)
```

Sum of the vector elements excluding **NA** values:

```{r}
#| collapse: true
sum(x, na.rm = TRUE)
```

## NULL - absence of anything

```{r}
#| collapse: true
y <- c(1, NULL, 2); y
is.null(y)
length(y)
```

## NaN, Inf

**NaN** and **Inf** values arise from arithmetic operations that are not defined.

```{r}
#| collapse: true
0/0
1/0
```
