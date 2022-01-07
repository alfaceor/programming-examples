programs=example_fftw32d example_with_omp

all:$(programs)


example_with_omp:example_with_omp.c
	gcc -o example_with_omp  example_with_omp.c -lfftw3 -lfftw3_omp -fopenmp -lm

example_fftw32d:example_fftw32d.c
	gcc -o example_fftw32d example_fftw32d.c -lfftw3 -lfftw3_omp -lm

clean:
	rm $(programs)

