import matplotlib.pyplot as plt
import numpy as np
from minimiser import Minimiser
from parseFile import ParseFile as pf
from regression import Regression as reg
from data import Data










x,y = pf.parseFilefromKeywords("data/possum.dat", "total_l", "head_l")
#z = pf.parseFileFromOneKeyword("county.dat", "pop2017")

xData = [Data(x,1,1)]#, Data(z, 1,1000)]

A = reg()
m, c = A.localMinimum(y, xData, 40, 5,0.0001 )

'''
for i in range(len(x)):
    if i == 0:
        datapoints = np.array([x[i],y[i],1])
    else:
        datapoints = np.vstack((datapoints, np.array([x[i],y[i],1])))

A = Minimiser(0.0001,5, datapoints)
a,b,beta,alpha = A.minimize(1,40)

print(a)
print(b)
print(beta)
print(alpha)
'''
linex= np.linspace(75,100,100)
liney= m[0].weight*linex + c

#beta, alpha = reg.simpleLinearRegression(x,y)
#linex2= np.linspace(75,100,100)
#liney2= beta*linex2 + alpha


print(m[0].weight)
print(c)

#plt.plot(linex2,liney2)
plt.plot(linex,liney)



plt.scatter(x,y)

plt.show()
