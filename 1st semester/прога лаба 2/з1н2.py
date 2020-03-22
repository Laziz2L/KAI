import math

x   = int(input())
go  = False
n   = 0
su  = 0
was = 0
while go == False :
    now = ((x**n)/math.factorial(n))-((x**(n+1))/math.factorial(n+1))
    if now == 0:
       go = True
    su += now
    was = now
    n  += 2

print(su)    
