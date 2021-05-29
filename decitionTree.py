import numpy as np
import math

class DecitionTree(object):

    def classify(attributes):
        input = attributes[0:len(attributes)-1]
        output = attributes[-1]
        DecitionTree.getSplitIndex(input,output)


    def getSplitIndex(input, output):
        grades = []
        for attribute in input:
            aSplit = np.zeros(len(attribute.types))
            bSplit = np.zeros(len(attribute.types))
            for case in range(len(attribute.cases)):
                if output.cases[case] == output.types[0]:
                    aSplit[attribute.getTypeIndex(attribute.cases[case])]+=1
                else:
                    bSplit[attribute.getTypeIndex(attribute.cases[case])]+=1
            totalInfo = 0
            for i in range(len(aSplit)):
                sum = aSplit[i] + bSplit[i]
                try:
                    info = -1*(aSplit[i]/sum)*math.log(aSplit[i]/sum,2) + -1*(bSplit[i]/sum)*math.log(bSplit[i]/sum,2)
                    print(info)
                except:
                    info = 0
                totalInfo += sum/len(attribute.cases) * info
            grades.append(totalInfo)
        print(grades)
