#include <iostream>
using namespace std;
#include "correo.h"

/*****************************************************************************
Enunciado: este ejercicio busca servir de ejemplo en cuanto a modularización.

Se considerá modulo al fichero .cpp que se encuentra junto al fichero .h

                            .cpp        .h
                          ┌------┐   ┌------┐
                          |      |   |      |
                          |      |   |      |
                          └------┘   └------┘

Para compilar: g++ -o ejecutable main.cpp correo.cpp
******************************************************************************/

/* Muestra un menu con diferentes opciones*/
int menu();

int main(){
  tListaCorreos lista;
  string nombre = "mensajes.txt";

  cout << "Hola! Bienvenido al gestor de correos :)" << endl;
  cout << "Que desea hacer?" << endl << endl;

  int opcion = menu();

  while(opcion != 0){
    switch (opcion) {
      case 1: cargar(nombre, lista); break;
      case 2: mostrar(lista); break;
    }

    opcion = menu();
  }

  cout << "Hasta luego! :D"

  return 0;
}

int menu(){
  int opcion = 0;

  cout << "1.- Cargar correos" << endl;
  cout << "2.- Mostrar correos" << endl;
  cout << "0.- Salir" << endl;
  cout << "Seleccione una de las opciones: ";
  cin >> opcion;
  cout << endl;

  return opcion;
}
