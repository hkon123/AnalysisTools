import matplotlib.pyplot as plt
import numpy as np
from minimiser import Minimiser
from parseFile import ParseFile as pf
from regression import Regression as reg
from data import Data
from decitionTree import DecitionTree as dt


#dt.classify(pf.parseArffFile("data/weather.nominal.arff"))


data = pf.parseArffFile("data/labor.arff")

#data = pf.replaceMissingValues(data, "?")

#data = pf.replaceValueInAttribute(data, "gender", "mf", "?")
#data = pf.replaceValueInAttribute(data, "gender", "x", "?")



#pf.printArffFile(data)

#print(pf.getMeanFromAttribute(data,"wage-increase-first-year"))



f = open("test2.arff", "w")

pf.arrfAttributesToFile(f, data, "test")

f.close()
