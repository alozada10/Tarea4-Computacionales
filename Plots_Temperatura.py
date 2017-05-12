import numpy as np
import matplotlib.pyplot as plt



casos = ["1", "2"]
condiciones = ["F","A","P"]
promedios = ["FM","AM","PM"]
tiempos = ["0","100","2500"]
arr = []
arrm = []
matx = []
ct =0
for i in casos:
	for j in condiciones:
		for k in tiempos:
			a = i
			b = j
			c = k
			txt = np.loadtxt(a+b+c +".txt")
			arr.append(txt)

for i in range(18):
	a = np.zeros((100,100), dtype=float)
	matx.append(a)


def inv(matriz, data):
	count=0
	for i in range(100):
		for j in range(100):
			matriz[j][i]= data[count]
			count+=1




for i in range(len(arr)):
	inv(matx[i], arr[i])




for h in range(len(casos)):
	for j in range(len(condiciones)):
		for k in range(len(tiempos)):
			plt.imshow(matx[ct])
			plt.title(r"Caso: " + casos[h] + condiciones[j] + "   Tiempo: " + tiempos[k] )
			plt.xlabel(r"x (cm)")
			plt.ylabel(r"y (cm)")
			plt.colorbar()
			plt.savefig(casos[h]+condiciones[j]+tiempos[k] + ".png")
			ct +=1
			plt.close()


for i in casos:
	for j in promedios:
			a = i
			b = j
			txt = np.loadtxt(a+b +".txt")
			arrm.append(txt)





t = np.linspace(0,25000,25001)
plt.figure()
plt.plot(t,arrm[0],label ="Fijas")
plt.plot(t,arrm[1],label ="Abiertas")
plt.plot(t,arrm[2],label ="Periodicas")
plt.title("Promedio de temperaturas Caso 1")
plt.xlabel("Tiempo (s)")
plt.ylabel("Temperatura $^{\circ}$C")
plt.legend()
plt.savefig("MEAN1.png")
plt.close()

	

plt.figure()
plt.plot(t,arrm[3],label ="Fijas")
plt.plot(t,arrm[4],label ="Abiertas")
plt.plot(t,arrm[5],label ="Periodicas")
plt.title("Promedio de temperaturas Caso 2")
plt.xlabel("Tiempo (s)")
plt.ylabel("Temperatura $^{\circ}$C")
plt.legend()
plt.savefig("MEAN2.png")
plt.close()
































