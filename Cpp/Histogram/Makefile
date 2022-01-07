all: IntegerHistogram gsl-histogram
LIBS=-lgsl -lgslcblas -lm

###example:example.cpp
###	g++ example.cpp -o example

gsl-histogram:gsl-histogram.cpp
	g++ -o gsl-histogram gsl-histogram.cpp $(LIBS)

IntegerHistogram:IntegerHistogram.cpp
	g++ -o IntegerHistogram IntegerHistogram.cpp $(LIBS)

