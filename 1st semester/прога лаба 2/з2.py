stroka = list(input())
dlina = int(len(stroka))

print('А)', stroka[0:4:1])
print('Б)', stroka[dlina-4:dlina:1])
x = float(dlina/2)
if dlina%2 != 0:
    x = x + 0.5 
    print ('В)',stroka[round(x-1)])
else:
     print('В) Количество символов чётное, поэтому в середине 2 символа :', stroka[round(x-1)], stroka[round(x)])
print ('Г)', stroka[2:8:1])
