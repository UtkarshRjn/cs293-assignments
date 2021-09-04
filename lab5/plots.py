import matplotlib.pyplot as plt

# ------------------------Runtime-Plot--------------------------#

runtime_random_x=[]
runtime_random_QSP1=[]
runtime_random_QSPR=[]
runtime_random_BuSo=[]
with open('runtime_random.txt') as f:
    content = f.readlines()
    lines = [x.strip() for x in content]
    for i in lines:
        line = [w for w in i.split()]
        runtime_random_x.append(float(line[0]))
        runtime_random_QSP1.append(float(line[1]))
        runtime_random_QSPR.append(float(line[2]))
        runtime_random_BuSo.append(float(line[3]))

plt.plot(runtime_random_x,runtime_random_QSP1,label = 'QuickSort-1st-Pivot(Random)',color='green',linestyle='--')
plt.plot(runtime_random_x,runtime_random_QSPR,label = 'QuickSort-Random-Pivot(Random)',color='green',linestyle='-.')
plt.plot(runtime_random_x,runtime_random_BuSo,label = 'Bubble-Sort(Random)',color='green',linestyle='-')

runtime_almost_sorted_x=[]
runtime_almost_sorted_QSP1=[]
runtime_almost_sorted_QSPR=[]
runtime_almost_sorted_BuSo=[]
with open('runtime_almost_sorted.txt') as f:
    content = f.readlines()
    lines = [x.strip() for x in content]
    for i in lines:
        line = [w for w in i.split()]
        runtime_almost_sorted_x.append(float(line[0]))
        runtime_almost_sorted_QSP1.append(float(line[1]))
        runtime_almost_sorted_QSPR.append(float(line[2]))
        runtime_almost_sorted_BuSo.append(float(line[3]))

plt.plot(runtime_almost_sorted_x,runtime_almost_sorted_QSP1,label = 'QuickSort-1st-Pivot(Almost-Sorted)',color='red',linestyle='--')
plt.plot(runtime_almost_sorted_x,runtime_almost_sorted_QSPR,label = 'QuickSort-Random-Pivot(Almost-Sorted)',color='red',linestyle='-.')
plt.plot(runtime_almost_sorted_x,runtime_almost_sorted_BuSo,label = 'Bubble-Sort(Almost-Sorted)',color='red',linestyle='-')

runtime_rev_almost_sorted_x=[]
runtime_rev_almost_sorted_QSP1=[]
runtime_rev_almost_sorted_QSPR=[]
runtime_rev_almost_sorted_BuSo=[]
with open('runtime_rev_almost_sorted.txt') as f:
    content = f.readlines()
    lines = [x.strip() for x in content]
    for i in lines:
        line = [w for w in i.split()]
        runtime_rev_almost_sorted_x.append(float(line[0]))
        runtime_rev_almost_sorted_QSP1.append(float(line[1]))
        runtime_rev_almost_sorted_QSPR.append(float(line[2]))
        runtime_rev_almost_sorted_BuSo.append(float(line[3]))

plt.plot(runtime_rev_almost_sorted_x,runtime_rev_almost_sorted_QSP1,label = 'QuickSort-1st-Pivot(Reverse-Almost-sorted)',color='blue',linestyle='--')
plt.plot(runtime_rev_almost_sorted_x,runtime_rev_almost_sorted_QSPR,label = 'QuickSort-Random-Pivot(Reverse-Almost-sorted)',color='blue',linestyle='-.')
plt.plot(runtime_rev_almost_sorted_x,runtime_rev_almost_sorted_BuSo,label = 'Bubble-Sort(Reverse-Almost-sorted)',color='blue',linestyle='-')

plt.title('Plot of Runtime for 3 different sorting algorithms')

plt.xlabel('Number Of Elements in the array')
plt.ylabel('Runtime (in secs)')
plt.legend(loc='upper left', frameon=False)
plt.savefig('Runtime.png', bbox_inches='tight')
# plt.show()
plt.close()

# ------------------------Runtime-Plot--------------------------#


#-------------------------An almost sorted array-----------------#

fig = plt.figure()
fig.suptitle('Plot of an Almost Sorted Array')

