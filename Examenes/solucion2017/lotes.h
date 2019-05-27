#ifndef lotes_h
#define lotes_h
#include <string>
using namespace std;

// Estructura de un lote
typedef struct {
    string identificador;
    string tipo;
    float peso;
    float precio;
    long long int comprador;
} tLotes;


// Operador relacional menor de dos lotes
bool operator<(tLotes lote1, tLotes lote2);

// Operador relacinoal igual de dos lotes
bool operator==(tLotes lote1, tLotes lote2);

// Muestra la información de un lote
void mostrarLote(tLotes lote);

// Muestra el comprador y el precio de un lote
void mostrarPrecio(tLotes lote);

// Modifica la informacion de un lote
void modificarLote(tLotes &lote, long long int comprador, float precio);


#endif
