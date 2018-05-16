#include <fstream>
#include <string>
#include <iostream>
#include "llamadas.h"
#include "clientes.h"
using namespace std;

/*****************************************************
 * Author: Ana M. González de Miguel
 * Date: Curso 2017-2018
 *****************************************************/

int main() {
    tListaClientes lista;
    bool ok = false;
    cargaLlamadas(lista, ok);
    if (ok) {
        muestraClientes(lista);
		cout << "Aplicando el descuento: " << endl;
        descuento(lista);
        muestraClientes(lista);
        libera(lista);
    }
    else {
        cout << "Error al cargar el archivo de llamadas." << endl;
    }
    system("pause");
    return 0;
} // main