comparisions_almost_sorted_x=[]
comparisions_almost_sorted_QSP1=[]
comparisions_almost_sorted_QSPR=[]
comparisions_almost_sorted_BuSo=[]
with open('comparisions_almost_sorted.txt') as f:
    content = f.readlines()
    lines = [x.strip() for x in content]
    for i in lines:
        line = [w for w in i.split()]
        comparisions_almost_sorted_x.append(float(line[0]))
        comparisions_almost_sorted_QSP1.append(float(line[1]))
        comparisions_almost_sorted_QSPR.append(float(line[2]))
        comparisions_almost_sorted_BuSo.append(float(line[3]))

fig.add_subplot(1,2,1)
plt.plot(comparisions_almost_sorted_x,comparisions_almost_sorted_QSP1,label = 'QuickSort-1st-Pivot')
plt.plot(comparisions_almost_sorted_x,comparisions_almost_sorted_QSPR,label = 'QuickSort-Random-Pivot')
plt.plot(comparisions_almost_sorted_x,comparisions_almost_sorted_BuSo,label = 'Bubble-Sort')
plt.title('Comparisions',fontsize=10)

plt.xlabel('Number Of Elements in the array')
plt.ylabel('No. of Comparisions')
plt.legend()

swaps_almost_sorted_x=[]
swaps_almost_sorted_QSP1=[]
swaps_almost_sorted_QSPR=[]
swaps_almost_sorted_BuSo=[]
with open('swaps_almost_sorted.txt') as f:
    content = f.readlines()
    lines = [x.strip() for x in content]
    for i in lines:
        line = [w for w in i.split()]
        swaps_almost_sorted_x.append(float(line[0]))
        swaps_almost_sorted_QSP1.append(float(line[1]))
        swaps_almost_sorted_QSPR.append(float(line[2]))
        swaps_almost_sorted_BuSo.append(float(line[3]))

fig.add_subplot(1,2,2)
plt.plot(swaps_almost_sorted_x,swaps_almost_sorted_QSP1,label = 'QuickSort-1st-Pivot')
plt.plot(swaps_almost_sorted_x,swaps_almost_sorted_QSPR,label = 'QuickSort-Random-Pivot')
plt.plot(swaps_almost_sorted_x,swaps_almost_sorted_BuSo,label = 'Bubble-Sort')

plt.xlabel('Number Of Elements in the array')
plt.ylabel('No. of Swaps')
plt.title('Swaps',fontsize=10)
plt.legend()

plt.tight_layout()
plt.savefig('Comparisions_Swaps_Almost_Sorted.png', bbox_inches='tight')
# plt.show()
plt.close()

#-------------------------An almost sorted array-----------------#


#-------------------------Reverse of An almost sorted array-----------------#

fig = plt.figure()
fig.suptitle('Plot of Reverse of an Almost Sorted Array')

comparisions_rev_almost_sorted_x=[]
comparisions_rev_almost_sorted_QSP1=[]
comparisions_rev_almost_sorted_QSPR=[]
comparisions_rev_almost_sorted_BuSo=[]
with open('comparisions_rev_almost_sorted.txt') as f:
    content = f.readlines()
    lines = [x.strip() for x in content]
    for i in lines:
        line = [w for w in i.split()]
        comparisions_rev_almost_sorted_x.append(float(line[0]))
        comparisions_rev_almost_sorted_QSP1.append(float(line[1]))
        comparisions_rev_almost_sorted_QSPR.append(float(line[2]))
        comparisions_rev_almost_sorted_BuSo.append(float(line[3]))

fig.add_subplot(2,2,1)
plt.plot(comparisions_rev_almost_sorted_x,comparisions_rev_almost_sorted_QSP1,label = 'QuickSort-1st-Pivot')
plt.plot(comparisions_rev_almost_sorted_x,comparisions_rev_almost_sorted_QSPR,label = 'QuickSort-Random-Pivot')
plt.xlabel('Number Of Elements in the array')
plt.ylabel('No. of Comparisions')
plt.title('Comparisions',fontsize=10)
plt.legend()

fig.add_subplot(2,2,2)
plt.plot(comparisions_rev_almost_sorted_x,comparisions_rev_almost_sorted_BuSo,label = 'Bubble-Sort')
plt.xlabel('Number Of Elements in the array')
plt.ylabel('No. of Comparisions')
plt.title('Comparisions',fontsize=10)
plt.legend()

