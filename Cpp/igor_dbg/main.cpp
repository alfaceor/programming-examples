#include <iostream>
#include "Utils.h"
#include "IntStr.h"

using namespace std;

int main(){
  Int_Str gene_seq;
  gene_seq.append(0);
  gene_seq.append(2);
  gene_seq.append(1);
  for (auto e :gene_seq){
    cout << e <<endl;
  }
  int memory_layer_cs = 0;
  Safety_bool_map safety_set(3);
	Seq_type_str_p_map constructed_sequences(6);//6 is the number of outcomes for Seq_type
	Mismatch_vectors_map mismatches_lists(6);
	Seq_offsets_map seq_offsets(6,3);
	//void set_value(const K& key ,const V& value , int memory_layer){
  constructed_sequences.set_value(V_gene_seq , &gene_seq , memory_layer_cs);
  constructed_sequences.print2debug();


  cout << "Joder " <<endl;
  return 0;
}

