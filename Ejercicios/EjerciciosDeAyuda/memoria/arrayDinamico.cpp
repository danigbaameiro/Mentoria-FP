#include <iostream>
using namespace std;

/****************************************************************************
 * Dinamico: array que se encuentra en la memoria dinámica.                 *
 * Estatico de datos dinamicos: array con sus datos en la memoria dinamica. *
 * *************************************************************************/

/********************* Array dinamico *******************
 * IMPORTANTE:                                          *
 *      - Los elementos se acceden a traves del puntero *
 *      - Se destruye el puntero que apunta al array    *
 *******************************************************/


typedef struct {
  int codigo;
  string nombre;
  double valor;
}tRegistro;

const int N = 1000;
typedef tRegistro *tRegPtr;

typedef struct {
  tRegPtr puntArray;
  int contador;
}tLista;

tRegistro newRegistro(int codigo, string nombre, double valor);
void show(tLista lista);
void eliminar(tLista lista);

int main(){
  // Inicializamos todo
  tLista lista;
  lista.contador = 0;
  lista.puntArray = new tRegistro[N];

  // Creamos elementos
  lista.puntArray[lista.contador] = newRegistro(123, "Inventado I", 1.1);
  lista.contador++;

  lista.puntArray[lista.contador] = newRegistro(456, "Inventado II", 2.2);
  lista.contador++;

  // Mostramos los elementos
  show(lista);

  // Eliminamos la memoria creada
  eliminar(lista);

  return 0;
}

tRegistro newRegistro(int codigo, string nombre, double valor){
  tRegistro newReg;

  newReg.codigo = codigo;
  newReg.nombre = nombre;
  newReg.valor = valor;

  return newReg;
}

void show(tLista lista){
  cout << "-------------------------------------------" << endl;
  cout << "|         Array de datos dinamicos        |" << endl;
  cout << "-------------------------------------------" << endl;
  cout << " Numero de datos: " << lista.contador << endl;
  cout << " Mostrando array: ";

  for(int i = 0; i < lista.contador; i++){
    cout << endl << endl << " Elemento numero " << i << endl;
    cout << " Codigo: " << lista.puntArray[i].codigo << endl;
    cout << " Nombre: " << lista.puntArray[i].nombre << endl;
    cout << " Valor: " << lista.puntArray[i].valor << endl;
  }

  cout << "-------------------------------------------" << endl;
}

void eliminar(tLista lista){
    delete []lista.puntArray;
}
