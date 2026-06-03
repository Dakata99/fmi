# Basic Data Types

You can get an object’s type using the `typeof` function.

- `is.<class type>()` checks the <class type> of the object
- `as.<class type>()` converts the object to <class type>

## Logical

Logical values can take one of two values: TRUE or FALSE. They can also be represented as T and F. But be careful, because these values can be overwritten.

Where True is the same as 1 and False is the same as 0.
```{r}
> x <- 1
> y <- 2
> z <- x > y
```

`typeof` function prints the type of the object
```{r}
> typeof(z)
[1] "logical"
```

`is.logical` checks if the class type of the object is logical
```{r}
> is.logical(2.5)
[1] FALSE
> is.logical(y)
[1] FALSE
> is.logical(z)
[1] TRUE
> is(z, "logical")
[1] TRUE
```

`as.logical` converts the type of the object to logical one
```{r}
> x <- as.logical(10.5); x; typeof(x)
[1] TRUE
[1] "logical"
> x <- as.logical(1); x; typeof(x)
[1] TRUE
[1] "logical"
> x <- as.logical(0); x; typeof(x)
[1] FALSE
[1] "logical"
> x <- as.logical("string"); x; typeof(x)
[1] NA
[1] "logical"
```

### Some more examples
```{r}
> FALSE < TRUE
[1] TRUE
> 5 * TRUE
[1] 5
> NA != NA
[1] NA
> NA == NA # Use is.na(NA) to check if an object is NA
[1] NA
> 2 < Inf
[1] TRUE
> Inf == Inf
[1] TRUE
> -Inf < Inf
[1] TRUE
> NA < Inf
[1] NA
```

Strings are compared lexicographically
```{r}
> "data" == "statistics"
[1] FALSE
> "data" < "math"
[1] TRUE
```

You can also use the functions any, all and which
```{r}
> v <- c(FALSE, FALSE, TRUE, FALSE)
> any(v)
[1] TRUE
> which(v)
[1] 3
> v <- c(TRUE, TRUE, TRUE, TRUE)
> all(v)
[1] TRUE
```

`%in%` function tests whether an element is in a collection and match return their indexes in the collection
```{r}
> v <- c(36, 45, 23, 17, 64, 75)
> 17 %in% v
[1] TRUE
> match(17, v)
[1] 4
> c(17, 45, 12) %in% v
[1]  TRUE  TRUE FALSE
> match(c(17, 45, 12), v)
[1]  4  2 NA
```

## Integer

If you want variable’s type to be integer, you must set it explicitly.
```{r}
> x <- 3; x
[1] 3
> typeof(x)
[1] "double"
> is.integer(x)
[1] FALSE
```

We can define it as integer in one of the following ways:
```{r}
> y <- as.integer(12.35); y 
[1] 12
> typeof(y)
[1] "integer"
> z <- 3L; z
[1] 3
> typeof(z)
[1] "integer"
```

### Some more examples
```{r}
> typeof(4L * 2)
[1] "double"
> typeof(4L * 2L)
[1] "integer"
> typeof(6L / 2L)
[1] "double"
```

Integers have a limited range, roughly between −2∗109,2∗109. You can see ?.Machine for more information
```{r}
> .Machine$integer.max
[1] 2147483647
> as.integer(2147483647)
[1] 2147483647
> as.integer(2147483648)
Warning: NAs introduced by coercion to integer range
[1] NA
```

## Double

It describes all the real numbers.
```{r}
> k <- 1; k
[1] 1
> typeof(k)
[1] "double"
> is.numeric(k)
[1] TRUE
> x <- 10.5; x
[1] 10.5
> typeof(x)
[1] "double"
```

Doubles are able to represent a larger range of integer values, from −2.Machine$double.digits,2.Machine$double.digits. If you go outside that range, some integers are not exactly representable.
```{r}
> .Machine$double.digits
[1] 53
> print(max.num <- 2 ^ .Machine$double.digits)
[1] 9.007199e+15
> options(digits = 22)
> print(max.num <- 2 ^ .Machine$double.digits)
[1] 9007199254740992
> (max.num) - (max.num - 1)
[1] 1
> (max.num + 1) - (max.num)
[1] 0
> (max.num + 2) - (max.num + 1)
[1] 2
```

## Complex

It describes the set of complex numbers.
```{r}
> z <- 5 + 6i; z
[1] 5+6i
> typeof(z)
[1] "complex"
> is.complex(z)
[1] TRUE
> as.complex(4)
[1] 4+0i
```

## Character

```{r}
> s <- "statistics"; s
[1] "statistics"
> typeof(s)
[1] "character"
> is.character(s)
[1] TRUE
> as.character(123)
[1] "123"
```

Some operations with characters

