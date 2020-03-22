f = lambda x: x**2 - 2
eps = float(input())
def F(a, b) :
    while abs(b-a)>eps:
        z = (a + b)/2
        if f(a)*f(z)<0:
            b = z
        if f(b)*f(z)<0:
            a = z
        F(a,b)
    return(a)
print(F(0, 5))
