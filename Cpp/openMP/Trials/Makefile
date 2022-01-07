
programs=Trials

all:$(programs)

LIBS= -lgsl -lgslcblas -lm -lboost_program_options

Trials:Trials.cpp
	g++ -o Trials Trials.cpp $(LIBS)

