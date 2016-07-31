def move(v,u):
    n = len(v)
    q = [0. for _ in range(n)]
    for i in range(n):
        q[i] += 0.8 * v[(i-u)%n]
        q[(i-1)%n] += 0.1 * v[(i-u)%n]
        q[(i+1)%n] += 0.1 * v[(i-u)%n]
    return q


if __name__ == "__main__":
    dist = [0.2, 0.2, 0.2, 0.2, 0.2]
    step = 2
    print move(dist,step)
