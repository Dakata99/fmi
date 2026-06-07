# ---

first <- 1:10 
second <- c("aa", "bb", "cc", "dd", "ee", "ff", "gg", "hh", "ii", "jj") 
third <- c(TRUE, FALSE, TRUE, TRUE, FALSE, TRUE, FALSE, FALSE, TRUE, FALSE) 
df <- data.frame(first, second, third); df

class(df)

# ---

head(df)

tail(df)

# ---

head(df, n = 3)

tail(df, n = 3)

# ---

dim(df)

dim(df)[1]

dim(df)[2]

nrow(df)

ncol(df)
# ---

str(df)

# ---

df <- data.frame(A = first, B = second, C = third); df

# ---

names(df)

# ---

colnames(df) <- c("f", "s", "t"); df

rownames(df) <- c("one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"); df

# ---

colnames(df) <- LETTERS[1:3]; df

rownames(df) <- month.name[1:10]; df

# ---

attributes(df)
 
names(df)

colnames(df)

rownames(df)

# ---

df[2, 3]

# ---

df[2, ]

# ---

df[, 3]

# ---

df[2, 2:3]

# ---

df[2, c("A" , "B")]

# ---

df$A

# ---

df[[2]]
