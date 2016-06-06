import numpy as np
W = 1
H = 84
N = 10

a = [ [i*j for j in range(N)] for i in range(H)]

b = [ [i-j for j in range(W)] for i in range(N)]

a = np.asarray(a)
b = np.asarray(b)

print np.dot(a,b)

print H*N + W*N
