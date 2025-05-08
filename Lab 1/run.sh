ulimit -s 1048576
./compile.sh

./runTest.py > variedS.csv
./runTestFixedS.py > fixedS.csv

rm Generator MergeSort HybridSort out.txt inp.txt

./makeDiagram.R > data.txt