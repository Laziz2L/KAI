x   = int(input())
go  = False
n   = 0
su  = 0
was = 0
while go == False :
    now = 1/((2*n+1)* pow(x, 2*n+1))
    if now == 0 :
       go = True
    su += now
    was = now
    n  += 1

print(su*2)    
