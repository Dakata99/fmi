# Task 1
library(MASS)
names(survey)
summary(survey)

# A)
prob_regular_smoker <- sum(survey$Smoke == 'Regul', na.rm = TRUE) / sum(!is.na(survey$Smoke))
prob_regular_smoker

# B)
prob_reg_sm_male <- sum(survey$Smoke == 'Regul' & 
                        survey$Sex == 'Male', na.rm = TRUE) / sum(!is.na(survey$Smoke) & !is.na(survey$Sex))
prob_reg_sm_male

# C)

# D)
