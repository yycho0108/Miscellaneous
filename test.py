from matplotlib import pyplot as pl

with open("result.txt","r") as f:
    s = f.read()
    s = s.split(",")
    del s[-1]

    a = [float(val) for val in s]
    pl.plot(a)
    pl.show()
