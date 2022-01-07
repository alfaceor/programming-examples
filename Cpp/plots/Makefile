all: gnuplot_persist plplot_example
gnuplot_persist:gnuplot_persist.cpp
	g++ gnuplot_persist.cpp -o gnuplot_persist

plplot_example:plplot_example.C
	g++ plplot_example.C -o plplot_example `pkg-config --cflags --libs plplotd-c++`
