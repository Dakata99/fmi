# Task 1
library(MASS)
names(survey)
summary(survey)

# A)
prob_regular_smoker <- sum(survey$Smoke == 'Regul', na.rm = TRUE) / sum(!is.na(survey$Smoke))
prob_regular_smoker

# B)


# C)


# D)
