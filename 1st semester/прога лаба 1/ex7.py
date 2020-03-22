Num = int(input())
Dig_1 = Num // 100
Digs_23 = Num % 100
Num_changed = Digs_23 * 10 + Dig_1
print(Num_changed)
