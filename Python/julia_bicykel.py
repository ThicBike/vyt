import tkinter
from random import *
canvas = tkinter.Canvas(w = 500, he = 500, bg = 'white')
canvas.pack()

color = ["red", "blue", "orange", "purple", "green", "lightblue", "black", "yellow", "darkgreen"]
kolesa_farba = choice(color)
ram_farba = choice(color)
sedadlo_volant_farba = choice(color)
loziska_farba = choice(color)

canvas.create_oval(25, 25, 475, 475, w = 40, fill = 'white', outline = 'red')

##lave koleso
canvas.create_oval(70, 240, 200, 370, w = 12, fill = 'white', outline = kolesa_farba)
canvas.create_oval(130, 300, 140, 310, w = 10, fill = loziska_farba, outline = loziska_farba)

##prave koleso
canvas.create_oval(300, 240, 430, 370, w = 12, fill = 'white', outline = kolesa_farba)
canvas.create_oval(360, 300, 370, 310, w = 10, fill = loziska_farba, outline = loziska_farba)

##pedal
canvas.create_oval(240, 290, 280, 330, w = 10, fill = 'white', outline = ram_farba)

##ram
canvas.create_line(280, 305 , 365, 305, w = 10, fill = ram_farba)
canvas.create_line(300, 220 , 365, 305, w = 10, fill = ram_farba)
canvas.create_line(260, 290 , 310, 200, w = 10, fill = ram_farba)
canvas.create_line(135, 300, 185, 175, w = 10, fill = ram_farba)
canvas.create_line(170, 220, 300, 220,  w = 10, fill = ram_farba)
canvas.create_line(165, 230, 245, 295,  w = 10, fill = ram_farba)

##volant & sedadlo
canvas.create_line(180, 180 , 210, 180, w = 10, fill = sedadlo_volant_farba)
canvas.create_line(280, 200 , 330, 200, w = 15, fill = sedadlo_volant_farba)
