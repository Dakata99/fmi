# Reading Data

## Reading from the command line

```scan()``` function will scan the keyboard until an empty line is specified.

If the file that you are going to read is saved in your working directory, you do not need to specify the whole path to the file or you can use file.choose function.

## Reading from .txt file

Getting help

```{r}
?read.table
```

read.table reads a file and creates a data frame from it. By default it doesn’t have a header.

```{r}
#| eval: false
ourData <- read.table("./data.txt", header = TRUE, sep="")
head(ourData)
```

## Reading from .csv file

Getting help

```{r}
?read.csv
```

csv stands for comma-separated values. read.csv reads a file and creates a data frame from it. By default it has a header and the values are separated sep by ,.

# TODO: read files
```{r}
#| eval: false
pokemon <- read.csv("./pokemon.csv")
head(pokemon)
```

```{r}
#| eval: false
titanic <- read.csv("./titanic.csv")
head(titanic)
```
