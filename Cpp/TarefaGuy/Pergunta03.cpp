/*
3. Crie um programa que possua um menu ABRIR NOVO FECHAR
 a. A opção abrir deve ser capaz de abrir um arquivo do tipo TXT
 b. A opção novo deve ser capaz de criar um novo arquivo txt e gravar em um arquivo
 c. a opção FECHAR deve fechar o sistema
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void printOptions(){
  cout << "====================================\n";
  cout << " 1.- ABRIR.\n";
  cout << " 2.- NOVO.\n";
  cout << " 3.- FECHAR.\n";
  cout << " Digite sua escolha e aperte ENTER:";
}

void Option01(){
  // Abrir arquivo TXT
  cout << "A opção 1 foi escolhida" << endl;
  ifstream arquivo;
  string linea;
  string nomeArquivo = "arquivo.TXT";
  arquivo.open(nomeArquivo.c_str());
  if (arquivo.fail() ){
    cout <<  "====> " <<  nomeArquivo << " não existe !" << endl;
  }else{
    while( !arquivo.eof() ){
      getline(arquivo, linea); 
      cout<<linea; 
    }
  }
  arquivo.close();
}

void Option02(){
  // Criar arquivo novo
  cout << "A opção 2 foi escolhida" << endl;
  ofstream arquivo;
  string nomeArquivo = "arquivoNovo.TXT";
  arquivo.open(nomeArquivo.c_str());
  arquivo << "Este arquivo [e novo." << endl;
  arquivo.close();
  cout << "====> " <<  nomeArquivo << " foi criado." << endl;
}


int main(){
  int choice;
  bool Exit = false;
  while ( Exit != true){
    printOptions();
    cin >> choice;
  
    switch (choice){
      case 1:
        Option01();
      break;
      case 2:
        Option02();
      break;
      case 3:
        cout << "Hasta la vista baby!\n";
        Exit = true;
      break;
      default:
        cout << "Não é uma escolha válida. \n";
        cout << "Tenta novamente.\n";
        cin >> choice;
      break;
    }
    
  }
  return 0;
}
