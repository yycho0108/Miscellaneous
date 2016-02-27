from operator import itemgetter

import math
def eucD(p1,p2):
    return math.sqrt((p1[0]-p2[0])**2 + (p1[1]-p2[1])**2)
def taxD(p1,p2):
    return abs(p1[0]-p2[0]) + abs(p1[1]-p2[1])

class KNN:
    def __init__(self,k):
        self.k=k
        self.dat = []
    def train(self,X,Y):
        self.dat.append((X,Y))
        self.dat.sort(key=itemgetter(1))
    def predict(self,I,metric="E"):
        print(self.dat)
        cand = []
        if metric == "E":
            cand = [(eucD(X,I),Y) for X,Y in self.dat]
        else:
            cand = [(taxD(X,I),Y) for X,Y in self.dat]
        cand.sort(key=itemgetter(0))
        print(cand)
        lab = [c[1] for c in cand[:self.k]]
        print(lab)
        return sum(lab)/float(self.k)
def main():
    X = [(1,6),(2,4),(3,7),(6,8),(7,1),(8,4)]
    Y = [7,8,16,44,50,68]
    knn = KNN(3)#
    for x,y in zip(X,Y):
        knn.train(x,y)

    print(knn.predict((4,2),"T"))
if __name__ == "__main__":
    main()
