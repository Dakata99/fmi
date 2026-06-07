# Task 1

print("-------------- Task 1 --------------")
print("Creating a vector and making it into matrix:")
vec <- c(8, 3, 8, 7, 15, 9, 12, 4, 9, 10, 5, 1);
mrx <- matrix(data = vec, nrow = 5, ncol = 2); mrx

print("Naming rows in matrix:")
rownames(mrx) <- c("r1", "r2", "r3", "r4", "r5"); mrx
# colnames(mrx) <- c("c1", "c2"); mrx

print("Add 3rd column in matrix:")
mrx <- cbind(mrx, c(1, 3, 5, 7, 9)); mrx

print("Sort matrix by first column in ascending order:")
mrx[order(mrx[,1]),]

# Task 2
print("-------------- Task 2 --------------")
# install.packages("UsingR")
library(UsingR)
head(homedata)
attach(homedata)

# A)
homes1970 <- homedata$y1970 # or homes1970 <- head(homedata)[,1];
homes2000 <- homedata$y2000 # or homes2000 <- head(homedata)[,2];

min_price2000 <- min(homes2000)
max_price2000 <- max(homes2000)

sprintf("Most cheapest house A during 2000: %d", min_price2000)
sprintf("Most expensive house B during 2000: %d", max_price2000)

sprintf("House A's price during 1970: %d", homes1970[which(homes2000 == min_price2000)])
sprintf("House B's price during 1970: %d", homes1970[which(homes2000 == max_price2000)])

# B)
tail(sort(homes2000), 5)

# C)
sum(homes2000 > 750000)

# D)
most_expensive1970 <- homes1970[homes2000 > 750000];
mean(most_expensive1970)

# E)
homes2000[which(homes2000 < homes1970)]

# F)
x <- (homes2000 - homes1970) / homes1970
head(sort(x, decreasing = TRUE), 10)

# Task 3
print("-------------- Task 3 --------------")
# install.packages("MASS")
library(MASS)
head(survey)
summary(survey)

# A)
sprintf("Number of males: %d", sum(survey$Sex == "Male", na.rm = TRUE))

# B)
sprintf("Number of males, who smoke: %d", sum(survey$Sex == "Male" & survey$Smoke != "Never", na.rm = TRUE))

# C)
sprintf("Average height of males: %f", mean(survey[survey$Sex == "Male", "Height"], na.rm = TRUE))
sprintf("Average height of males: %f", mean(survey[survey$Sex == "Male", ]$Height, na.rm = TRUE))

# D)
print("Height and sex of the 6 youngest students:")
sort(survey$Age)[1:6]
survey[order(survey$Age)[1:6], c("Age", "Height", "Sex")]