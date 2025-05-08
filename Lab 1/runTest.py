#!/usr/bin/env python3
import subprocess, sys

print("n,s,keyComparison,runtime")

nlimit = 10000000
slimit = 100
test = 3

# Part (c)ii, iii, and (d)
# for a fixed n, iterate s

n = 1000
while n<=nlimit:
	for _ in range(test):
		subprocess.run("echo " + str(n) + " | ./Generator > inp.txt", shell=True, executable="/bin/bash")

		for s in range(1,slimit):
			subprocess.run("./HybridSort " + str(s) + " < inp.txt > out.txt", shell=True, executable="/bin/bash");
			out = list(map(int, open("out.txt","r").read().split()))
			print(n,s,out[0],out[1],sep=",")
	n = 10*n