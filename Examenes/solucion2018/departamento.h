#include <string>
#include "listacontratos.h"

const int MAX_EMPLEADOS = 50;

// Estructura de un empleado
typedef struct {
    tPunteroContrato puntero;
    int numero;
} tEmpleado;

// Tipo puntero a empleado
typedef tEmpleado *tPunteroEmpleado;

// Lista: array dinámico y contador
typedef struct {
    tPunteroEmpleado empleados;
    int contador;
    string identificador;
} tDepartamento;

// Devuelve un departamento inicializado sin empleados
tDepartamento inicializar(string identificador);

// Busca un nif en un departamento
int buscarEmpleado(const tDepartamento &departamento, string nif);

// Inserta un nuevo empleado al final de un departamento
void insertarEmpleado(const tListaContratos &lista, tDepartamento &departamento, bool &ok);

// Muestra la información de un empleado
void mostrarEmpleado(tEmpleado empleado);

// Muestra la información de un departamento
void mostrarDepartamento(const tDepartamento &departamento, int pos);

// Libera la memoria dinámica utilizada
void liberar(tDepartamento &departamento);
