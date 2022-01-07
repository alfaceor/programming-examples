programs=randomCongruential randomGSL exponentialDistribution
all:$(programs)
LIBS=-lgsl -lgslcblas -lm

randomCongruential:randomCongruential.cpp
	$(CXX) -o randomCongruential randomCongruential.cpp $(LIBS)

randomGSL:randomGSL.cpp
	$(CXX) -o randomGSL randomGSL.cpp $(LIBS)

exponentialDistribution:exponentialDistribution.cpp
	$(CXX) -o exponentialDistribution exponentialDistribution.cpp $(LIBS)


clean:
	rm -f $(programs)

