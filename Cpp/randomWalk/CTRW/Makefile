programs=example_ctrw ctrw__mu_var__lmax_var02 ctrw__mu_var__lmax_var
all:$(programs)

LIBS = -lgsl -lgslcblas -lm -lboost_program_options

example_ctrw:example_ctrw.cpp
	g++ -o example_ctrw example_ctrw.cpp $(LIBS)

ctrw__mu_var__lmax_var:ctrw__mu_var__lmax_var.cpp
	g++ -o ctrw__mu_var__lmax_var ctrw__mu_var__lmax_var.cpp $(LIBS)

ctrw__mu_var__lmax_var02:ctrw__mu_var__lmax_var02.cpp
	g++ -o ctrw__mu_var__lmax_var02 ctrw__mu_var__lmax_var02.cpp $(LIBS)

