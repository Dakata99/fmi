# Initializing needed data

# Statistics data frame
gender <- c("Male", "Female", "Female", "Male", "Female", "Male")
maritual_status <- c("Married", "Unmarried", "Married", 
                    "Unmarried", "Married", "Unmarried")
working_status <- c("Working", "Working", "Not working",
                    "Working", "Working", "Not working")
age <- c(45, 22, 36, 32, 42, 28)

statistics <- data.frame(gender, maritual_status, working_status, age)

# Countries data frame
country <- c("Austria", "Bhutan", "Canada", "Ethiopia", "Finland", "Honduras")
population2020 <- c(9006398, NA, 37742154, NA, 5540720, NA)
landaread <- c(82409, NA, 9093510, 1000000, NA, 111890)
density <- c(109, 20, 4, NA, NA, 89)

countries <- data.frame(country, population2020, landaread, density)

# Task 3
lapply(statistics, class)

# or
for (i in statistics) {
    print(class(i))
}

# Task 4
x <- c(5, 1, 5, 3, 2, 5, 3, 5)
x[which(x != 3)[2]]

# Task 5
library(MASS)
summary(survey)
shapiro.test(survey$Height)

# Task 7

# Task 8

# a)
rbinom(100, 10, 13 / 52)

# b)
pbinom(4, 10, 13 / 52)

# c)
pbinom(7, 10, 13 / 52) - pbinom(1, 10, 13 / 52)



# Task
table(is.na(countries))
sum(is.na(countries[2,]))
sum(is.na(countries[,2]))
colSums(is.na(countries))[2]

