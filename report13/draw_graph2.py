# -*- coding: utf-8 -*-

import numpy as np
import matplotlib
import matplotlib.pyplot as plt

data1 = np.loadtxt('data1.csv', delimiter=',', skiprows=1)
data2 = np.loadtxt('data2.csv', delimiter=',', skiprows=1)
data1 = data1.T
data2 = data2.T

fig, ax = plt.subplots()
plt.xlabel("data size")
plt.ylabel("time [s]")
ax.plot(data1[0], data1[2], label="random average", color="red", marker=".")
ax.plot(data2[0], data2[2], label="worst", color="blue",marker=".")
ax.grid(which="major")
ax.legend(loc="best")

#plt.show()
plt.savefig("fig2.png")
