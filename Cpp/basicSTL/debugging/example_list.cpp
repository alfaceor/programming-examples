// constructing lists
#include <iostream>
#include <list>
using namespace std;


enum Event_type {GeneChoice_t , Deletion_t , Insertion_t , Dinuclmarkov_t,Undefined_t};
enum Event_safety{VD_safe = 0  , DJ_safe = 1  , VJ_safe = 2 };
enum Seq_side{ Five_prime =0 , Three_prime = 1 , Undefined_side = 2 };
enum Seq_type {V_gene_seq = 0 , VD_ins_seq = 1 , D_gene_seq = 2 , DJ_ins_seq = 3 , J_gene_seq = 4 , VJ_ins_seq = 5};
enum Gene_class{V_gene=0 , VD_genes=1 , D_gene=2 , DJ_genes=3 , J_gene=4 , VJ_genes=5 , VDJ_genes=6 ,Undefined_gene=7 };
enum Fileformat{CSV_f,FASTA_f,TXT_f, FASTQ_f};
enum Int_nt { int_A = 0 , int_C = 1 , int_G = 2 , int_T = 3 , int_R = 4 , int_Y = 5 , int_K = 6 , int_M = 7 , int_S = 8 ,
				int_W = 9 , int_B = 10 , int_D = 11 , int_H = 12 , int_V = 13 , int_N = 14};

typedef std::string Rec_Event_name;


class Rec_Event {
public:
	Rec_Event();
	//Accessors
	const Gene_class get_class() const{return event_class;};
	const Seq_side get_side() const{return event_side;};
	const int get_priority() const{return priority;};
	const Rec_Event_name get_name() const{return name;};
	const std::string get_nickname() const{return nickname;};
	void set_nickname(std::string name){nickname = name;}
	Event_type get_type() const{return this->type;}
  void print();


protected:
	int priority;
	Gene_class event_class;
	Seq_side event_side ;
	Rec_Event_name name; //Construct the name in a smart way so that it is unique
	std::string nickname;
	Event_type type;
	int event_index;
	bool updated;
	bool viterbi_run;
	bool initialized;
};


Rec_Event::Rec_Event(){
    event_class = V_gene;
    event_side = Undefined_side;
    priority = 7;
    name ="Ask Your Mama";
    nickname = "Motherfucker";
    type = GeneChoice_t;

};

void Rec_Event::print(){
  std::cout << "event_class : " << event_class << std::endl;
  std::cout << "event_side  : " << event_side  << std::endl;
  std::cout << "nickname    : " << nickname    << std::endl;
}

int main ()
{
  // constructors used in the same order as described above:
  int intVar = 10;
  intVar = 30;
  Rec_Event ev; // = new Rec_Event();
  ev.print();

  std::list<Rec_Event> ListEventos;
  ListEventos.push_back(ev);
  ev.set_nickname("Forrest Forrest Gump");
  
  std::list<int> first;                                // empty list of ints
  std::list<int> second (4,100);                       // four ints with value 100
  std::list<int> third (second.begin(),second.end());  // iterating through second
  std::list<int> fourth (third);                       // a copy of third

  // the iterator constructor can also be used to construct from arrays:
  int myints[] = {16,2,77,29};
  std::list<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

  std::cout << "The contents of fifth are: ";
  for (std::list<int>::iterator it = fifth.begin(); it != fifth.end(); it++)
    std::cout << *it << ' ';

  std::cout << '\n';

  return 0;
}
