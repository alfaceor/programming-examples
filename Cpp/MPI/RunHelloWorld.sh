#!/bin/bash

export PATH=/home/lenin_diaz/libr/openmpi-2.0.2b/bin:$PATH
export LD_LIBRARY_PATH=/home/lenin_diaz/libr/openmpi-2.0.2b/lib:$LD_LIBRARY_PATH


mpirun -np 2 ./mpiHelloWorld
