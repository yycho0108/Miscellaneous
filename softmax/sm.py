import numpy as np

def sigmoid(x):
    return 1.0 / (1.0 + np.exp(-x));
def softmax(x):
    m = np.max(x)
    ex = np.exp(x)
    return ex/np.sum(ex)

I = [
    0.352815 ,
    0.797425 ,
    0.671223 ,
    0.320503 ,
    0.393341 ,
    0.364678 ,
    0.463536 ,
    0.529704 ,
    0.41544  ,
    0.730509 
]
I = [
        0.9,
        0.1,
        0.1,
        0.1
        ]

I = np.asarray(I);
I = softmax(I);
print I
