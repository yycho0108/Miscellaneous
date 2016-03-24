table = [1,2,3] #placeholder

def lerp(x,y,a):
    return (1.0-a)*x + a*y

def sign(x):
    return (-1 if x<0 else 1)

def lookup(windAngle):


def fiddle(sailAngle):
    pass

def getSailAngle(windAngle):
    sailAngle = lookup(wind.angle)
    dSA = fiddle(sailAngle)
    return sailAngle + dSA
