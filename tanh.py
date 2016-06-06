from matplotlib import pyplot as plt
import numpy as np


x = np.linspace(0,2)
y = np.tanh(x)
plt.plot(x,y)
plt.show()
