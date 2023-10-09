# submit your solutions in this space
"""
Author: Amelia Bates
Class: CIS 210
Title: Math problems
Description: 5 destinct math problems using algebra
"""
import math
#First math problem: determines if the square root of a^2 + b^2 divided by 2 and then rounded to the 5th decimal place equals c
a = 2
b = 7.2
c = 3.73631
print("*****Question 1*****")
print((((math.sqrt((b**2)+(a**2)))/2)) == c) #will return False

#Second math problem: gives the result of 6 times x plus 7 and then multiplied by 2
x = 4
print("\n*****Question 2*****")
print(2*(6*x + 7)== 2*(6*x)+7) #will return False

#Third math problem: determine if b times a divded by c equals 4
a = 4.2
b = 8
c = 10.23
print("\n*****Question 3*****")
print(b*a//c == 4)#will return False

#Fourth math problem: gives the result of x^2 plus the absolute value of y divided by z, rounded to the 3rd decimal place
x = 6.4
y = -24
z = 12.8
print("\n*****Question 4*****")
print((x**2 + (abs(y)/z)) == x**2 + (y)/z)#will return False

#Fifth math problem: does y equal 3.2^2 times 4 divided 2 subtracted by .84
y = 20
print("\n*****Question 5*****")
print(y == round(((3.2**2 * 4)/2) - 0.84,2)) #will return False

