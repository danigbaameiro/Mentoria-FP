#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>
#include "listaingredientes.h"
using namespace std;


void inserta(tListaIngredientes &lista, tIngrediente ingrediente, bool &ok) {    
    ok = true;
    if (lista.contador == MAX_INGREDIENTES) {
        ok = false;
    }
    else {
        int i = 0;
        while ((i < lista.contador) && (lista.ingredientes[i]->nombre < ingrediente.nombre)) {
            i++;
        }
        for (int j = lista.contador; j > i; j--) {
            lista.ingredientes[j] = lista.ingredientes[j - 1];
        }
        lista.ingredientes[i] = new tIngrediente(ingrediente);
        lista.contador++;
    }
} // inserta


void carga(tListaIngredientes &lista, bool &ok) {
    ok = true;
    tIngrediente ingrediente;
    ifstream archivo;
    string intro;
	lista.contador = 0;
    archivo.open(BD);
    if (!archivo.is_open()) {
        ok = false;
    }
    else {
        archivo >> ingrediente.calorias;
        while ((lista.contador < MAX_INGREDIENTES) && (ingrediente.calorias != -1)) {
            getline(archivo, intro);
            getline(archivo, ingrediente.nombre);
            inserta(lista, ingrediente, ok);
            if (!ok) {
                cout << "Error al insertar el ingrediente." << ingrediente.nombre << "." << endl;
            }
            archivo >> ingrediente.calorias;
        }
    }	
} // carga


string selecIngred(const tListaIngredientes &lista) {
    int numero;
    string nombre;
    for (int i = 0; i < lista.contador; i++) {
        cout << "Ingrediente " << i + 1 << ":" << endl;
		cout << setw(5) << "";
        cout << lista.ingredientes[i]->nombre << endl;
		cout << setw(5) << "";
        cout << lista.ingredientes[i]->calorias << " cal. /100 gr" << endl;
    }
    do {
        cout << endl;
        cout << "Numero: ";
        cin >> numero;
        if ((numero < 1) || (numero > lista.contador)) {
            cout << "Ingrediente no valido." << endl;
        }
    } while ((numero < 1) || (numero > lista.contador));
    nombre = lista.ingredientes[numero - 1]->nombre;
    return nombre;
} // selecIngred


int busca(const tListaIngredientes &lista, string nombre, int ini, int fin) {
    int pos = -1;
    if (ini <= fin) {
        int mitad = (ini + fin) / 2;
        if (nombre == lista.ingredientes[mitad]->nombre) {
            pos = mitad;
        }
        else if (nombre < lista.ingredientes[mitad]->nombre) {
            pos = busca(lista, nombre, ini, mitad - 1);
        }
        else {
            pos = busca(lista, nombre, mitad + 1, fin);
        }
    }
    return pos;
} // busca


void libera(tListaIngredientes &lista) {
    for (int i = 0; i < lista.contador; i++) {
        delete lista.ingredientes[i];	
    }
    lista.contador = 0;
} // libera
