programs=openmpReductionArr03 singleReductionArr03
all:$(programs)

openmpReductionArr03:reductionArr03.cpp
	g++ -o openmpReductionArr03 -fopenmp reductionArr03.cpp

singleReductionArr03:reductionArr03.cpp
	g++ -o singleReductionArr03 reductionArr03.cpp

clean:
	rm $(programs)

