import matplotlib.pyplot as plt
import numpy as np

d = {}
with open("UniformGen.txt") as f:
    for line in f:
        if not line.isspace():   
           #print(line)
           (key, val) = line.split()
           d[int(key)] = float(val)


n, bins, patches = plt.hist(d.values(), 100, density=True, facecolor='g', alpha=0.75)

plt.show()





