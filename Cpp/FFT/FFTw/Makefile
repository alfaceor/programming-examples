programs=force_omp

all:$(programs)

LIBS=-lfftw3 -lm

force_omp:force_omp.cpp
	g++ -o force_omp force_omp.cpp -lfftw3 -lfftw3_omp -fopenmp -lm

force:force.cpp
	g++ -o force force.cpp $(LIBS)

clean:
	rm $(programs)

