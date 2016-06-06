import cv2
import numpy as np

image = cv2.imread('images/cam1.png')
image = cv2.resize(image,dsize=(0,0),fx=0.5,fy=0.5)
shifted = cv2.pyrMeanShiftFiltering(image,9,21) # -- 9,21 arbitrary
#edge = cv2.edgePreservingFilter(image)
gray = cv2.cvtColor(shifted,cv2.COLOR_BGR2GRAY)
edge_2 = cv2.adaptiveThreshold(gray,255,cv2.ADAPTIVE_THRESH_GAUSSIAN_C,cv2.THRESH_BINARY,13,2)

cv2.imshow("image", image)
cv2.imshow("edge", edge_2)
cv2.imshow("gray", gray)

cv2.waitKey()
