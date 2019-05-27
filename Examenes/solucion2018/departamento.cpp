#include <string>
#include <iostream>
#include <iomanip>
#include "departamento.h"
#include "checkML.h"
using namespace std;

tDepartamento inicializar(string identificador) {
    tDepartamento departamento;
    departamento.empleados = new tEmpleado[MAX_EMPLEADOS];
    departamento.contador = 0;
    departamento.identificador = identificador;
    return departamento;
} // inicializar


int buscarEmpleado(const tDepartamento &departamento, string nif) {
    int pos = -1, i = 0;
    bool encontrado = false;
    while ((i < departamento.contador) && !encontrado) {
        if (departamento.empleados[i].puntero->nif == nif) {
            encontrado = true;
            pos = i;
        }
        else {
            i++;
        }
    }
    return pos;
} // buscarEmpleado


void insertarEmpleado(const tListaContratos &lista, tDepartamento &departamento, bool &ok) {
    tEmpleado empleado;
	ok = true;
    int pos1, pos2 = -1;
    do {
        pos1 = seleccionarContrato(lista);
        pos2 = buscarEmpleado(departamento, lista.contratos[pos1]->nif);
        if (pos2 == -1) {
            empleado.puntero = lista.contratos[pos1];
            cout << "Numero para el empleado: ";
            cin >> empleado.numero;
            cout << endl;
			if (departamento.contador == MAX_EMPLEADOS) {
                ok = false;
            }
            else {
                departamento.empleados[departamento.contador] = empleado;
                departamento.contador++;
            }
        }
    } while ((pos2 != -1) && ok);
} // insertarEmpleado


void mostrarEmpleado(tEmpleado empleado) {
	cout << fixed << left << setw(30) << empleado.puntero->nombre;
	cout << "num: " << setw(5) << empleado.numero << endl;
} // mostrarEmpleado


void mostrarDepartamento(const tDepartamento &departamento, int pos) {
    if (pos < departamento.contador) {
        cout << pos + 1 << ". ";
        mostrarEmpleado(departamento.empleados[pos]);
        mostrarDepartamento(departamento, pos + 1);
    }
} // mostrarDepartamento


void liberar(tDepartamento &departamento) {
    delete[] departamento.empleados;
} // liberar
