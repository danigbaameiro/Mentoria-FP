#include <iostream>
using namespace std;
#include <iomanip>
#include <fstream>

const int POSIB = 5;
typedef int tEscaneo[POSIB];

/*******************************************
 * Author: Daniel García Baameiro
 * Date: inventado para el curso 2017-2018
 *******************************************/

// Funcion que muestraun menu
int menu();
bool opcionPrimera();
void opcionSegunda();
void mostrar(int dest, int x, int chew, int vacio, int star);
void analizar(char nave, int &dest, int &x, int &chew, int &vacio, int &star);


int main(){
  int opcion = 0;

  opcion = menu();

  while(opcion != 0){
    switch(opcion){
    case 1:
      {
	// usuario introduce cadena
	if(!opcionPrimera()){
	  cout << "Ha ocurrido un error durante el escaneo" << endl;
	}
      }break;
    case 2:
      {
	// se recoge desde archivo
	opcionSegunda();
      }break;
    default:
      {
	cout << endl << "Muchas gracias!" << endl;
      }

    }

    opcion = menu();
  }

  return 0;
}

/*
  Desde la estación situada en el Planeta Ocean hemos realizado un escaneo al espacio. En dicho escaneo hemos detectado diferentes objetos. Se nos ha desconfigurado el detector experimental de objetos. Ayudanos a detectar qué objetos son concretmente enbase a los resultados del detector.

  La cadena se dará o por entrada por consola o por archivo. Hay que recordar que el escaneo tan solo detecta 20 espacios como máximo.

  1.- Leer escaneo desde cadena
  2.- Leer escaneo desde archivo
  0.- Salir

AVANZADA: meter xy, de un archivo a otro

*/

int menu(){
  int opcion = 0;

  do {
    cout << "1.- Leer escaneo desde cadena" << endl;
    cout << "2.- Leer escaneo desde archivo" << endl;
    cout << "0.- Salir" << endl;
    cout << "Eleccion: ";
    cin >> opcion;
  }while(opcion < 0 || opcion > 2);

  return opcion;
}

bool opcionPrimera(){
  string escaneo;
  bool ok = true;
  int dim = 0, destCont = 0, xCont = 0, chewCont = 0, vacioCont = 0, starCont = 0;

  // Se recoge la cadena
  cout << endl << "Introduce los resultados del escaneo: ";
  cin >> escaneo;

  dim = escaneo.length();

  // Se analiza que sea menor de 20
  if(dim > 20){
    cout << "Cadena demasiado grande" << endl;
    ok = false;
  }

  // Se hace una busqueda de elementos

  else{
    for(int i = 0; i < dim; i++){
      analizar(escaneo[i], destCont, xCont, chewCont, vacioCont, starCont);
    }

    mostrar(destCont, xCont, chewCont, vacioCont, starCont);
  }

  return ok;
}

void analizar(char nave, int &dest, int &x, int &chew, int &vacio, int &star){
      if(nave == 'a'){
	dest++;
      }

      else if(nave == 'b'){
        x++;
      }

      else if(nave == 'c'){
        chew++;
      }

      else if(nave == 'd'){
	vacio++;
      }

      else{
        star++;
      }
}

void opcionSegunda(){
  ifstream escaneo;
  char nave;
  int destCont = 0, xCont = 0, chewCont = 0, vacioCont = 0, starCont = 0;

  escaneo.open("escaneo.txt");

  if(escaneo.is_open()){
    while(!escaneo.eof()){
      escaneo >> nave;
      analizar(nave, destCont, xCont, chewCont, vacioCont, starCont);
    }

    mostrar(destCont, xCont, chewCont, vacioCont, starCont);
  }

  else{
    cout << "ERROR: No se ha podido abrir el fichero" << endl;
  }
}

void mostrar(int dest, int x, int chew, int vacio, int star){
  cout << "---------- Recuento ---------- " << endl;
  cout << "|" << setw(30) << "| " << endl;
  cout << "| Destructores imperiales:" <<  setw(2) << dest << " | " << endl;
  cout << "| X-Wing: " << setw(18) << x << " | " << endl;
  cout << "| Chewbacca: " << setw(15) << chew << " | " << endl;
  cout << "| Estrella de la muerte: " << setw(3) << star << " | " << endl;
  cout << "|" << setw(30) << "| " << endl;
  cout << "------------------------------ " << endl;
  cout << endl << endl;
}
