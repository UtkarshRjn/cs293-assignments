import matplotlib.pyplot as plt
import numpy as np

swap_insert=[]
swap_deleteMin=[]
with open('swap.csv') as f:
    content = f.readlines()
    lines = [x.strip() for x in content]
    for i in lines:
        line = [w for w in i.split(',')]
        swap_insert.append(float(line[0]))
        swap_deleteMin.append(float(line[1]))

time_insert=[]
time_deleteMin=[]
with open('time.csv') as f:
    content = f.readlines()
    lines = [x.strip() for x in content]
    for i in lines:
        line = [w for w in i.split(',')]
        time_insert.append(float(line[0]))
        time_deleteMin.append(float(line[1]))

X = ['1e3','1e4','1e5','1e6']
X_axis = np.arange(len(X))
plt.bar(X_axis-0.2,swap_insert,width=0.4,label = 'Insert')
plt.bar(X_axis+0.2,swap_deleteMin,width=0.4,label = 'Delete-Min')


plt.xticks(X_axis, X)

plt.xlabel('N')
plt.ylabel('Average Number of Swaps')
plt.title("Comparision of Swaps for delete-min \n in a MinHeap")
plt.legend()
# plt.show()
plt.savefig('swap.png')
plt.close()

plt.bar(X_axis-0.2,time_insert,width=0.4,label = 'Insert')
plt.bar(X_axis+0.2,time_deleteMin,width=0.4,label = 'Delete-Min')

plt.xticks(X_axis, X)

plt.xlabel('N')
plt.ylabel('Average Time Taken (in sec)')
plt.title("Comparision of Average-Runtime \n in a MinHeap")
plt.legend()
# plt.show()
plt.savefig('time.png')
plt.close()
