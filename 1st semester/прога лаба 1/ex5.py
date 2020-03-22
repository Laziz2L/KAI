Num = int(input())
Sum = (Num // 100) + ((Num % 100) // 10) + (Num % 10)
Proizv = (Num // 100) * ((Num % 100) // 10) * (Num % 10)
print(Sum, Proizv)
