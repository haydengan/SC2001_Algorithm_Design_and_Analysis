#!/usr/bin/env python3
import subprocess, sys

print("n,s,keyComparison,runtime")

nlimit = 10000000
slimit = 100
test = 3

# Part (c)i
# for a fixed s, iterate n
s = 32
n = 1000
while n<=nlimit:
	for _ in range(test):
		subprocess.run("echo " + str(n) + " | ./Generator > inp.txt", shell=True, executable="/bin/bash")

		subprocess.run("./HybridSort " + str(s) + " < inp.txt > out.txt", shell=True, executable="/bin/bash");
		out = list(map(int, open("out.txt","r").read().split()))
		print(n,s,out[0],out[1],sep=",")
	n = int(1.77827*n) #10**0.25

