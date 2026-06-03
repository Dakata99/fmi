# ---

x <- c(1, 2, 3); x
y <- c(4, 5, 6, 7, 8, 9, 10); y
z <- c(FALSE, TRUE); z
str <- c("e", "x", "a", "m", "p", "l", "e"); str

# ---

typeof(x)
typeof(y)
typeof(z)
typeof(str)
typeof(pi)
p <- c(5, 6.4, "string"); p
typeof(p)

# ---

x <- c(1, 2, 3); x
x + 2
5 * x
x^2
sqrt(x)

# ---

length(x)
sum(x)

# ---

x <- c(1, 2, 3)
y <- c(5, 6, 7)
x + y
y - x
x * y
x / y

# ---

x <- c(1, 2, 3)
y <- c(5, 6, 7, 8, 9, 10)
x + y 
y - x
x * y
x / y

# ---

y <- c(5, 6, 7, 8, 9, 10)
y[3]
y[c(3, 4)]
y[c(4, 2, 3)]
y[-3]
y[8]

# ---

y[9] <- 11
y

# ---

y[10:15] <- 3
y

# ---

y[0]
numeric(0)

# ---

y[]

# ---

1:12
1:-9
seq(1, 17, by = 2)
seq(0, 100, length.out = 5)
rep(1:3, times = 2)
rep(1:3, times = 3:1)
rep(1:3, each = 2)
rep(1:3, each = 2, times = 2)

# ---

x <- 5:7; x
y <- 2:5; y
y <= 3
x[y <= 3]
sum(y <= 3)
sum(x[y <= 3])
which(y >= 3)
x[which(y >= 3)]
z <- 5:21; zz[y <= 3] # Different vectors length!!!

# --

testScores <- c(Sophia = 73, Olivia = 87, Bob = 72, Liam = 99)
testScores

# ---

names(testScores) <- c("Brown", "Grant", "Johnson", "Smith")
testScores

# ---

testScores <- setNames(c(73, 87, 72, 99), c("Sophia Brown", "Olivia Grant", "Bob Johnson", "Liam Smith"))
testScores

# ---

names(testScores)

# ---

precip["Los Angeles"]

# ---

head(precip)
tail(precip)

# ---

head(sort(precip), n = 15)
head(sort(precip, decreasing = TRUE), n = 15)
