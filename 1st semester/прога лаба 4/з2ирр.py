f = lambda x: x**2 - 2
def F(a, b):
    eps = float(input())
    while abs(b-a)>eps:
        z = (a + b)/2
        if f(a)*f(z)<0:
            b = z
        if f(b)*f(z)<0:
            a = z
    return z
print(F(0, 5))
