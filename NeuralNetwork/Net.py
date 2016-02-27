import numpy as np
from matplotlib import pyplot as plt


def sigmoid(x):
    return 1.0/(1.0 + np.exp(-x))
def sigmoidPrime(x):
    s = sigmoid(x)
    return s * (1.0 - s)

class Layer:
    def __init__(self,l):
        pass


class Net:
    def __init__(self,t):
        self.length = len(t)
        self.L = []
        self.W = [] 
        for l in t:
            self.L.append(Layer(l))
        for i in range(1, self.length):
            self.W.append(np.random.randn(t[i-1],t[i]))
    def FF(self,X):
        self.L[0].O = X
        print(X)
        for i in range(1,self.length):
            self.L[i].I = np.dot(self.L[i-1].O,self.W[i-1])
            self.L[i].O = sigmoid(self.L[i].I)
        return self.L[-1].O
    def BP(self,X,Y):
        #currently writing here, incomplete.
        self.L[-1].G = (self.FF(X)-Y) * sigmoidPrime(self.L[i-1].O)
        for i in range(self.length-1, 1):
            L[i].G = L[i+1].G * sigmoidPrime(self.L[i].I)
        for i in range(1, self.length):
            dW = np.dot(L[i].G, self.L[i]
        pass

def main():
    t = [2,4,1]
    net = Net(t)
    print net.FF(np.atleast_2d([0,0]))
if __name__ == "__main__":
    main()