swaps_random_x=[]
swaps_random_QSP1=[]
swaps_random_QSPR=[]
swaps_random_BuSo=[]
with open('swaps_random.txt') as f:
    content = f.readlines()
    lines = [x.strip() for x in content]
    for i in lines:
        line = [w for w in i.split()]
        swaps_random_x.append(float(line[0]))
        swaps_random_QSP1.append(float(line[1]))
        swaps_random_QSPR.append(float(line[2]))
        swaps_random_BuSo.append(float(line[3]))

fig.add_subplot(2,2,3)
plt.plot(swaps_random_x,swaps_random_QSP1,label = 'QuickSort-1st-Pivot')
plt.plot(swaps_random_x,swaps_random_QSPR,label = 'QuickSort-Random-Pivot')
plt.xlabel('Number Of Elements in the array')
plt.ylabel('No. of Swaps')
plt.title('Comparisions',fontsize=10)
plt.legend()

fig.add_subplot(2,2,4)
plt.plot(swaps_random_x,swaps_random_BuSo,label = 'Bubble-Sort')
plt.xlabel('Number Of Elements in the array')
plt.ylabel('No. of Swaps')
plt.title('Swaps',fontsize=10)
plt.legend()

plt.savefig('Comparisions_Swaps_Rev_Almost_Sorted.png', bbox_inches='tight')
# plt.show()
plt.close()

#-------------------------Reverse of An almost sorted array-----------------#


#---------------------------------Random array-------------------------------#

fig = plt.figure()
fig.suptitle('Plot of a Random Array')

comparisions_random_x=[]
comparisions_random_QSP1=[]
comparisions_random_QSPR=[]
comparisions_random_BuSo=[]
with open('comparisions_random.txt') as f:
    content = f.readlines()
    lines = [x.strip() for x in content]
    for i in lines:
        line = [w for w in i.split()]
        comparisions_random_x.append(float(line[0]))
        comparisions_random_QSP1.append(float(line[1]))
        comparisions_random_QSPR.append(float(line[2]))
        comparisions_random_BuSo.append(float(line[3]))

fig.add_subplot(2,2,1)
plt.plot(comparisions_random_x,comparisions_random_QSP1,label = 'QuickSort-1st-Pivot')
plt.plot(comparisions_random_x,comparisions_random_QSPR,label = 'QuickSort-Random-Pivot')
plt.xlabel('Number Of Elements in the array')
plt.ylabel('No. of Comparisions')
plt.title('Comparisions',fontsize=10)
plt.legend()

fig.add_subplot(2,2,2)
plt.plot(comparisions_random_x,comparisions_random_BuSo,label = 'Bubble-Sort')
plt.xlabel('Number Of Elements in the array')
plt.ylabel('No. of Comparisions')
plt.title('Comparisions',fontsize=10)
plt.legend()

swaps_random_x=[]
swaps_random_QSP1=[]
swaps_random_QSPR=[]
swaps_random_BuSo=[]
with open('swaps_random.txt') as f:
    content = f.readlines()
    lines = [x.strip() for x in content]
    for i in lines:
        line = [w for w in i.split()]
        swaps_random_x.append(float(line[0]))
        swaps_random_QSP1.append(float(line[1]))
        swaps_random_QSPR.append(float(line[2]))
        swaps_random_BuSo.append(float(line[3]))

fig.add_subplot(2,2,3)
plt.plot(swaps_random_x,swaps_random_QSP1,label = 'QuickSort-1st-Pivot')
plt.plot(swaps_random_x,swaps_random_QSPR,label = 'QuickSort-Random-Pivot')
plt.xlabel('Number Of Elements in the array')
plt.ylabel('No. of Swaps')
plt.title('Swaps',fontsize=10)
plt.legend()

fig.add_subplot(2,2,4)
plt.plot(swaps_random_x,swaps_random_BuSo,label = 'Bubble-Sort')
plt.xlabel('Number Of Elements in the array')
plt.ylabel('No. of Swaps')
plt.title('Swaps',fontsize=10)
plt.legend()

plt.tight_layout()
plt.savefig('Comparisions_Swaps_Random.png', bbox_inches='tight')
# plt.show()
plt.close()

#-------------------------Random array-----------------------------------#