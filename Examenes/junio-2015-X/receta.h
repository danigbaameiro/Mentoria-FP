#include <string>
#include "componente.h"
using namespace std;

const int MAX_COMPONENTES = 20;

// Tipo puntero a componente
typedef tComponente *tPunteroComponente;

// Lista: array dinámico y contador
typedef struct
{
    tPunteroComponente componentes;
    int contador;
    string nombre;
} tReceta;


// Crea una receta sin componentes
void crea(tReceta &receta);

// Inserta un componente al final de una receta
void inserta(tReceta &receta, tComponente componente, bool &ok);

// Muestra la información de una receta
void muestra(const tReceta &receta);

// Libera la memoria dinámica utilizada
void libera(tReceta &receta);
