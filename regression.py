import numpy as np
import matplotlib.pyplot as plt
from data import SquaredSum

class Regression(object):

    def __init__(self):
        self.a =0

    def simpleLinearRegression(xData, yData):
        productSum = 0
        xDataSum = 0
        yDataSum = 0
        xDataSumSquared = 0
        yDataSumSquared = 0
        for i in range(len(xData)):
            productSum+=xData[i]*yData[i]
            xDataSum+=xData[i]
            yDataSum+=yData[i]
            xDataSumSquared+=xData[i]*xData[i]
            #yDataSumSquared+=yData[i]*yData[i]

        beta = (len(xData)*productSum - xDataSum*yDataSum)/(len(xData)*xDataSumSquared-xDataSumSquared)
        alpha = yData[5] - beta*xData[5]
        return beta, alpha


    def localMinimum(self, yData, xData, initialConstant, initialStepSize, stepSizeMin):
        step = initialStepSize
        constant = initialConstant
        squaredSum = self.getSquaredSum(yData,xData,constant)
        minSquaredSum = SquaredSum(squaredSum, None)
        while step>stepSizeMin:
            curMin = minSquaredSum.squaredSum
            print(curMin)
            for data in xData:
                data.weight += step
                squaredSum1 = self.getSquaredSum(yData,xData,constant)
                data.weight -= 2*step
                squaredSum2 = self.getSquaredSum(yData,xData,constant)
                if (squaredSum1 < squaredSum2):
                    if squaredSum1 < minSquaredSum.squaredSum:
                        print("ok")
                        minSquaredSum.squaredSum = squaredSum1
                        minSquaredSum.data = data
                        minSquaredSum.dir = 1
                else:
                    if squaredSum2 < minSquaredSum.squaredSum:
                        print("ok2")
                        minSquaredSum.squaredSum = squaredSum2
                        minSquaredSum.data = data
                        minSquaredSum.dir = -1
                data.weight = data.bestWeight
            squaredSum1 = self.getSquaredSum(yData,xData,constant+step)
            squaredSum2 = self.getSquaredSum(yData,xData,constant-step)
            if (squaredSum1 < squaredSum2):
                if squaredSum1 < minSquaredSum.squaredSum:
                    print("ok3")
                    minSquaredSum.squaredSum = squaredSum1
                    minSquaredSum.data = -1
                    minSquaredSum.dir = 1
            else:
                if squaredSum2 < minSquaredSum.squaredSum:
                    print("ok4")
                    minSquaredSum.squaredSum = squaredSum2
                    minSquaredSum.data = -1
                    minSquaredSum.dir = -1
            if curMin <= minSquaredSum.squaredSum:
                step = step/2.0
                print("ok5")
                continue
            if minSquaredSum.data!= -1:
                minSquaredSum.data.weight = minSquaredSum.data.weight + minSquaredSum.dir*step
                minSquaredSum.data.bestWeight = minSquaredSum.data.weight
            else:
                constant = constant + minSquaredSum.dir*step
        return xData, constant

    def getSquaredSum(self,yData, xData, constant):
        calculated = np.full(xData[0].size, constant,dtype='float64')
        for data in xData:
            for i in range(data.size):
                calculated[i] += data.getIndex(i)*data.weight

        squaredSum = 0
        for i in range(np.size(calculated)):
            squaredSum += (yData[i]- calculated[i])*(yData[i]- calculated[i])
        return squaredSum
