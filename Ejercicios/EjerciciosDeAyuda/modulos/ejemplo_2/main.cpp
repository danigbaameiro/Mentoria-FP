#include <iostream>
using namespace std;
#include "correo.h"
#include "listacorreo.h"

int main(){
    tCorreo correo;
    tListaCorreo lista;

    // Inicializo variables
    lista.contador = 0;

    // Creo una estructura para un correo
    correo.id = 1234;
    correo.asunto = "Urgente";
    correo.mensaje = "Hola! \n\n ¿Cómo lo llevas? \n\n Un saludo, \n\n Daniel García Baameiro";

    // La meto en la lista
    lista.bandeja[0] = correo;
    lista.contador++;

    leerBandeja(lista);    

    return 0;
}