#include <iostream>
#include "listaingredientes.h"
#include "componente.h"
#include "receta.h"


/*****************************************************
 * Author: Ana M. González de Miguel
 * Date: Curso 2017-2018
 *****************************************************/


// Muestra el menú y lee la opción introducida por el usuario
int menu();


int main()
{
    tListaIngredientes lista;
    tReceta receta;
    tComponente componente;
    int opcion;
    bool ok = false;
    carga(lista, ok);
    if (ok) {
        crea(receta);
        do {
            opcion = menu();
            switch (opcion) {
                case 1:
                    componente = leeComponente(lista);
                    inserta(receta, componente, ok);
                    if (!ok) {
                        cout << "Error al insertar el componente." << endl;
                    }
                    break;
                case 2:
                    muestra(receta);
                    break;
            }
        } while (opcion != 0);
        libera(lista);
        libera(receta);
    } else {
        cout << "Error al cargar la lista de ingredientes." << endl;
    }
    return 0;
} // main


int menu() {
    int opcion;
    cout << "1. Aniadir un ingrediente." << endl;
    cout << "2. Mostrar la receta." << endl;
    cout << "0. Salir." << endl;
    do {
        cout << "Elige: ";
        cin >> opcion;
        if ((opcion < 0) || (opcion > 2)) {
            cout << "Opcion no valida." << endl;
        }
    } while ((opcion < 0) || (opcion > 2));
    cout << endl;
    return opcion;
} // menu
