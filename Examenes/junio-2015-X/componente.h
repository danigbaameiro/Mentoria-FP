#ifndef componente_h
#define componente_h
#include "listaingredientes.h"
using namespace std;

// Estructura de un componente
typedef struct
{
    tPunteroIngrediente puntero;
    int cantidad;
} tComponente;


// Devuelve un componente de receta
tComponente leeComponente(const tListaIngredientes &lista);

// Muestra la información de un componente
void muestra(tComponente componente);

#endif
