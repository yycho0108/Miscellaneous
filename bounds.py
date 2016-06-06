import numpy as np

def bounds(ki,kj,r,w,h):
    i_start = max(0, r - ki)
    j_start = max(0, r - kj);
    i_end = min(h, h + r - ki)
    j_end = min(w, w + r - kj)
    return ((i_start,j_start),(i_end,j_end))

print bounds(1,1,1,5,5)
