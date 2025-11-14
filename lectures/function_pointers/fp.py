def square(x):
    return x**2

def double(x):
    return 2*x

def integrate(fn, lb, ub, N):
    delta = (ub - lb) / N
    sum = 0
    for i in range(N):
        sum += delta * fn(lb + delta*(i+0.5))
    return sum


print(f"Integrating square in range 10-20...{integrate(square, 10.0, 20.0, 10000):.2f}")
print(f"Integrating double in range 10-20...{integrate(double, 10.0, 20.0, 10000):.2f}")


import matplotlib.pylab as plt

def plot_fn(f, lb=-10, ub=10, dx=0.01):
    Xs = []
    Ys = []
    for i in range(0, int((ub-lb)/dx)):
        x = lb + dx*i
        Xs.append( x )
        Ys.append( f(x) )
        
    plt.plot(Xs,Ys)
    plt.show()


import math
plot_fn(square)
plot_fn(math.sin)

