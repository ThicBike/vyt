import tkinter
from random import *
canvas = tkinter.Canvas(w = 500, he = 500, bg = 'white')
canvas.pack()

y = 10
x = 0
posun = 100

for i in range(5):
    print(i)
    canvas.create_line(x, y, x + posun, y, w = 2, fill = "black")
    canvas.create_line(x + posun, y, x + posun, y + posun, w = 2, fill = "black")
    x += posun
    y += posun
