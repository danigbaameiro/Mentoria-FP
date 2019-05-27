#include <iostream>
#include <string>
#include <fstream>
#include "lotes.h"
#include "listalonja.h"
#include "listacompradores.h"
using namespace std;

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    ifstream archivo;
    long long int usuario;
    float precio;
    archivo.open(BD);
    if (archivo.is_open()) {
        tListaLonja lonja;
        inicializa(lonja);
        tListaComprador lista;
        inicializa(lista);
        bool ok = false;
        carga(lonja, archivo, ok);
        if (ok) {
            for (int i = 0; i < lonja.contador; i++) {
                mostrarLote(*(lonja.lonja[i]));
                cout << "Comprador y precio" << endl;
                cin >> usuario;
                cin >> precio;
				modificarLote(*(lonja.lonja[i]), usuario, precio);
                insertar(lista, usuario, precio);
            }
            mostrar(lista);
            mostrar(lonja);
        }
        else {
            cout << "Error al cargar la lonja." << endl;
        }
        libera(lista);
        libera(lonja);
    }
    else {
        cout << "Error al abrir el fichero de datos." << endl;
    }
    system("pause");
    return 0;
} // main
