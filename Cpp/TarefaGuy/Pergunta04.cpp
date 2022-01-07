/*
4. Crie um programa que leia um valor n e crie dinamicamente um vetor de n elementos e passe esse vetor para uma função que vai ler os elementos desse vetor. Depois, no programa principal, o vetor preenchido deve ser impresso. Antes de finalizar o programa o programa deve liberar a área de memória alocada. 
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printVector(vector<double>& v){
  cout <<"{ ";
  for(int i=0; i<v.size(); ++i)
    cout << v[i] << " ";
  cout <<"}";
  cout <<endl;
}

void insertVectorElements(vector<double>& v){
  double element = 0;
  cout << "size : " << v.size() <<endl;
  for ( int i=0; i<v.size(); i++){
    cin >> element;
    // v.push_back(element);
    v[i] = element;
  }
}

int main(){
  int n =0;
  cout << "n = " ;
  cin >> n;
  cout <<endl;
  vector<double> v;
  // v.reserve(n);
  v.resize(n);
  cout << "Ingrese os "<< n << " elementos do vetor: "<<endl;

  insertVectorElements(v);
  printVector(v);

  v.clear();
  return 0;
}
