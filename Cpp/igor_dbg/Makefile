programs=main
all:$(programs)

CXXFLAGS=-g -O0

IntStr.o:IntStr.cpp
	g++ -c $(CXXFLAGS) IntStr.cpp 

Utils.o:Utils.cpp Utils.h
	g++ -c $(CXXFLAGS) Utils.cpp 

main.o:main.cpp
	g++ -c $(CXXFLAGS) main.cpp

main:main.o Utils.o IntStr.o
	g++ $(CXXFLAGS) -o main main.o Utils.o IntStr.o

clean:
	rm $(programs) *.o
