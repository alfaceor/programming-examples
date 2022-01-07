/*
5. Crie um programa que possa cadastrar n alunos
 a. Cada aluno deve possuir nome, numero da matrícula e duas notas.
 b. Em seguida imprima a matrícula, o nome e a média de cada um dos alunos cadastrados.
 c. Utilize struct para representar os alunos
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Aluno{
  private:
    string nome;
    string matricula;
    double nota1;
    double nota2;
    double notaMedia;

  public:
    Aluno();
    Aluno(string nome, string matricula, double nota1, double nota2);
    ~Aluno();
    void setNome(string nome);
    void setMatricula(string matricula);
    void setNota1(double nota1);
    void setNota2(double nota2);
    void print();
    void insertAluno();
    void calcMean();
};

Aluno::Aluno(){
  this->nome      = "";
  this->matricula = "";
  this->nota1     =  0;
  this->nota2     =  0;
  this->notaMedia =  0;
}

Aluno::Aluno(string nome, string matricula, double nota1, double nota2){
  this->nome      = nome;
  this->matricula = matricula;
  this->nota1     = nota1;
  this->nota2     = nota2;
  this->notaMedia = notaMedia;
}

Aluno::~Aluno(){
}

void Aluno::print(){
    calcMean();
    cout <<"{ " <<endl;
    cout << "nome      :" <<  nome      << " "<< endl;
    cout << "matricula :" <<  matricula << " "<< endl;
    cout << "média     :" <<  notaMedia << " "<< endl;
    cout <<"}";
    cout << endl;
}

void Aluno::calcMean(){
  notaMedia = 0.5*(nota1 + nota2 );
}

// void printAlunoVector(vector<Aluno>& v){
//   cout <<"{ " <<endl;
//   for(int i=0; i<v.size(); ++i){
//     printAluno(v[i]);
//   }
//   cout <<"}";
//   cout <<endl;
// }

void Aluno::insertAluno(){
  cin.ignore(1024, '\n'); // Para evitar conflitos com o getline. 1024 é so um numero grande de caracteres.
  cout << "nome       : ";
  getline(cin, nome);
  // cin >> nome; // So pode pegar o primeiro nome
  cout << "matricula  : ";
  cin >> matricula;
  cout << "nota1      : ";
  cin >> nota1;
  cout << "nota2      : ";
  cin >> nota2;
  cout << "-----------------------------------" <<endl;
}

// void insertAlunoVector(vector<Aluno>& v){
//   double element = 0;
//   cout << endl;
//   for ( int i=0; i<v.size(); i++){
//     insertAluno(v[i]);
//   }
// }

int main(){
  //  Aluno alu;
  //  insertAluno(alu);
  //  printAluno(alu);

  int n =0;
  cout << "Numero de alunos = " ;
  cin >> n;
  cout <<endl;
  vector<Aluno> v;
  // v.reserve(n);
  v.resize(n);
  cout << "Ingrese os "<< n << " alunos: "<<endl;
  for ( int i=0; i<v.size(); i++){
    v[i].insertAluno();
  }
  for ( int i=0; i<v.size(); i++){
    v[i].print();
  }

  // insertAlunoVector(v);
  // printAlunoVector(v);

  v.clear();
  return 0;
}
