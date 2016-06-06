import numpy as np
from matplotlib import pyplot as plt
from numpy import sqrt, exp

class X:
    def __init__(self,x0):
        i = 1j
        self.l1 = (-1+i*sqrt(7))/2
        self.l2 = (-1-i*sqrt(7))/2
        self.P = np.asarray([[1,1],[self.l1,self.l2]])
        self.Pt = np.asarray([[self.l2,-1],[-self.l1,1]])/(self.l2-self.l1)
        self.x0 = x0
    def __getitem__(self,t):
        el = np.diag([exp(self.l1*t),exp(self.l2*t)])
        return np.dot(self.P,np.dot(el,np.dot(self.Pt,self.x0)))



if __name__ == "__main__":
    for i in range(100):
        x_init = np.random.randn(2,1)
        x = X(x_init)
        xt = []
        ts = np.linspace(0,100,1000)
        for t in ts:
            xt += [x[t]]

        x0,x1 = zip(*xt)
        plt.plot(x_init[0],x_init[1],'o')
        plt.plot(x0,x1)
        #plt.show()
    plt.show()
