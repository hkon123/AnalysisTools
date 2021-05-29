import numpy as np

class Data(object):

    def __init__(self, array, weight, initialStepSize):
        self.array = np.array(array)
        self.weight = weight
        self.bestWeight = weight
        self.size = np.size(self.array)
        #self.calculated = np.array()
        self.step = initialStepSize

    def getIndex(self, index):
        return self.array[index]

    def initCalculated(self):
        self.calculated = np.array()

class SquaredSum(object):

    def __init__(self, squaredSum, data):
        self.squaredSum = squaredSum
        self.data = data
        self.dir = 0
