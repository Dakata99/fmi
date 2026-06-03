# --- Arithmetic operators ---

print(2 + 3) # Addition

print(2 + 3 + 5)

print(2 - 4) # Subtraction

print(2 * 3) # Multiplication

print((2 + 3) * 4)

print(11 / 3) # Division

print(11 %/% 3) # Integer Division

print(11 %% 3) # Modulus - remainder after the division

# ** is old /still not deprecated/ translated to ^ in the parser.
print(2 ** 3) # Raise to a power
 
print(2 ^ 3) # Raise to a power

# For double inputs, R uses EIC 60559 arithmetic 
# The result in this example is mandated by the C99 Standard
print((-2) ^ (1 / 3)) # Nan

apropos("sq")

# Using find we can find from which package is the function
# We can only search functions from the already loaded packages.
find("sqrt")

x = 5
y <- 5  # Recommended
5 -> z
x; y; z # Prints

x = 20
mean(x = 3); x
mean (x <- 3); x # Not a good idea

A <- 5
# a; # Error: object 'a' not found

a <- 5
a <- 5.4
a <- "string"

a
print(a)

print(a, quote = FALSE)

a <- 3145.429357453; a
print(a, digits = 10)

getwd()

ls()

rm(x, y, z)
ls()

rm(list = ls())
ls()