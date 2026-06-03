# ---

x <- list(1, 2, 3); x

y <- list(a = 1, b = 2, c = 3); y

z <- list(a = c(1, 2, 4, 5),
          b = c(TRUE, FALSE, TRUE),
          c = c("Statistics")); z

p <- list(a = c(1, 2, 4, 5),
          b = list(c = c(TRUE, FALSE),
                   d = c(1, 2, 4),
                   e = c("string")),
          c = data.frame(x = 1:10, y = rep(c(TRUE, FALSE), 5))); p

# ---

str(p)

# ---

p$a
p[[1]]
p$b$c
p[[2]][[1]]

# ---

names(p)
names(p$b)