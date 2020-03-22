import math

x   = int(input())
go  = False
n   = 0
su  = 0
was = 0
while go == False :
    now = ((x**(2*n))/math.factorial(2*n))-((x**(2*(n+1)))/math.factorial(2*(n+1)))
    if now == 0:
       go = True
    su += now
    was = now
    n  += 2

print(su)    
