Num = int(input())
Dig_1 = Num // 100
Dig_2 = (Num % 100) // 10
Dig_3 = Num % 10
Reverse = Dig_3*100 + Dig_2*10 + Dig_1
print(Reverse)
