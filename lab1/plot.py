import matplotlib.pyplot as plt

linear_x=[]
linear_y=[]
with open('linear.txt') as f:
    content = f.readlines()
    lines = [x.strip() for x in content]
    for i in lines:
        line = [w for w in i.split()]
        linear_x.append(float(line[0]))
        linear_y.append(float(line[1]))

expo_x=[]
expo_y=[]
with open('exponential.txt') as f:
    content = f.readlines()
    lines = [x.strip() for x in content]
    for i in lines:
        line = [w for w in i.split()]
        expo_x.append(float(line[0]))
        expo_y.append(float(line[1]))


plt.plot(linear_x,linear_y,label = 'linear')
# plt.hold(True)
plt.plot(expo_x,expo_y, label= 'exponential')

plt.xlabel('Number Of Elements Inserted')
plt.ylabel('Average Runtime')
plt.legend()
plt.show()
plt.savefig('plot.png')