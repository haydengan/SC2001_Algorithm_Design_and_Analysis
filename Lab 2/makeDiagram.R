#!/usr/bin/env Rscript


#####################################################################################

data = read.csv("./data.csv", header=TRUE)
# print(data)
# break

# Iterate 
for(vv in seq(3,1903,100)){
	print(vv)
	ab = subset(data, v==vv)
	a = subset(ab, algoType==0)
	b = subset(ab, algoType==1)
	# print(ab)
	# print(a)

	# a
	plot(main=paste("Algorithm A (V=",vv,")",sep=""),
		 x=a$e,
		 y=a$runtime,
		 xlab="|E|",
		 ylab="CPU Runtime (us)",
		 col="Red")

	# b
	plot(main=paste("Algorithm B (V=",vv,")",sep=""),
		 x=b$e,
		 y=b$runtime,
		 xlab="|E|",
		 ylab="CPU Runtime (us)",
		 col="Blue")

	# a and b
	plot(main=paste("Algorithm A and B (V=",vv,")",sep=""),
		 x=a$e,
		 y=a$runtime,
		 ylim=c(0,max(a$runtime,b$runtime)),
		 xlab="|E|",
		 ylab="CPU Runtime (us)",
		 col="Red")
	points(b$e, b$runtime, col="Blue")

	a = subset(a, e<=12*vv)
	b = subset(b, e<=12*vv)
	plot(main=paste("Algorithm A and B (zoomed in) (V=",vv,")",sep=""),
		 x=a$e,
		 y=a$runtime,
		 ylim=c(0,max(a$runtime,b$runtime)),
		 xlab="|E|",
		 ylab="CPU Runtime (us)",
		 col="Red")
	points(b$e, b$runtime, col="Blue")
}
