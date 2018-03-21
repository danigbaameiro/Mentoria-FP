#include <iostream>
using namespace std;


int main(){
  int *puntI, *puntJ; //puntero a entero
  int i = 1; //dato entero
  int j = 2;

  puntI = &i; //el puntero contiene la dirección en memoria de i
  puntJ = &j;

  cout << "Suma de i+j = " << i+j << endl;
  cout << "Suma memoria de punteros puntI + puntJ = " << *puntI + *puntJ << endl;

  int prueba;
  int *nuevo = &prueba;
  *nuevo = 20;

  cout << "Direccion en memoria: " << &nuevo << endl;
  cout << "Valor en memoria: " << *nuevo << endl;

  cout << "Resto uno al valor en la direccion a la que apunta puntI haciendo: " << endl;
  *puntI = *puntI - 1;

  cout << "i vale: " << i << endl;
  cout << "puntI vale: " << *puntI << endl;

  return 0;
}
