#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include "listacontratos.h"
#include "checkML.h"
using namespace std;

void cargarContratos(tListaContratos &lista, const tPrioridades &prioridades, bool &ok) {
    ok = true;
    ifstream archivo;
    tContrato contrato;
	string finlinea;
    int numero, num;
	lista.contador = 0;
    archivo.open(BD2);
    if (!archivo.is_open()) {
        ok = false;
    }
    else {
        archivo >> numero;
		getline(archivo, finlinea);
        for (int i = 0; i < numero; i++) {
            getline(archivo, contrato.nombre);
            archivo >> contrato.nif;
			archivo >> contrato.sueldo;
			archivo >> num;
            cargarTareas(contrato.lista, archivo, prioridades, num);
            insertarContrato(lista, contrato, ok);
			if (!ok) {
                cout << "Error al insertar el contrato." << contrato.nif << endl;	
            }
        }
		archivo.close();
    }
} // cargarContratos


void insertarContrato(tListaContratos &lista, tContrato contrato, bool &ok) {
    ok = true;
    if (lista.contador == MAX_CONTRATOS) {
        ok = false;
    }
    else {
        int i = 0;
        while ((i < lista.contador) && (lista.contratos[i]->nif < contrato.nif)) {
            i++;
        }
        for (int j = lista.contador; j > i; j--) {
            lista.contratos[j] = lista.contratos[j - 1];
        } 
        lista.contratos[i] = new tContrato(contrato);
        lista.contador++;
    }
} // insertarContrato


void mostrarContratos(const tListaContratos &lista) {
    for (int i = 0; i < lista.contador; i++) {
        cout << i + 1 << ". " << fixed << left << setw(30) << lista.contratos[i]->nombre;
        cout << setw(10) << lista.contratos[i]->nif;
        cout << " (" << lista.contratos[i]->lista.contador << ") ";
		cout << setprecision(2) << lista.contratos[i]->sueldo << endl;
    }
    cout << endl;
} // mostrarContratos


int seleccionarContrato(const tListaContratos &lista) {
    int orden;
	cout << "La lista de contratos es: " << endl;
    mostrarContratos(lista);
    do {
        cout << "Introduce el numero de linea del contrato: ";
        cin >> orden;
        if ((orden < 1) || (orden > lista.contador)) {
            cout << "Contrato no valido." << endl;
        }
    } while ((orden < 1) || (orden > lista.contador));
    return orden - 1;
} // seleccionarContrato


void liberar(tListaContratos &lista) {
    for (int i = 0; i < lista.contador; i++) {
        delete lista.contratos[i];
    }
} // liberar
