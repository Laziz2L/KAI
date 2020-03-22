S = list(input())

lenght = len(S)
print('а) ', lenght)

if S[0] != '.' :
    w = 1
for i in S :
    if i == ' ' :
        w += 1
print('б) ', w)        

wds = [0]
wds *= w+1
wlen = 0
p = 0
k = 1
for p in S :
    if p != ' ' :
        wds[k] += 1
    else  :
        k += 1
wds[-1] -= 1
del wds[0]
short = 99999999
long = 0
for i in wds :
    if i > long :
        long = i
    if i < short :
        short = i
print('в) длина самого короткого слова - ', short,', самого длинного - ', long)

n=0
for p in S :
    S[n]*=2
    n+=1
S1 = str(S)
S1 = S1.replace('*',' ')
print(S1)    
    



        
    
