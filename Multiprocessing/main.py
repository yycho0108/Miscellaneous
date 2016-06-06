from multiprocessing import Pool
from sklearn.grid_search import ParameterGrid
def f(x):
    return x*x

def run(params):
    return params, params['a'] * params['b'] * params['c']

if __name__ == '__main__':
    valid_params = {'a':(1,2,3),'b':(4,5,6),'c':(7,8,9)}
    grid = ParameterGrid(valid_params)
    p = Pool(5)

    maxParam = None
    maxScore = 0.0
    for p,s in p.map(run,grid):
        if s > maxScore:
            maxScore = s
            maxParam = p
    print maxParam

