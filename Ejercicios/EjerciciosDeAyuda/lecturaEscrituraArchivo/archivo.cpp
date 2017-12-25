#include <iostream>
using namespace std;

// Declarar biblioteca
#include <fstream>

int main(){
  //Variable para lectura
  ifstream entrada;

  //Variable para escritura
  ofstream salida;

  string cojo;
  
  entrada.open("archivo.txt");

  if(entrada.is_open()){
    //Modelo de busqueda
    getline(entrada, cojo);
    
    while(cojo != "XXX"){
      cout << cojo << endl;
      getline(entrada, cojo); 
    }
  }
  
  else{
    cout << "ERROR" << endl;
  }

  entrada.close();

  return 0;
}
