#include <iostream>
using namespace std;

const int N = 10;
typedef int tElementos[N];

typedef struct{
  tElementos elementos;
  int contador;
}tLista;

int buscar(tLista lista, int buscado, int ini, int fin);
void newList(tLista &lista);

int main(){
  locale::global(locale("spanish"));
  tLista lista;
  int numero;

  newList(lista);

  do{
    cout << "Del 1 al 10 indicanos que número buscar: ";
    cin >> numero;

    if(numero < 1 || numero > 10){
      cout << endl << "ERROR: por favor, ¡del 1 al 10!" << endl;
    }
  }while(numero < 1 || numero > 10);

  // Recojo la posición
  int pos = buscar(lista, numero, 0, lista.contador-1);

  cout << "Hemos encontrado el numero " << numero << " en la posicion " << pos+1 << endl;

  return 0;
}

void newList(tLista &lista){
  lista.contador = N;
  for (int i = 0; i < N; i++){
    lista.elementos[i] = i+1;
  }
}

int buscar(tLista lista, int buscado, int ini, int fin) {
   int pos = -1;
   if(ini <= fin) {
      int mitad = (ini + fin) / 2;
      if(buscado == lista.elementos[mitad]) {
         pos = mitad;
      }
      else if (buscado < lista.elementos[mitad]) {
         pos = buscar(lista, buscado, ini, mitad -1);
      }
      else {
         pos = buscar(lista, buscado, mitad + 1, fin);
      }
   }
   return pos;
}
