/*
3. Crie um programa que possua um menu ABRIR NOVO FECHAR
 a. A opção abrir deve ser capaz de abrir um arquivo do tipo TXT
 b. A opção novo deve ser capaz de criar um novo arquivo txt e gravar em um arquivo
 c. a opção FECHAR deve fechar o sistema
*/

#include <iostream>
#include <fstream>
#include <string>
#include "calc.h"

using namespace std;

void printOptions(){
  cout << "====================================\n";
  cout << " 1.- Soma.\n";
  cout << " 2.- Subtração.\n";
  cout << " 3.- Divisão.\n";
  cout << " 4.- Multiplicação.\n";
  cout << " 5.- Sair.\n";
  cout << " Digite sua escolha e aperte ENTER:";
}



int main(){
  
  // Variaveis de entrada
  double a, b;
  cout<< "Digite o primeiro numero : " << endl;
  cin >> a;
  cout<< "Digite o segundo numero  : "  << endl;
  cin >> b;

  int choice;
  bool Exit = false;
  while ( Exit != true){
    printOptions();
    cin >> choice;
  
    switch (choice){
      case 1:
        cout << "Resultado : " << a << " + " << b << " = "<< Add(a, b)            <<endl;
      break;
      case 2:
        cout << "Resultado : " << a << " - " << b << " = "<< Substraction(a, b)   <<endl;
      break;
      case 3:
        cout << "Resultado : " << a << " / " << b << " = "<< Division(a, b)       <<endl;
      break;
      case 4:
        cout << "Resultado : " << a << " * " << b << " = "<< Multiplication(a, b) <<endl;
      break;
      case 5:
        cout << "*****************************************************" <<endl;
        cout << "Tchau tchau" << endl;
        Exit = true;
      break;
      default:
        cout << "Não é uma escolha válida. \n";
        cout << "Tente novamente.\n";
        cin >> choice;
      break;
    }
    
  }
  return 0;
}
