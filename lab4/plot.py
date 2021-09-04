import matplotlib.pyplot as plt
import math

x=[]
y=[]
with open('BST.csv') as f:
    content = f.readlines()
    lines = [x.strip() for x in content]
    for i in lines:
        line = [w for w in i.split(',')]
        x.append(float(line[0]))
        y.append(float(line[1]))


nlogn = [1.25e-7 * i * math.log(i) for i in x]
plt.plot(x,y,label='Time-Complexity of BST Insert')
plt.plot(x,nlogn,label='k*(nlog(n))     (Where k is a constant)')

plt.xlabel('Number Of Elements Inserted')
plt.ylabel('Average Runtime (in sec)')
plt.legend()
plt.show()