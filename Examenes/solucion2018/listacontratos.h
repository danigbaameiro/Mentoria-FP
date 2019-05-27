#ifndef listacontratos_h
#define listacontratos_h
#include <string>
#include "listatareas.h"

const int MAX_CONTRATOS = 100;
const string BD2 = "contratos.txt";

// Estructura de un contrato
typedef struct {
    string nombre;
    string nif;
    tListaTareas lista;
    double sueldo;
} tContrato;

// Tipo puntero a contrato
typedef tContrato *tPunteroContrato;

// Tipo array de punteros a contratos
typedef tPunteroContrato tArrayPunteros[MAX_CONTRATOS];

// Lista: array de datos dinámicos y contador
typedef struct {
    tArrayPunteros contratos;
    int contador;
} tListaContratos;

// Carga una lista de contratos
void cargarContratos(tListaContratos &lista, const tPrioridades &prioridades, bool &ok);

// Inserta un contrato en una lista ordenada de contratos
void insertarContrato(tListaContratos &lista, tContrato contrato, bool &ok);

// Muestra la información de una lista de contratos
void mostrarContratos(const tListaContratos &lista);

// Permite seleccionar un contrato
int seleccionarContrato(const tListaContratos &lista);

// Libera la memoria dinámica utilizada
void liberar(tListaContratos &lista);

#endif
