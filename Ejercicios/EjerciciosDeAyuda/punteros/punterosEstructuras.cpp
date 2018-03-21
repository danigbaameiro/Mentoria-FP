#include <iostream>
using namespace std;
#include <iomanip>

typedef struct {
  int codigo;
  string nombre;
  double sueldo;
}tRegistro;

typedef tRegistro *tRegistroPtr;

int main(){
  tRegistro registro;
  tRegistroPtr puntero = &registro;

  registro.codigo = 101;
  registro.nombre = "Daniel";
  registro.sueldo = 0;

  cout << setw(10) << left << "Codigo: " << puntero->codigo << endl;
  cout << setw(10) << left << "Nombre: " << puntero->nombre << endl;
  cout << setw(10) << left << "Sueldo: " << puntero->sueldo << endl;

  return 0;
}
