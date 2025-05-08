#!/usr/bin/env python3
import subprocess, sys
from math import ceil

test = 3
vLimit = 2003
vJump = 100

print("v,e,algoType,runtime")

def runTest(v, e):
	# print("test",v,e)
	subprocess.run("echo "+str(v)+" "+str(e)+" | ./Generator > inp.txt", shell=True, executable="/bin/bash")
	
	subprocess.run("./DijkstraA < inp.txt > out.txt", shell=True, executable="/bin/bash")
	out = list(map(int, open("out.txt","r").read().split()))
	print(v,e,0,out[0],sep=",")

	subprocess.run("./DijkstraB < inp.txt > out.txt", shell=True, executable="/bin/bash")
	out = list(map(int, open("out.txt","r").read().split()))
	print(v,e,1,out[0],sep=",")


for _ in range(test):
	for v in range(3,vLimit,vJump):
		runTest(v, v-1)
		# Do 10 logstep of e
		e = v-1
		r = (v*(v-1)//2 / (v-1))**0.05
		while e <= v*(v-1)//2:
			runTest(v,e)
			e = int(ceil(e*r))
		runTest(v, v*(v-1)//2)
		# Do 10 step of e
		# eJump = int(ceil((v*(v-1)/2 - (v-1)) / 10))
		# for e in range(v-1, v*(v-1)//2+1, eJump):
		# 	for _ in range(test):
		# 		runTest(v, e)




#Using pregenerated test files
# for i in range(1,testCount+1):
# 	# print(i)
# 	# subprocess.run("...", shell=True, executable="/bin/bash")
# 	# subprocess.run("./DijkstraA < ./TestCases/"+str(i)+".in >> data.csv", shell=True, executable="/bin/bash")
# 	# subprocess.run("./DijkstraB < ./TestCases/"+str(i)+".in >> data.csv", shell=True, executable="/bin/bash")
# 	subprocess.run("./DijkstraA < ./TestCases/"+str(i)+".in", shell=True, executable="/bin/bash")
# 	subprocess.run("./DijkstraB < ./TestCases/"+str(i)+".in", shell=True, executable="/bin/bash")
