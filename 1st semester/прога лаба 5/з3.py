from tkinter import *
import time
import _thread

c = Canvas(width=120, height=320, bg='grey80')
c.pack()

oval1 = c.create_oval(20,20,100,100, fill='black')
oval2 = c.create_oval(20,120,100,200, fill='black')
oval3  = c.create_oval(20,220,100,300, fill='black')

def func():
    cnt = 10
    while cnt > 0:
        c.itemconfig(oval1, fill = 'red')
        time.sleep(3)
        c.itemconfig(oval2, fill = 'yellow')
        time.sleep(2)
        c.itemconfig(oval1, fill = 'black')
        c.itemconfig(oval2, fill = 'black')
        c.itemconfig(oval3, fill = 'green')
        time.sleep(4)
        
        cntgr = 5
        while cntgr > 0:            
            c.itemconfig(oval3, fill = 'green')
            cntgr -=1
        c.itemconfig(oval3, fill = 'black')
        c.itemconfig(oval2, fill = 'yellow')
        time.sleep(2)
        c.itemconfig(oval2, fill = 'black')
        cnt -= 1
    _thread.exit()


_thread.start_new_thread(func, ())

mainloop()
