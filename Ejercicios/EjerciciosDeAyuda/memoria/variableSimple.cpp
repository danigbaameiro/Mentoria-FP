#include <iostream>
using namespace std;

typedef struct{
  string primero;
  string segundo;
  string postre;
}tMenu;

void creacionEntero();
void creacionEstructura();
tMenu nuevo();

int main(){
  cout << "----------------------------------------------" << endl;
  cout << "| Uso de memoria dinamica variable de entero |" << endl;
  cout << "----------------------------------------------" << endl;
  creacionEntero();
  cout << "----------------------------------------------" << endl;

  cout << endl << endl;

  cout << "----------------------------------------------------------" << endl;
  cout << "| Uso de memoria dinamica estructura                     |" << endl;
  cout << "----------------------------------------------------------" << endl;
  creacionEstructura();

  cout << "----------------------------------------------------------" << endl << endl;

  return 0;
}

void creacionEntero(){
  // Creamos un puntero
  int *a, *b;
  // Hacemos que el puntero apunte a un entero en memoria dinamica
  a = new int;
  // Le damos un valor de 12 al puntero
  *a = 12;

  // Podemos hacer los dos pasos anteriores en una sola linea
  b = new int(12);

  cout << "La variable a tiene un valor de: " << *a << endl;
  cout << "La variable b tiene un valor de: " << *b << endl;
}

void creacionEstructura(){
  tMenu menu;
  menu = nuevo();

  tMenu *puntMenu = new tMenu(menu);

  cout << "El primer plato de la estructura es: " << puntMenu->primero << endl;
  cout << "El segundo plato de la estructura es: " << puntMenu->segundo << endl;
  cout << "El tercer plato de la estructura es: " << puntMenu->postre <<  endl;
}

tMenu nuevo(){
  tMenu menu;

  menu.primero = "Macarrones con tomate";
  menu.segundo = "Pollo con patatas";
  menu.postre = "Nada, somos pobres :D";

  return menu;
}
