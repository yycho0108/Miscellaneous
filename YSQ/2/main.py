from matplotlib import pyplot as plt
import numpy as np

def next(s,pos,neg): #s=sum
    if pos<0 or neg<0 or s<0:
        return 0. #IMPOSSIBLE
    elif pos==0 and neg==0: #END
        return 1.
    else:
        return next(s+1,pos-1,neg) + \
               next(s-1,pos,neg-1)

def factorial(x):
    if x <= 1:
        return 1.
    else:
        return x * factorial(x-1)

if __name__ == "__main__":
    ys = []
    xs = range(1,15)

    for x in xs:
        print x
        ys += [next(0,x,x) / (factorial(2*x) / (factorial(x)**2))]
    
    f,axs = plt.subplots(2,sharex=True)
    axs[0].plot(xs,ys)

    xs = np.asarray(xs)
    ys = 1. / (xs+1.)
    axs[1].plot(xs,ys)
    plt.show()
