import random

N = 4 

def f(x): #what to do with box number
    return x

def test(box):
    for i in range(N): # prisoner number
        pos = i
        for _ in range(N/2): # number of attempts
            if i == box[pos]:
                break
            else:
                pos = f(box[pos])
        else:
            #couldn't get to number
            return False 
    return True


def try_once():
    box = range(N)
    random.shuffle(box) #create random configuration
    print [x+1 for x in box]

    for i in range(N):
        for j in range(N/2):
            box[i],box[j] = box[j],box[i] #swap
            if test(box) is True:
                print 'i:{},j:{}'.format(i,j)
                return True
            box[i],box[j] = box[j],box[i]

    return False

def main():
    for _ in range(100):
        if not try_once():
            print 'FAIL'
            return
    print 'SUCCESS'

if __name__ == "__main__":
    main()
