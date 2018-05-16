#include "llamadas.h"
using namespace std;

const int MAX_CLIENTES = 300;
const int DESCUENTO = 10;

// Estructura de un cliente
typedef struct {
    string nif;
    double gasto;
    tListaLlamadas lista;
} tCliente;

// Array de clientes
typedef tCliente tArray[MAX_CLIENTES];

// Lista de clientes: array y contador
typedef struct {
    tArray clientes;
    int contador;
} tListaClientes;

// Carga las llamadas de todos los clientes
void cargaLlamadas(tListaClientes &lista, bool &ok);

// Crea un nuevo cliente
tCliente nuevoCliente(string nif);

// Inserta un cliente al final de la lista
void altaCliente(tListaClientes &lista, tCliente cliente, bool &ok);

// Busca un cliente con un nif
int buscaCliente(const tListaClientes &lista, string nif);

// Muestra la información de un cliente
void muestraCliente(tCliente cliente);

// Muestra la lista de clientes
void muestraClientes(const tListaClientes &lista);

// Aplica el descuento actualizando coste de llamadas y gasto de clientes
void descuento(tListaClientes &lista);

// Libera la memoria dinámica utilizada
void libera(tListaClientes &lista);


