programs=rw histo
all:$(programs)

LIBS= -lgsl -lgslcblas -lm -lboost_program_options

rw:rw.cpp
	g++ -O2 -o rw rw.cpp $(LIBS)

histo:histo.cpp
	g++ -O2 -o histo histo.cpp $(LIBS)

clean:
	rm $(programs)
