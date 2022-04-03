#!/usr/bin/python
import sys
import matplotlib.pyplot as plt
from statistics import mean

# Argumetnos del programa: nameSavePlot file1 file2
for i in range(2,len(sys.argv)):
	fileName = sys.argv[i]
	#print("fileName = "+str(fileName))

	file1 = open(fileName, "r") 
	
	y = []
	listTimes = file1.readlines()
	for t in listTimes:
		val = int(t.strip())
		#print(val)
		y.append( val )
	
	x = [ v for v in range(len(y)) ] 	
	media = round( mean(y), 2 )
	plt.plot(x,y, label=fileName+" ( avg = "+str( media )+" )")

	file1.close() 

plt.xlabel('fib(n)') 
plt.ylabel('Tiempo en nanosegundos') 
plt.title('Tiempos de cada funcion') 
plt.legend() # graficar los titulos

nameSavePlot = sys.argv[1]
plt.savefig(nameSavePlot, bbox_inches='tight', dpi=150)
plt.show()