`nchar` gives the number of characters in the string
```{r}
> nchar(s)
[1] 10
```

`substr` extract substrings
```{r}
> substr(s, start = 1, stop = 4)
[1] "stat"
```

It is worth mеntioning that you can’t concatenate strings with + sign.
```{r}
> x <- "1"
> y <- "3.5"
> x + y
Error in x + y: non-numeric argument to binary operator
```

We need to use C-style sprintf formatting
```{r}
> sprintf("X%s", 1:3)
[1] "X1" "X2" "X3"
```

or the paste function with parameters sep defining the separator between variables (default is sep=" ") and collapse to combine the elements of the resulting vector with the given delimiter.

```{r}
> paste(x, y)
[1] "1 3.5"
> paste("X", 1:3)
[1] "X 1" "X 2" "X 3"
> paste("X", 1:3, sep = "")
[1] "X1" "X2" "X3"
> paste("X", 1:3, sep = "", collapse = ", ")
[1] "X1, X2, X3"
```

Where the function converts the parameters to strings.
```{r}
> x <- 1
> y <- 3.5
> paste(x, y)
[1] "1 3.5"
```

You can work with regular expressions using grep function.
For examples lets look at state.name data (?state) containing the 50 full state names of the United States of America.
```{r}
> state.name
 [1] "Alabama"        "Alaska"         "Arizona"        "Arkansas"      
 [5] "California"     "Colorado"       "Connecticut"    "Delaware"      
 [9] "Florida"        "Georgia"        "Hawaii"         "Idaho"         
[13] "Illinois"       "Indiana"        "Iowa"           "Kansas"        
[17] "Kentucky"       "Louisiana"      "Maine"          "Maryland"      
[21] "Massachusetts"  "Michigan"       "Minnesota"      "Mississippi"   
[25] "Missouri"       "Montana"        "Nebraska"       "Nevada"        
[29] "New Hampshire"  "New Jersey"     "New Mexico"     "New York"      
[33] "North Carolina" "North Dakota"   "Ohio"           "Oklahoma"      
[37] "Oregon"         "Pennsylvania"   "Rhode Island"   "South Carolina"
[41] "South Dakota"   "Tennessee"      "Texas"          "Utah"          
[45] "Vermont"        "Virginia"       "Washington"     "West Virginia" 
[49] "Wisconsin"      "Wyoming"       
```

Let’s take the states containing v in their name. Parameter value=TRUE shows the matching elements, otherwise we will see their indexes.
```{r}
> grep(pattern = "v", state.name, value = TRUE)
[1] "Nevada"       "Pennsylvania"
> grep(pattern = "v", state.name)
[1] 28 38
```

If we want to also see the states containing V we need to add ignore.case=TRUE
```{r}
> grep(pattern = "v", state.name, ignore.case = TRUE, value = TRUE)
[1] "Nevada"        "Pennsylvania"  "Vermont"       "Virginia"     
[5] "West Virginia"
```

And for example if we want to see only those names of states starting with V
```{r}
> grep(pattern = "^V", state.name, value = TRUE)
[1] "Vermont"  "Virginia"
```

# Derived Data Types

The data types below are stored as either of the basic data types, but have additional attribute information that allows to be treated in special ways by certain functions in R. These attributes define the object’s class and can be extracted from that object via the class or attribute function.

## Factor</summary>

Factors are used to group variables into a fixed number of unique categories or levels.

For example imagine we have some weather sample:
```{r}
> weather <- c("Sunny", "Sunny", "Sunny", "Cloudy", "Sunny", "Sunny", "Cloudy",
                "Cloudy", "Stormy", "Cloudy", "Fog", "Sunny", "Sunny", "Cloudy",
                "Cloudy", "Stormy", "Cloudy", "Fog", "Rain", "Rain", "Snow", "Snow")
> weather
 [1] "Sunny"  "Sunny"  "Sunny"  "Cloudy" "Sunny"  "Sunny"  "Cloudy" "Cloudy"
 [9] "Stormy" "Cloudy" "Fog"    "Sunny"  "Sunny"  "Cloudy" "Cloudy" "Stormy"
[17] "Cloudy" "Fog"    "Rain"   "Rain"   "Snow"   "Snow"  
```

Lets convert it to factors. We have the same vector, but now with the unique labels of the categories.
```{r}
> factorWeather <- as.factor(weather)
> factorWeather
 [1] Sunny  Sunny  Sunny  Cloudy Sunny  Sunny  Cloudy Cloudy Stormy Cloudy
[11] Fog    Sunny  Sunny  Cloudy Cloudy Stormy Cloudy Fog    Rain   Rain  
[21] Snow   Snow  
Levels: Cloudy Fog Rain Snow Stormy Sunny
```

