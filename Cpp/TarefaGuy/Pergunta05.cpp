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

struct Aluno{
  string nome;
  string matricula;
  double nota1;
  double nota2;
  double notaMedia;
};

void printAluno(Aluno& alu){
    alu.notaMedia = 0.5*(alu.nota1 + alu.nota2 );
    cout <<"{ " <<endl;
    cout << "nome      :" <<  alu.nome      << " "<< endl;
    cout << "matricula :" <<  alu.matricula << " "<< endl;
    cout << "média     :" <<  alu.notaMedia << " "<< endl;
    cout <<"}";
    cout << endl;
}

void printAlunoVector(vector<Aluno>& v){
  cout <<"{ " <<endl;
  for(int i=0; i<v.size(); ++i){
    printAluno(v[i]);
  }
  cout <<"}";
  cout <<endl;
}

void insertAluno(Aluno& alu){
  cin.ignore(1024, '\n'); // Para evitar conflitos com o getline. 1024 é so um numero grande de caracteres.
  cout << "nome       : ";
  //cin >> alu.nome; // So pode pegar o primeiro nome
  getline(cin, alu.nome); //, '\n');
  cout << "matricula  : ";
  cin >> alu.matricula;
  cout << "nota1      : ";
  cin >> alu.nota1;
  cout << "nota2      : ";
  cin >> alu.nota2;
  cout << "-----------------------------------" <<endl;
}

void insertAlunoVector(vector<Aluno>& v){
  double element = 0;
  cout << endl;
  for ( int i=0; i<v.size(); i++){
    insertAluno(v[i]);
  }
}

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

  insertAlunoVector(v);
  printAlunoVector(v);

  v.clear();
  return 0;
}
