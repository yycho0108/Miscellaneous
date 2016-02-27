import numpy as np
from matplotlib import pyplot as plt

PI = np.pi

def sample():
    t,dt = np.linspace(0,20,num=1000,endpoint=False,retstep=True) #from t(time) =0 to 2*PI
    w = 10 # 10 rads per sec
    v = np.sin(w*t)
    return t,dt,v
def DFT():
    t_raw,dt,v_raw = sample()
    N = 100 #sample size
    for i in range(8):
        v = v_raw[i*N:(i+1)*N] #sample v
        t = t_raw[i*N:(i+1)*N] #sample t
        T = t[-1] - t[0] #time frame

        c = []
        w = []

        for n in range(N):
            res = 0
            w_h = 2*PI*n/T #harmonic frequency
            for t_i,v_i in zip(t,v):
                res += v_i * np.exp(-1j*w_h*t_i) * dt
            res /= T
            c.append(res)
            w.append(w_h)
        plt.plot(w,c)
        
        test = np.fft.fft(v)
        plt.plot(test)
        plt.show()
        

def main():
    DFT() 
if __name__ == "__main__":
    main()
