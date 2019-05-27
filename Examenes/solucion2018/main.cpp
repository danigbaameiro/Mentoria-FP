#include <iostream>
#include "listacontratos.h"
#include "listatareas.h"
#include "departamento.h"
#include "checkML.h"

// Muestra el menú y lee la opción introducida por el usuario
int menu();

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    tDepartamento dpto;
    tListaContratos lista;
	tPrioridades prioridades;
    tEmpleado empleado;
    string id, nif;
    int opcion, pos = -1;
    bool ok = false;
	cargarPrioridades(prioridades, ok);
	if (ok) {
        cargarContratos(lista, prioridades, ok);
        if (ok) {
            cout << "Identificador del departamento: ";
            cin >> id;
		    cout << endl;
            dpto = inicializar(id);
            do {
                opcion = menu();
                switch (opcion) {
                    case 1:
                        insertarEmpleado(lista, dpto, ok);
                        if (!ok) {
                            cout << "Error al insertar el empleado." << endl;
                        }
                        break;
                    case 2:
				        cout << "Nif del empleado: ";
                        cin >> nif;
					    cout << endl;
					    pos = buscarEmpleado(dpto, nif);
					    if (pos != -1) {
						    mostrarTareas(dpto.empleados[pos].puntero->lista);
					    } else {
						    cout << "El empleado no existe en el departamento." << endl;
					    }
                        cout << endl;
                        break;
				     case 3:
					    if (dpto.contador != 0) {
							cout << "Los empleados son:" << endl;
						    mostrarDepartamento(dpto, 0);
					    } else {
						    cout << "No hay empleados en el departamento." << endl;
					    }
                        cout << endl;
                        break;
                }
            } while (opcion != 0);
            liberar(lista);
            liberar(dpto);
        }
        else {
            cout << "Error al cargar la lista de contratos." << endl;
        }
	}
	else {
		cout << "Error al cargar las prioridades." << endl;
	}
    return 0;
} // main


int menu() {
    int opcion;
    cout << "1. Insertar empleado en el nuevo departamento." << endl;
	cout << "2. Mostrar las tareas de un empleado." << endl;
    cout << "3. Mostrar los empleados actuales del departamento." << endl;
    cout << "0. Salir." << endl;
    do {
        cout << "Elige opcion: ";
        cin >> opcion;
        if ((opcion < 0) || (opcion > 3)) {
            cout << "Opcion no valida." << endl;
        }
    } while ((opcion < 0) || (opcion > 3));
    cout << endl;
    return opcion;
} // menu
