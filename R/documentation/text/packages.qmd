# Packages

## Installing packages

R has a rich collection of packages. They allow researchers to share R functions and data. You can install packages available in the CRAN repository using install.packages. We already learned how we can get help

```{r}
?install.packages
help("install.packages")
```

You can also install packages from the R Studio interface

For the next tasks you will need to install UsingR and MASS packages available in the CRAN repository.

```{r}
install.packages("UsingR")
install.packages("MASS")
```

We can also install packages from GitHub using install_github. But first you need to install devtools from CRAN.

You can also see available packages using the available.packages or update a package using update.packages functions.

## Loading packages

Just because a package is installed on your computer does not mean that you have access to its functions. We need to load the package into the current R session. Getting help

```{r}
?library
```
Load the package in the memory

```{r}
library(UsingR)
library(MASS)
```

In R we have Warning and Error messages. Warning messages do not stop the flow of the function.

You can also use the require function to load a package.

## Session info

You can see information about your current session - R version, OS, attached or loaded packages and their versions using sessionInfo.

```{r}
sessionInfo()
```

## Unloading packages

Sometimes you need to unload a package.
```{r}
#| eval: false
detach("package:MASS")
```

## Uninstalling packages

remove.packages remove installed packages.
```{r}
#| eval: false
remove.packages("MASS")
```

## Example

Next are considered examples with mtcars data frame from datasets package.
```{r}
head(mtcars)
```

Wring ? before the name of the data frame gives information about the data frame, if it is available.

```{r}
?mtcars
```

You can see what is this data frame about and some information about the data contained in the columns.

As we already saw we can use dim,nrow and ncol to show the dimensions of the data frame

```{r}
dim(mtcars)
nrow(mtcars)
ncol(mtcars)
```

Next different ways to take only part of the data frame are reviewed.
Shows the element in the 1 row, 2 column

```{r}
mtcars[1, 2]
```

Shows the element in the “Mazda RX4” row, “cyl” column

```{r}
mtcars["Mazda RX4", "cyl"]
```

Shows the elements in the 9 column

```{r}
mtcars[[9]]
```

Shows the element in the “am” column
```{r}
mtcars[["am"]]
```

Shows the element in the “am” column

```{r}
mtcars$am
```

## Attach data frame

Taking the names of the columns in the data frame

```{r}
names(mtcars)
```

Let’s say we want to take the mpg column, we can use $ after the data frame’s name

```{r}
mtcars$mpg
```

or to attach the data frame and only to write the name of the column.
```{r}
attach(mtcars)
mpg
```

attach loads the data frame, so it is not necessary to write the data frame’s name in front of the column name.
Getting help

```{r}
?attach
```

Sometime this is very helpful, but it is important to notice that if you change the attached object the data frame is not going to change. For example let’s change the first value

```{r}
mpg[1] = 200
mpg
mtcars$mpg
```
