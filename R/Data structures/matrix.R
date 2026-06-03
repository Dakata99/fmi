# ---

A <- matrix(c(2, 4, 1, 5, 7, 6),
            nrow = 2,
            ncol = 3)
A

A <- matrix(c(2, 4, 1, 5, 7, 6),
            nrow = 2,
            ncol = 3,
            byrow = TRUE)
A

B <- matrix(c(2, 4, 3, 1, 5, 7),
            nrow = 3,
            ncol = 2)
B

# ---

dim(B)

# ---

A[2, 3]
A[2, ]
A[, 3]
A[, c(1, 3)]

# ---

A

A + 3

G <- matrix(rep(1:2, times=3), nrow = 2); G

A + G

A * G

# ---

t(A)

# ---

G %*% t(A)

# ---

cbind(c(1, 2, 3), c(3, 4, 5))

cbind(B, c(3, 4, 5))

# ---

rbind(c(1, 2, 3), c(3, 4, 5))

C <- rbind(A, c(3, 4, 5)); C

# ---

dimnames(C) <- list(c("r1", "r2", "r3"), c("c1", "c2", "c3"))
C

# ---

colnames(C) <- c("col1", "col2", "col3")
C

rownames(C) <- c("row1", "row2", "row3")
C
