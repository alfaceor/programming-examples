programs=HeatEngine
all:$(programs)

LIBS= -lgsl -lgslcblas -lm -lboost_program_options


HeatEngine:HeatEngine.cpp
	g++ -o HeatEngine HeatEngine.cpp $(LIBS)

