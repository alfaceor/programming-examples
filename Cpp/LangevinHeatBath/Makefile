
LIBS = -lgsl -lgslcblas -lm -lboost_program_options

all:LangHB Verlet

LangHB:LangHB.cpp IOParams.o
	g++ -o LangHB LangHB.cpp IOParams.o $(LIBS)

Verlet:Verlet.cpp IOParams.o
	g++ -o Verlet Verlet.cpp IOParams.o $(LIBS)

IOParams.o:IOParams.cpp
	g++ -c IOParams.cpp -o $@

clean:
	rm LangHB
