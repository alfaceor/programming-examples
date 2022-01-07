# g++ -std=c++11 -Wall -Wextra -pedantic -fopenmp critical.cpp
all:openMPwriteFile singlewriteFile

openMPwriteFile:openMPwriteFile.cpp
	g++ -o openMPwriteFile -fopenmp openMPwriteFile.cpp
singlewriteFile:openMPwriteFile.cpp
	g++ -o singlewriteFile openMPwriteFile.cpp
