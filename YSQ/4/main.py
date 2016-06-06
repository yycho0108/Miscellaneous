import numpy as np
from matplotlib import pyplot as plt

def step(n,k):
    return n+1000, k + 1000*k/n + 100

n = 1000.
k = 0.

rat = []
for i in range(100000):
    n, k = step(n,k)
    rat += [k/n]

plt.plot(rat)
plt.show()
