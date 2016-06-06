import numpy as np
from matplotlib import pyplot as plt

t = np.linspace(0,0.01,1000)
w0 = 432*2*np.pi

sig = np.cos(w0*t)*np.cos(w0*t)
plt.plot(t,sig)
plt.plot(t,np.cos(w0*t))
plt.show()