So how is this object represented?

Using the typeof we can see that the factor is saved in integer format
```{r}
> typeof(weather)
[1] "character"
> typeof(factorWeather)
[1] "integer"
> as.integer(factorWeather)
 [1] 6 6 6 1 6 6 1 1 5 1 2 6 6 1 1 5 1 2 3 3 4 4
```

Why is it storing the values as integer?

- The reason is the factor objects are storing each value as an integer that points to one of the unique levels.

Their respective class are:
```{r}
> class(weather)
[1] "character"
> class(factorWeather)
[1] "factor"
```

The factor object has 2 attributes: class and levels. Wherelevels shows all the possible categories for the data in the factor.
```{r}
> attributes(factorWeather)
$levels
[1] "Cloudy" "Fog"    "Rain"   "Snow"   "Stormy" "Sunny" 

$class
[1] "factor"
```

We can also see the unique levels and their order using levels function
```{r}
> levels(factorWeather)
[1] "Cloudy" "Fog"    "Rain"   "Snow"   "Stormy" "Sunny" 
```

The order in which the levels are displayed match their integer representation.

We can not assign a value into a factor unless it matches a level. Trying to will rise a warning and insert a value of NA
```{r}
> factorWeather[23] <- "Windy"
Warning in `[<-.factor`(`*tmp*`, 23, value = "Windy"): invalid factor level, NA
generated
> factorWeather
 [1] Sunny  Sunny  Sunny  Cloudy Sunny  Sunny  Cloudy Cloudy Stormy Cloudy
[11] Fog    Sunny  Sunny  Cloudy Cloudy Stormy Cloudy Fog    Rain   Rain  
[21] Snow   Snow   <NA>  
Levels: Cloudy Fog Rain Snow Stormy Sunny
```

First we need to add it to the levels of the factor
```{r}
> levels(factorWeather) <- c(levels(factorWeather), "Windy")
> factorWeather[23] <- "Windy"
> factorWeather
 [1] Sunny  Sunny  Sunny  Cloudy Sunny  Sunny  Cloudy Cloudy Stormy Cloudy
[11] Fog    Sunny  Sunny  Cloudy Cloudy Stormy Cloudy Fog    Rain   Rain  
[21] Snow   Snow   Windy 
Levels: Cloudy Fog Rain Snow Stormy Sunny Windy
```

This will be used when making plots in the next chapter.

## Date

Date, POSIXlt and POSIXct classes represent calendar dates.
- as.Date stores just dates using different origins

```{r}
> d <- as.Date("2019-05-27"); d
[1] "2019-05-27"
```

You can see that the object is of class Date and its type is double representing the number of dates after the origin.
```{r}
> class(d)
[1] "Date"
> typeof(d)
[1] "double"
> as.double(d)
[1] 18043
```

Dates can be in different format ?parse_date_time, but the output is in ISO 8601 international standard format %Y-%m-%d
```{r}
> d <- as.Date("05/27/19", format = "%m/%d/%y"); d
[1] "2019-05-27"
> d <- as.Date(18043, origin = "1899-12-30"); d
[1] "1949-05-25"
as.POSIXct stores data and time as the number of seconds since January 1, 1970
> t <- as.POSIXct("2019-05-27 17:42"); t
[1] "2019-05-27 17:42:00 EEST"
> typeof(t)
[1] "double"
> class(t)
[1] "POSIXct" "POSIXt" 
> as.Date(t)
[1] "2019-05-27"
> attributes(t)
$class
[1] "POSIXct" "POSIXt" 

$tzone
[1] ""
```

`as.POSIXlt` stores them as a list with elements for year, month, day, hour, minutes and seconds. We can see this using the function attribute.
```{r}
> t <- as.POSIXlt("2019-05-27 17:42"); t
[1] "2019-05-27 17:42:00 EEST"
> typeof(t)
[1] "list"
> class(t)
[1] "POSIXlt" "POSIXt" 
> as.Date(t)
[1] "2019-05-27"
> attributes(t)
$names
 [1] "sec"    "min"    "hour"   "mday"   "mon"    "year"   "wday"   "yday"  
 [9] "isdst"  "zone"   "gmtoff"

$class
[1] "POSIXlt" "POSIXt"
```

You can easily take the year from the list using $. It shows the number of years since 1900, so we see 2019 as 119.
```{r}
> t$year
[1] 119
```

Shows the month in 0−11 format, so we see May as 4.
```{r}
> t$mon
[1] 4
```

Shows the day in 1−31 format
```{r}
> t$mday
[1] 27
```

Shows the hours, minutes and seconds
```{r}
> t$hour
[1] 17
> t$min 
[1] 42
> t$sec
[1] 0
```
