#ifndef listacorreo_h
#define listacorreo_h
#include "correo.h"

const int MAX = 10;

typedef tCorreo tBandeja[MAX];

typedef struct {
    int contador;
    tBandeja bandeja;
}tListaCorreo;

void leerBandeja(const tListaCorreo lista);

#endif