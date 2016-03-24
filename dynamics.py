import numpy as np
from matplotlib import pyplot as plt

def L(t):
    return np.asarray([[np.exp(-t),0],[0,np.exp(t)]])

V = np.asarray([[-1,np.sqrt(3)],[np.sqrt(3),1]])
C = np.random.randn(2,1)
ts = np.arange(100)
x = [None for _ in range(100)]

for t in ts:
    x[t] = np.dot(np.dot(V,L(t)),C)

x1 = [e[0] for e in x]
x2 = [e[1] for e in x]

print(x1)
print(len(ts))

f, (ax1,ax2,ax3) = plt.subplots(1,3)
#ax1.set_yscale('log')
ax1.plot(ts,x1)
#ax2.set_yscale('log')
ax2.plot(ts,x2)
ax3.plot(x1,x2)
#plt.plot(ts,x1)
#plt.title("X1")
plt.show()

#plt.plot(ts,x2)
#plt.title("X2")
plt.show()
