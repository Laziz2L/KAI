import random
n = int(input())
A = []
for i in range(n) :
    x = random.randint(-9, 9)
    A.append(x)
print('заданный список : ', A)

A.reverse()
s = 0                                  #номер символа, идущего после группы
c = 0                                  #кол-во чисел в группе
for i in A :
    s += 1
    if i > 0 :
        c += 1
    if i <= 0 :
        if c >= 2 :
            break
        c = 0
s -= 1
if c >= 2 :
    del A[s-c:s]
A.reverse()
print('скорректированный список : ', A)
