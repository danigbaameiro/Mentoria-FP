#include <iostream>
using namespace std;

int main(){
  int opt = -1;

  cout << "Introduce una opcion: ";
  cin >> opt;
  cout << endl;
  
  while(opt != 0){
    cout << "Opción seleccionada: " << opt << endl;

    cout << "Repite la opcion: ";
    cin >> opt;
    cout << endl;
  }

  //system("PAUSE");
  return 0;
}
