
LIBS= -lgsl -lgslcblas -lm
all:Class_separateFile 

Chain.o:Chain.cpp
	g++ -O2 -c Chain.cpp -o $@

Class_separateFile:Class_separateFile.cpp Chain.o
	g++ -O2 -o Class_separateFile Class_separateFile.cpp Chain.o $(LIBS)



#Chain.o:Chain.cpp
#	g++ -c Chain.cpp -o $@ -fopenmp
#
#ompClass_separateFile:Class_separateFile.cpp Chain.o
#	g++ -o ompClass_separateFile  -fopenmp Class_separateFile.cpp Chain.o $(LIBS)
#

clean:
	rm *.o Class_separateFile


