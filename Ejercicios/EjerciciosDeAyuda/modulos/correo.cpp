#include <iostream>
using namespace std;
#include "correo.h"
#include <fstream>
#include <string>

void mostrar(const tListaCorreos &lista){
  if(lista.contador == 0){
    cout << "No hay ningun mensaje cargado. Ejecute la opcion 1.";
  }else{
    for(int i = 0; i < lista.contador; i++){
      cout << "-----------------------------------------------------------" << endl;
      cout << "Id del correo: " << lista.listaCorreos[i].id << endl;
      cout << "Emisor: " << lista.listaCorreos[i].nombre << endl;
      cout << "Email: " << lista.listaCorreos[i].email << endl;
      cout << "Mensaje: " << lista.listaCorreos[i].cuerpo << endl;

      if(lista.listaCorreos[i].spam){
        cout << "Este mensaje ha sido considerado como spam" << endl;
      }else{
        cout << "Mensaje emisor de confianza" << endl;
      }

      cout << "-----------------------------------------------------------" << endl << endl;
    }
  }
}

bool cargar(string nombreFichero, tListaCorreos &lista){
  bool ok = false;

  if(cargarCorreos(nombreFichero, lista)){
    cout << "Todo ha salido guay! Correos cargados al programa :)" << endl << endl;
    ok = true;
  }else{
    cout << "ERROR! Algo ha fallado :S" << endl;
    ok = false;
  }

  return ok;
}

bool cargarCorreos(string nombreFichero, tListaCorreos &lista){
  ifstream entrada;
  bool ok = false;
  tCorreo correo;
  char car;

  entrada.open(nombreFichero);

  if(entrada.is_open()){
    ok = true;
    lista.contador = 0;

    entrada >> correo.id;
    //cout << correo.id << endl;
    while(correo.id != 999){
      entrada >> correo.nombre;
      //cout << correo.nombre << endl;
      entrada >> correo.email;
      //cout << correo.email << endl;
      entrada.get(car);
      getline(entrada, correo.cuerpo);
      //cout << correo.cuerpo << endl;
      entrada >> correo.spam;
      //cout << correo.spam << endl;

      lista.listaCorreos[lista.contador] = correo;
      lista.contador++;
      //cout << "Contador: " << lista.contador << endl;

      entrada >> correo.id;
      //cout << correo.id << endl;
    }

    entrada.close();
  }

  else{
    ok = false;
  }

  return ok;
}
