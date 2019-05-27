#ifndef listalonja_h
#define listalonja_h
#include <fstream>
#include "lotes.h"

const int MAX_LOTES_LONJA = 300;
const string BD = "datos.txt";

// Tipo puntero a lotes
typedef tLotes *tPunteroLotes;

// Tipo array de punteros a lotes
typedef tPunteroLotes tArrayPunteros[MAX_LOTES_LONJA];

// Lista: array de datos dinámicos y contador
typedef struct {
    tArrayPunteros lonja;
    int contador;
} tListaLonja;


// Inicializa una lista de lotes
void inicializa(tListaLonja &lista);

// Devuelve el numero de lotes de una lista
int numLotes(const tListaLonja &lista);

// Inserta un nuevo lote en la lista de lotes
void inserta(tListaLonja &lista, tLotes lote, bool &ok);

// Carga una lista de lotes
void carga(tListaLonja &lista, ifstream &archivo, bool &ok);

// Busca un lote en la lista de lotes
bool busca(const tListaLonja &lista, tLotes lote, int &pos);

// Busca un lote en la lista de lotes por búsqueda binaria
bool buscaBin(const tListaLonja &lista, tLotes lote, int ini, int fin, int &pos);

// Dada una posición válida, devuelve el lote de esa posicion en la lista
void obtenerLote(const tListaLonja &lista, tLotes &lote, int pos);

// Muestra la información de una lista de lotes
void mostrar(const tListaLonja &lista);

// Libera la memoria dinámica utilizada
void libera(tListaLonja &lista);

#endif
