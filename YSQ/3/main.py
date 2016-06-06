import numpy as np

def dist(a,b):
    return [2*ea + np.floor(eb/11.)-1 for ea in a for eb in b]

dice = range(1,21)
dice = np.asarray(dice)

res = dist(dice,dice)
print res
print np.bincount(res)
