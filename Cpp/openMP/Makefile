
LIBS= -lgsl -lgslcblas -lm
all:hello omphello Force ompForce InsideClass ompInsideClass ompClass_separateFile reduction reductionArr
#Class_separateFile
reductionArr:reductionArr.cpp
	g++ -o reductionArr -fopenmp reductionArr.cpp

reduction:reduction.cpp
	g++ -o reduction -fopenmp reduction.cpp

compilerTest:compilerTest.cpp
	g++ -o compilerTest -fopenmp compilerTest.cpp

hello:hello.cpp
	g++ -o hello hello.cpp $(LIBS)

omphello:hello.cpp
	g++ -o omphello -fopenmp hello.cpp $(LIBS)

Force:Force.cpp
	g++ -o Force Force.cpp $(LIBS)

ompForce:Force.cpp
	g++ -o ompForce -fopenmp Force.cpp $(LIBS)

InsideClass:InsideClass.cpp
	g++ -o InsideClass InsideClass.cpp $(LIBS)

ompInsideClass:InsideClass.cpp
	g++ -o ompInsideClass -fopenmp InsideClass.cpp $(LIBS)


#Chain.o:Chain.cpp
#	g++ -c Chain.cpp -o $@
#
#Class_separateFile:Class_separateFile.cpp Chain.o
#	g++ -o Class_separateFile Class_separateFile.cpp Chain.o $(LIBS)
#


Chain.o:Chain.cpp
	g++ -O2 -c Chain.cpp -o $@ -fopenmp

ompClass_separateFile:Class_separateFile.cpp Chain.o
	g++ -O2 -o ompClass_separateFile  -fopenmp Class_separateFile.cpp Chain.o $(LIBS)


clean:
	rm *.o ompClass_separateFile #Class_separateFile


