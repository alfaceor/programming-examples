programs=mpiHelloWorld mpiArraySum mpiAvrg
all:$(programs)

mpiHelloWorld:mpiHelloWorld.cpp
	mpic++ -o mpiHelloWorld mpiHelloWorld.cpp

mpiArraySum:mpiArraySum.cpp
	mpic++ -o mpiArraySum mpiArraySum.cpp

mpiAvrg:mpiAvrg.cpp
	mpic++ -o mpiAvrg mpiAvrg.cpp

clean:
	rm $(programs)
