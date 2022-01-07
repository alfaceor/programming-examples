/*
Crie um programa em C++ que leia um numero e identifique a paridade do mesmo.
a. O programa deve escrever par caso ele o numero lido seja par e impar caso seja impar
b. O calculo deve ser realizado dentro de uma função que receba um valor por parâmetro e retorne verdadeiro.
c. A escrita deve ser feita por um procedimento que receba um boolean por parâmetro e imprima par caso seja verdadeiro e impar caso seja falso
*/

#include <iostream>
using namespace std;

bool isEven(int numero){
  if (numero % 2 == 0 )
    return true;
  else
    return false;
}

void printAnswer(bool flag){
  if (flag)
    cout << "PAR" << endl;
  else
    cout << "IMPAR" << endl;
}


int main(){
  int number = 0;
  cout << "Input:" ;
  cin >> number;
  printAnswer( isEven(number));
  return 0;
}
