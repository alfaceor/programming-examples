programs=main

all: $(programs)

LIBS=-lglfw3 -lGL -lX11 -lpthread -lXrandr -lXi

main:main.cpp
	g++ -o main main.cpp $(LIBS)
