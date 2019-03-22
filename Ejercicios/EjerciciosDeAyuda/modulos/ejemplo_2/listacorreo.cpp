#include <iostream>
#include "listacorreo.h"
#include "correo.h"

void leerBandeja(const tListaCorreo lista){
    for(int i = 0; i < lista.contador; i++){
        leerCorreo(lista.bandeja[i]);
    }
}