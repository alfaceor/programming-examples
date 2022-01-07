#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXCHARLEN 200

class MDfilenames{
public:
  MDfilenames(const int argc,char **argv);
  char filename_pattern[MAXCHARLEN];
  char filename_pdb[MAXCHARLEN];
  char filename_dat[MAXCHARLEN];
  char filename_ini[MAXCHARLEN];
  char ext_pdb[5];
  char ext_dat[5];
  char ext_ini[5];

  char letter_prefix[MAXCHARLEN];
  char token[5];
};

// TODO: Aqui debo el numero de argumentos que entran
MDfilenames::MDfilenames(const int argc, char **argv){
  // Init file extensions 
  strcpy(ext_pdb,".pdb");
  strcpy(ext_dat,".dat");
  strcpy(ext_ini,".ini");
  
  strcpy(letter_prefix,"_irct____");
   /*
  i: idjob
  r: revision number
  c: chain
  t: temperature
  */
  strcpy(token,"__");
  strcpy(filename_pattern,argv[0]);
  
  for (int i=1; i<argc; i++){
    token[1]=letter_prefix[i];
    strcat(filename_pattern,token);
    strcat(filename_pattern,argv[i]);
  }
}

/*
void MDfilenames::Dfixed(int Dvalue){
  
}
*/

int main(int argc, char* argv[]) {
  MDfilenames mdfile(3,argv);
  printf("filename_pattern ==== %s\n",mdfile.filename_pattern);
  /*
  double Dvalue=3.01;
  mdfile.Dfixed(Dvalue);
  */
}


/*
// input parameters
	char exec_line[]="MD\t[prefix_file]\t[chain]\t[temp]\t[total_time]\t[dt]\t[epsi]\t[q]\t[Ec]\t[print_each]\n";

  if(argc != 10){
		printf("Usage: %s",exec_line);
		return EXIT_FAILURE;
	}

  
  char *prefix_file, *hydroChain;
  prefix_file = argv[1];
  hydroChain  = argv[2];

	char filename_pattern[MAXCHARLEN];
	char filename_pdb[MAXCHARLEN];
	char filename_dat[MAXCHARLEN];
	char filename_ini[MAXCHARLEN];
	char ext_pdb[]=".pdb";
	char ext_dat[]=".dat";
	char ext_ini[]=".ini";


	strcpy(filename_pattern,prefix_file);
	for (int i=2;i<argc;i++){
		strcat(filename_pattern,"_");
		strcat(filename_pattern,argv[i]);
	}

	strcpy(filename_pdb,filename_pattern);
	strcpy(filename_dat,filename_pattern);
	strcpy(filename_ini,filename_pattern);
	strcat(filename_pdb,ext_pdb);
	strcat(filename_dat,ext_dat);
	strcat(filename_ini,ext_ini);

	FILE *fp_pdb, *fp_dat;
	fp_pdb = fopen(filename_pdb,"w");
	fp_dat = fopen(filename_dat,"w");

	// header INPUT data
	fprintf(fp_dat,"# %s",exec_line);
	fprintf(fp_dat,"# ");
	for (int i=0; i<argc; i++){
		fprintf(fp_dat,"%s\t",argv[i]);
	}
	fprintf(fp_dat,"\n");
	fprintf(fp_dat,"#%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n","time","Energy", "KinecticEnergy", "PotentialEnergy", "Rg", "D","HRg","PRg");

  // TODO: Generar los nombres de los archivos
*/

