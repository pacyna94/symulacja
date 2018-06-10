import matplotlib.pyplot as plt
import numpy as np

d1 = []
d2 = []
with open("wyniki//bloodLevel.txt") as f:
    for line in f:
        if not line.isspace():   
           #print(line)
           x,y = line.split(" ")
	   d1.append(x)
       d2.append(y)
	   #[int(key)] = float(val)

#n, bins, patches = plt.hist(d.values(), 100, density=True, facecolor='g', alpha=0.75)
plt.bar(d1, d2)
plt.show()



