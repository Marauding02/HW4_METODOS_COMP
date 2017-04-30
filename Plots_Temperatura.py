import numpy as np
import matplotlib.pyplot as plt

daticos = np.loadtxt("fijas_a_100.txt")
daticos1 = np.loadtxt("fijas_a_2500.txt")
daticos2 = np.loadtxt("Promedio_fijas.txt")

tiempo = daticos2[:,0]
f1_mean = daticos2[:,1]

plt.figure()
plt.plot(tiempo, f1_mean, label=r"$Fijas$")
plt.title("FRONTERAS FIJAS")
plt.xlabel("TIEMPO")
plt.ylabel("TEMP $^{\circ}$C")
plt.savefig("FIJAS.png")

