/*
2. Escreva uma procedimento maior que receba um vetor inteiro v[0..n-1] por parâmetro e o endereço de uma variável como por exemplo maior, e deposite nessa variável o valor do maior elemento do vetor. Escreva também uma função main que use a função maior.
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void printVector(vector<int>& v){
  cout <<"{ ";
  for(int i=0; i<v.size(); ++i)
    cout << v[i] << " ";
  cout <<"}";
  cout <<endl;
}

void maior(vector<int>& v, int index){
  if (v.size() < index || index < 0 ){
    cout << "Endereço inválido o vetor tem " << v.size() << "elementos." << endl;
  }else{
    vector<int>::iterator result;
    result = max_element(v.begin(), v.end());
    cout << "Vector antes : " ;
    printVector(v);
    cout << "O maior [e : " << *result << endl;
    v[index] = *result ;
    cout << "Vector depois : " ;
    printVector(v);
  }
}

int main(){
  vector<int> v = {0, -4, 7, -10} ;
  maior(v, 0);
  return 0;
}
