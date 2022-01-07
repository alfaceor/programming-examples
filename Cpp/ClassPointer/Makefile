
all:main

LIBS= -lgsl -lgslcblas -lm -lboost_program_options

main:main.cpp Ring.o SubSystem.o SubSystem2.o
	g++ main.cpp -o main Ring.o SubSystem.o SubSystem2.o $(LIBS)

Ring.o:Ring.cpp
	g++ -c Ring.cpp

SubSystem.o:SubSystem.cpp
	g++ -c SubSystem.cpp

SubSystem2.o:SubSystem2.cpp
	g++ -c SubSystem2.cpp

clean:
	rm *.o main

