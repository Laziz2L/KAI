import threading
import time
from random import choice
from string import ascii_letters


def sortirovka():
    while 4 > 0:
        time.sleep(5)
        with open("myFile.txt", "w") as f:
            list1.sort(key=str.lower)
            f.write(str(list1))


def printer():
    open("myFile.txt", "r")
    while 5 > 0:
        print(list1)
        time.sleep(1)

list1 = []
t = threading.Thread(target=sortirovka)
p = threading.Thread(target=printer)
t.start()
p.start()
while 5 > 0:
    list1.append(''.join(choice(ascii_letters) for i in range(10)))
    time.sleep(1)

