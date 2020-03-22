from tkinter import *

c = Canvas(width=450, height=450, bg='grey80')
c.pack()

oval = c.create_rectangle (40, 15, 160, 50)
c.itemconfig(oval, outline='green', fill='yellow', width = 10)

def moove(event):
    c.move(oval, 10, 5)
c.bind('<Button-1>', moove)

def color(event):
    c.itemconfig(oval, fill='blue',width=8)
c.bind('<Button-3>', color)


