#include <iostream>
using namespace std;

/*********************************************************************
 * Para entender de forma visual abre el gif situado en esta carpeta *
 *********************************************************************/
const int N = 8;
typedef int tLista[N];

void viewArray(tLista lista);
void burbuja(tLista lista);

int main(){
  tLista lista = {6,5,3,1,8,7,2,4};

  // Mostramos el array
  cout << "Momento de iniciar" << endl;
  cout << "-----------------" << endl << endl;
  viewArray(lista);

  //Ordenamos el array
  burbuja(lista);

  // Mostramos el array
  cout << "Tras haber ordenado" << endl;
  cout << "-----------------" << endl << endl;
  viewArray(lista);

  return 0;
}

void viewArray(tLista lista){
  cout << "Array:";

  for(int i = 0; i < N; i++){
    cout << " " << lista[i];
  }

  cout << endl;
}

void burbuja(tLista lista){
  bool inter = true;
  int i = 0;
  // Desde el 1º hasta el penúltimo si hay intercambios...

  while ((i < N - 1) && inter) {
    inter = false;
    // Desde el último hasta el siguiente a i...
    for (int    j = N - 1; j > i; j--) {
      if(lista[j] < lista[j -1]) {
	int tmp;
	tmp = lista[j];
	lista[j] = lista[j - 1];
	lista[j - 1] = tmp;
	inter = true ;
      }
    }
   if(inter) {
     i++;
   }
  }
}
