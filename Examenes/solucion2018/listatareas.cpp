#include <fstream>
#include <iostream>
#include <iomanip>
#include "listatareas.h"
#include "checkML.h"
using namespace std;

void cargarPrioridades(tPrioridades &prioridades, bool &ok) {
	ok = true;
    ifstream archivo;
	string finlinea;
    int numero;
    archivo.open(BD1);
    if (!archivo.is_open()) {
        ok = false;
    }
	else {
		for (int i = 0; i < MAX_ANYOS; i++) {
			for (int j = 0; j < MAX_TIPOS_TAREAS; j++) {
				archivo >> prioridades[i][j];
			}
			getline(archivo, finlinea);
		}
		archivo.close();
	}
} // cargarPrioridades


void cargarTareas(tListaTareas &lista, ifstream &archivo, const tPrioridades &prioridades, int numero) {
    tTarea tarea;
    char intro;
    bool ok = false;
    lista.contador = 0;
    for (int i = 0; i < numero; i++) {   
        archivo >> tarea.codigo;
        archivo.sync();
        archivo.get(intro);
        getline(archivo, tarea.descripcion);
        tarea.tiempo = calcularTiempo(prioridades, tarea.codigo - 1);
        insertarTarea(lista, tarea, ok);
        if (!ok) {
            cout << "Error al insertar la tarea." << tarea.codigo << endl;	
        }
    }
} // cargarTareas


int calcularTiempo(const tPrioridades &prioridades, int pos) {
	int sum = 0, media;
	for (int j = 0; j < MAX_ANYOS; j++) {
		sum += prioridades[j][pos];
	}
	media = floor(sum / MAX_ANYOS);
	return HORAS_MES * media;
} // calcularTiempo


void insertarTarea(tListaTareas &lista, tTarea tarea, bool &ok) {
    ok = true;
    if (lista.contador == MAX_TAREAS) {
        ok = false;
    }
    else {
        lista.tareas[lista.contador] = tarea;
        lista.contador++;		
    }
} // insertarTarea


void mostrarTareas(const tListaTareas &lista) {
	cout << "La lista de tareas es: " << endl;
	for (int i = 0; i < lista.contador; i++) {
	    cout << setw(3) << lista.tareas[i].codigo;
        cout << fixed << left << setw(40) << lista.tareas[i].descripcion;
	    cout << "   " << lista.tareas[i].tiempo;
		cout << endl;
	}
	cout << endl;
} // mostrarTareas