stroka = input('Введите 6 целых десятичных чисел через запятую')
stroka = list(stroka.split(', '))

print('4-й элемент : ', stroka[3])
print('элементы в обратном порядке : ', stroka[::-1])
i = 0
s = 0
while i < 6:
    x = int(stroka[i])
    i += 1
    s += x
print('сумма : ', s)
print('среднее арифметическое : ', s/len(stroka))
