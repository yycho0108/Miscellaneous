from matplotlib import pyplot as plt
import numpy as np

test = [10**i for i in range(10)]

err = []
for g in test:
    orig = g
    for _ in range(1000000):
        g += 0.000001
    g -= orig
    err += [1 - g]

plt.plot(err)
plt.show()
