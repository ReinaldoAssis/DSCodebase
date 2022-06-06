from turtle import color
import matplotlib.pyplot as plt
import io

from numpy import number

file = open("LinkedQmarking_4.txt",'r');
lines = file.readlines()

filetwo = open("HeapQmarking_4.txt",'r');
linestwo = filetwo.readlines()

x = []
y = []

for rawline in lines:
    lineargs = rawline.strip().split(' ')
    n = float(lineargs[0]);
    factual = float(lineargs[1])
    
    x.append(n)
    y.append(factual)

xh = []
yh = []

for rawline in linestwo:
    lineargs = rawline.strip().split(' ')
    n = float(lineargs[0]);
    factual = float(lineargs[1])
    
    xh.append(n)
    yh.append(factual)


fig, (ax1,ax2) = plt.subplots(1,2)
fig.suptitle("Complexidade - Linked List Vs Heap")
ax1.plot(x,y, '.', color='black')
ax2.plot(xh,yh, '.', color='black')

plt.show()