
LIBS= -lgsl -lgslcblas -lm -lboost_program_options

main:main.o Gas.o HeatBath.o
	g++ main.o Gas.o -o main $(LIBS)

main.o:main.cpp
	g++ -c main.cpp

Gas.o:Gas.cpp
	g++ -c Gas.cpp

HeatBath.o:HeatBath.cpp
	g++ -c HeatBath.cpp

clean:
	rm *.o
