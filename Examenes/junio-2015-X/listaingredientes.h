#ifndef listaingredientes_h
#define listaingredientes_h
#include <string>
using namespace std;

const int MAX_INGREDIENTES = 50;
const string BD = "ingredientes.txt";

// Estructura de un ingrediente
typedef struct
{
    string nombre;
    int calorias;
} tIngrediente;

// Tipo puntero a ingrediente
typedef tIngrediente *tPunteroIngrediente;

// Tipo array de punteros a ingredientes
typedef tPunteroIngrediente tArrayIngredientes[MAX_INGREDIENTES];

// Lista: array de datos dinámicos y contador
typedef struct
{
    tArrayIngredientes ingredientes;
    int contador;
} tListaIngredientes;


// Inserta un ingrediente en una lista
void inserta(tListaIngredientes &lista, tIngrediente ingrediente, bool &ok);

// Carga una lista de ingredientes
void carga(tListaIngredientes &lista, bool &ok);

// Devuelve el nombre de un ingrediente elegido
string selecIngred(const tListaIngredientes &lista);

// Devuelve un ingrediente o -1 si no existe
int busca(const tListaIngredientes &lista, string nombre, int ini, int fin);

// Libera la memoria dinámica utilizada
void libera(tListaIngredientes &lista);

#endif