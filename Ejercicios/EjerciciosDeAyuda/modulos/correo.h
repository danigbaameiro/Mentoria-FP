#ifndef correo_h
#define correo_h

#include <iostream>
using namespace std;

// Constante que nos marcará el número máximo de mensajes
const int MAX = 10;

//Estructura que contendrá los campos de un correo
typedef struct{
  int id;
  string nombre;
  string email;
  string cuerpo;
  bool spam;
}tCorreo;

//Array que contendrá los correos
typedef tCorreo tArrayCorreos[MAX];

//Lista a través de la cual tendrémos un contador con el número de mensajes que almacena el array
typedef struct{
  int contador;
  tArrayCorreos listaCorreos;
}tListaCorreos;

/*******************************************************************
 * Muestra todos los mensajes que se encuentras en la estructura
 * E: lista
 ******************************************************************/
void mostrar(const tListaCorreos &lista);

/*******************************************************************
 * Opcion que hace una llamada a cargarCorreos() e indica al usuario
 * a través de un mensaje si ha sucedido algún error.
 * E: nombreFichero
 * E/S: lista
 ******************************************************************/
bool cargar(string nombreFichero, tListaCorreos &lista);

/*******************************************************************
 * Carga en lista los diferentes correos del archivo nombrado
 * nombreFichero que contiene los correos.
 * E: nombreFichero
 * E/S: lista
 ******************************************************************/
bool cargarCorreos(string nombreFichero, tListaCorreos &lista);

#endif
