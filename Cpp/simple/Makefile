all:mainHMFRelax

LIBS= -lgsl -lgslcblas -lm -lboost_program_options

Ring.o:Ring.cpp
	g++ -c Ring.cpp

mainHMFRelax:mainHMFRelax.cpp Ring.o
	g++ -o mainHMFRelax mainHMFRelax.cpp Ring.o $(LIBS)

clean:
	rm *.o mainHMFRelax


