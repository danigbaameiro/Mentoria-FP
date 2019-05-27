#ifndef listatareas_h
#define listatareas_h
#include <fstream>
#include <string>
using namespace std;

const int MAX_ANYOS = 5;
const int MAX_TIPOS_TAREAS = 7;
const int MAX_TAREAS = 15;
const int HORAS_MES = 20;
const string BD1 = "prioridades.txt";

// Tabla de prioridades
typedef int tPrioridades[MAX_ANYOS][MAX_TIPOS_TAREAS];

// Estructura de una tarea
typedef struct {
    int codigo;
	string descripcion;
    int tiempo;
} tTarea;

// Tipo array de tareas
typedef tTarea tArrayTareas[MAX_TAREAS];

// Lista: array y contador
typedef struct {
    tArrayTareas tareas;
    int contador;
} tListaTareas;

// Carga la tabla de prioridades
void cargarPrioridades(tPrioridades &prioridades, bool &ok);

// Carga una lista de tareas
void cargarTareas(tListaTareas &lista, ifstream &archivo, const tPrioridades &prioridades, int numero);

// Calcula el tiempo asignable a una tarea
int calcularTiempo(const tPrioridades &prioridades, int pos);

// Inserta una tarea al final de la lista de tareas
void insertarTarea(tListaTareas &lista, tTarea tarea, bool &ok);

// Muestra una lista de tareas
void mostrarTareas(const tListaTareas &lista);
#endif