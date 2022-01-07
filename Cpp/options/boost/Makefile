all: first options_description my_options multiple_sources

first:first.cpp
	g++ first.cpp -lboost_program_options -o first

options_description:options_description.cpp
	g++ options_description.cpp -lboost_program_options -o options_description

multiple_sources:multiple_sources.cpp
	g++ multiple_sources.cpp -lboost_program_options -o multiple_sources

my_options.o:my_options.cpp
	g++ -c my_options.cpp 

IOParams.o:IOParams.cpp IOParams.h
	g++ -c IOParams.cpp 

my_options:my_options.o IOParams.o
	g++ my_options.o IOParams.o -lboost_program_options -o my_options 

clean:
	rm first options_description my_options multiple_sources
