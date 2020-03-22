from tkinter import *

#Фон серый, границы фигур- черные, координаты 
c = Canvas(width=460,height=460,bg='grey80') #bg- темнота
c.pack()
oval = c.create_oval(30,10,130,80)
rect = c.create_rectangle(180,10,280,80)
trian = c.create_polygon(330,80,380,10,430,80, fill='grey80', outline="black")

#Перемещение прямоугольника по оси
c.move(rect,0,150) 
c.itemconfig(trian,outline="red", width = 3) #width- толщина обводки
c.coords(oval,300,200,450,450) #Овал смещается и увеличивается в размерах


def mooove(event):
    c.move(rect,0,2) #Смещает прямоугольник на 2 пикселя
c.bind('<Button-1>',mooove) #Bind - нажатие


oval = c.create_oval(30,10,130,80,tag="group1")
c.create_line(10,100,450,100,tag="group1")

def color(event):
    c.itemconfig('group1',fill="red",width=3)
c.bind('<Button-3>',color)

def clean(event):
    c.delete('all')

c.bind('<Button-2>',clean)


