#ifndef llamadas_h
#define llamadas_h
#include <string>
using namespace std;

const int MAX_LLAMADAS = 500;
const double ESTABLECIMIENTO = 0.15;
const double MINUTO = 0.08;
const string BD = "llamadas.txt";

// Estructura de una llamada
typedef struct {
    string fecha;
    int duracion;
    double coste;
} tLlamada;

// Puntero del array dinámico
typedef tLlamada *tPuntero;

// Lista de llamadas: array dinámico y contador
typedef struct {
    tPuntero llamadas;
    int contador;
} tListaLlamadas;

// Inserta un registro en la lista de llamadas
void insertaLlamada(tListaLlamadas &lista, tLlamada registro, bool &ok);

// Muestra la información de un registro
void muestraLlamada(tLlamada registro);

// Compara dos estructuras tLlamada
bool operator<(tLlamada reg1, tLlamada reg2);

#endif
