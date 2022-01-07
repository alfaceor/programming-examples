#programs=main_FILE multipleFILEs
programs=multipleFILEs
all:$(programs)
LIBS= -lgsl -lgslcblas -lm -lboost_program_options
main_FILE:main_FILE.cpp
	g++ -o main_FILE main_FILE.cpp $(LIBS)

multipleFILEs:multipleFILEs.cpp
	g++ -o multipleFILEs multipleFILEs.cpp $(LIBS)
