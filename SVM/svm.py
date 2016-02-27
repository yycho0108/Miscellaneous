import numpy as np
from prep_terrain_data import makeTerrainData
from matplotlib import pyplot as plt
from sklearn import svm
import pandas
from class_vis import prettyPicture


x_train,y_train,x_test,y_test = makeTerrainData()


df = pandas.DataFrame(data=x_test,columns=['f_1','f_2'])
df['label'] = pandas.Series(y_test)

dat_pos = df[df.label==1]
dat_neg = df[df.label==0]

plt.scatter(dat_pos['f_1'],dat_pos['f_2'],c='blue')
plt.scatter(dat_neg['f_1'],dat_neg['f_2'],c='red')
#plt.show()

clf = svm.SVC(kernel='rbf',C=0.01)
clf.fit(x_train,y_train)

prettyPicture(clf,x_test,y_test)

#w = clf.coef_[0]
#a = -w[0]/w[1]
#m = clf.intercept_[0] / w[1]
#x_ = np.linspace(0.0,1.0)
#y_ = a*x_ - m

#plt.plot(x_,y_)
plt.show()

#feature_1 = [x[0] for x in x_train]
#feature_2 = [x[1] for x in x_train]

#pos = [i for i,x in enumerate(y_train) if x == 1]
#neg = [i for i,x in enumerate(y_train) if x != 1]

#f1_pos = [feature_1[i] for i in pos]
#f2_pos = [feature_2[i] for i in pos]
#f1_neg = [feature_1[i] for i in neg]
#f2_neg = [feature_2[i] for i in neg]

#plt.scatter(f1_pos,f2_pos,c='red')
#plt.scatter(f1_neg,f2_neg,c='blue')

#plt.show()

