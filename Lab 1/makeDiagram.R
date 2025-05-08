#!/usr/bin/env Rscript

# n,s,keyComparison,runtime
nlimit = 10000000

#####################################################################################

# Part (c)i
# For s=32, make n vs keyComparison graph
data = read.csv("./fixedS.csv", header=TRUE)
data$log10n = log(data$n, 10)
log10n = seq(0,7,0.05)
n = 10**log10n
t = n*log(n,2) + 11*n
plot(main=paste("Hybridsort key comparison (S=32)"),
	 x=data$log10n,
	 y=data$keyComparison,
	 xlab="log10(n)",
	 ylab="keyComparison",
	 col="dark green")
lines(log10n, t, col="blue")

#####################################################################################

# Part (c)ii,iii
# For n=1000...10000000, make s vs keyComparison graph
nn = 1000
while(nn <= nlimit){
	data = read.csv("variedS.csv", header=TRUE)
	data = subset(data, n==nn)
	plot(main=paste("Hybridsort key comparison (N=",format(nn, scientific=FALSE, big.mark=','),")",sep=""),
		 x=data$s,
		 y=data$keyComparison,
		 xlab="S",
		 ylab="keyComparison",
		 col="dark green")

	s = seq(1,100)
	t = nn*log(nn/s, 2) + nn*s/4
	lines(s, t, col="blue")

	nn = 10*nn
}

#####################################################################################


# # Part (d)
# For s=1 and s=bestS, make n vs keycomparison and runtime graph
bestS = 6
nn = 10000000
data = read.csv("variedS.csv", header=TRUE)
mergesortData = subset(data, s==1)
hybridsortData = subset(data, s==bestS)

print("Mergesort Data")
print(mergesortData)
print("Hybridsort Data")
print(hybridsortData)

# plot(main=paste("Key comparison"),
# 	 x=hybridsortData$n,
# 	 y=hybridsortData$keyComparison,
# 	 xlab="n",
# 	 ylab="keyComparison")
# points(mergesortData$n, mergesortData$keyComparison, col="blue")

# plot(main=paste("Runtime"),
# 	 x=hybridsortData$n,
# 	 y=hybridsortData$runtime,
# 	 xlab="n",
# 	 ylab="runtime")
# points(mergesortData$n, mergesortData$runtime, col="blue")