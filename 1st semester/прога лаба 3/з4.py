n = int(input())

if n > 7 :
    A = []
    p = 1
    while p < n :
        A.append(p)
        p += 1
    A.append(p)
    Div7 = [] 
    for i in A :
        if i % 7 == 0 :
            Div7.append(i)
    print('все числа от 1 до ', n, ', кратные 7 : ', Div7)
else :
    print('чисел от 1 до', n, ', кратных 7, нет')
    
A = [0] * n 
for i in range(n): 
    A[i] = i 
A[1] = 0
p = 2 
while p < n: 
    if A[p] != 0: 
        k = p * 2 
        while k < n:
            A[k] = 0 
            k = k + p 
    p += 1
B = []
for i in A:
    if A[i] != 0:
        B.append(A[i])
del A
print ('все простые числа от 1 до ',n , ':', B)


if n > 7 :
    print ('все простые числа от 1 до ', n, ',кратные 7 : 7')
else :
        print('простых чисел от 1 до', n, ', кратных 7, нет')
