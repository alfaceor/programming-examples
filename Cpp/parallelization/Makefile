
programs=rw3D_RegularPorousDepletion_F2B_VAR__B2F_VAR__B2B_VAR__HRadius_VAR__BRadius  debug
all:$(programs)


LIBS= -lgsl -lgslcblas -lm -lboost_program_options

#debug:debug.cpp
#	g++ -g -o debug debug.cpp $(LIBS)

debug:rw3D_RegularPorousDepletion_F2B_VAR__B2F_VAR__B2B_VAR__HRadius_VAR__BRadius.cpp
	g++ -g -o debug rw3D_RegularPorousDepletion_F2B_VAR__B2F_VAR__B2B_VAR__HRadius_VAR__BRadius.cpp $(LIBS)

rw3D_RegularPorousDepletion_F2B_VAR__B2F_VAR__B2B_VAR__HRadius_VAR__BRadius:rw3D_RegularPorousDepletion_F2B_VAR__B2F_VAR__B2B_VAR__HRadius_VAR__BRadius.cpp
	g++ -O3 -o rw3D_RegularPorousDepletion_F2B_VAR__B2F_VAR__B2B_VAR__HRadius_VAR__BRadius rw3D_RegularPorousDepletion_F2B_VAR__B2F_VAR__B2B_VAR__HRadius_VAR__BRadius.cpp $(LIBS)

clean:
	rm  $(programs)
