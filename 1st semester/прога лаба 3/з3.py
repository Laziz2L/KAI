import random
n = int(input())
A = []
for i in range(n) :
    x = random.randint(-9, 9)
    A.append(x)
print('заданный список : ', A)

s = 0                                  #номер символа
c = 0                                  #кол-во чисел в каждой группе(больше на 1)
k = 0                                  #кол-во чисел в наибольшей группе(больше на 1)
for i in A :
    s += 1
    c += 1
    if i < 0 :
        if c > 2 :
            k = c
            num = s                    #номер последнего символа наибольшей группы(больше на 2)
        c = 0   

if k != 0 :
    del A[num-k:num-1]
    print('полученный список : ', A)
else :
        print('ни одной группы положительных чисел не найдено')
