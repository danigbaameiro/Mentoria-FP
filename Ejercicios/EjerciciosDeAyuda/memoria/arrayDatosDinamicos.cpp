#include <iostream>
using namespace std;

/****************************************************************************
 * Dinamico: array que se encuentra en la memoria dinámica.                 *
 * Estatico de datos dinamicos: array con sus datos en la memoria dinamica. *
 * *************************************************************************/

/************* Array de datos dinamicos *************
 * IMPORTANTE:                                      *
 *      - Se crean a medida que se insertan         *
 *      - Se destruyen a medida que se eliminan     *
 ****************************************************/

typedef struct {
  int codigo;
  string nombre;
  double valor;
}tRegistro;

typedef tRegistro *tRegPtr;

const int N = 1000;
// Array de punteros a registros:
typedef tRegPtr tArray[N];

typedef struct {
  tArray registros;
  int contador;
}tLista;


tRegistro newRegistro(int codigo, string nombre, double valor);
void show(tLista lista);
void eliminar(tLista lista);

int main(){
  // Inicializamos todo
  tLista lista;
  lista.contador = 0;

  // Creamos elementos
  lista.registros[lista.contador] = new tRegistro(newRegistro(123, "Inventado", 1.1));
  lista.contador++;

  lista.registros[lista.contador] = new tRegistro(newRegistro(456, "Inventado II", 2.2));
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
    cout << " Codigo: " << lista.registros[i]->codigo << endl;
    cout << " Nombre: " << lista.registros[i]->nombre << endl;
    cout << " Valor: " << lista.registros[i]->valor << endl;
  }

  cout << "-------------------------------------------" << endl;
}

void eliminar(tLista lista){
  for(int i = 0; i < lista.contador; i++){
    delete lista.registros[i];
  }
}
