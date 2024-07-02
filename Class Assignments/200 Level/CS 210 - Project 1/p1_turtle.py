# submit your solution in this space
"""
Author: Amelia Bates
Class: CIS 210 
Resources used: PythonContextCH01.pdf slides on canvas
Title: Duck Drawing
Description: Create a drawing of a duck using turtle
"""
import turtle
t = turtle.Turtle()
"""
def drawPolygon(t, sideLength, numSides):
    turnAngle = 360 / numSides
    for i in range(numSides):
        t.fd (sideLength)
        t.right(turnAngle)
def drawCircle(t, radius):
    circumfrence = 2 * 3.1415 * radius
    sideLength = circumfrence / 360
    drawPolygon(t, sideLength, 360)
"""
def drawTriangle(t, sideLength):
    for i in range(3):
        t.forward(sideLength)
        t.right(120)
t.circle(20)
t.right(90)
t.circle(30,300)
t.penup()
t.goto(-30,20)
t.right(180)
t.pendown()
drawTriangle(t,10)
t.penup()
t.goto(35,-10)
t.pendown()
t.circle(10,180)
t.hideturtle()
