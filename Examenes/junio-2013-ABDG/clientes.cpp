#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "clientes.h"
using namespace std;


void cargaLlamadas(tListaClientes &lista, bool &ok) {
    ok = false;
    ifstream archivo;
    tCliente cliente;
    tLlamada llamada;
    string nif;
    int pos;
    lista.contador = 0;
    archivo.open(BD);
    if (archivo.is_open()) {
        ok = true;
        archivo >> nif;
        while (nif != "X") {
            pos = buscaCliente(lista, nif);
            archivo >> llamada.fecha;
            archivo >> llamada.duracion;
            llamada.coste = ESTABLECIMIENTO + (MINUTO * llamada.duracion / 60);
            if (pos == -1) {
                cliente = nuevoCliente(nif);
                insertaLlamada(cliente.lista, llamada, ok);
                if (ok) {
                    cliente.gasto = llamada.coste;
                    altaCliente(lista, cliente, ok);
                    if (!ok) {
                        cout << "Error en el alta del cliente." << endl;
                    }
                }
                else {
                    cout << "Error al insertar la llamada." << endl;
                }
            }
            else {
                insertaLlamada(lista.clientes[pos].lista, llamada, ok);
                if (!ok) {
                    cout << "Error al insertar la llamada." << endl;
                }
                lista.clientes[pos].gasto += llamada.coste;
            }
            archivo >> nif;
        }
        archivo.close();
    }
} // cargaLlamadas


tCliente nuevoCliente(string nif) {
    tCliente cliente;
    cliente.nif = nif;
    cliente.gasto = 0.0;
    cliente.lista.contador = 0;
    cliente.lista.llamadas = new tLlamada[MAX_LLAMADAS];
    return cliente;
} // nuevoCliente


void altaCliente(tListaClientes &lista, tCliente cliente, bool &ok) {
    ok = true;
    if (lista.contador == MAX_CLIENTES) {
        ok = false;
    }
    else {
        lista.clientes[lista.contador] = cliente;
        lista.contador++;
    }
} // altaCliente


int buscaCliente(const tListaClientes &lista, string nif) {
    int pos = 0;
    bool encontrado = false;
    while ((pos < lista.contador) && !encontrado) {
        if (lista.clientes[pos].nif == nif) {
            encontrado = true;
        }
        else {
            pos++;
        }
    }
    if (!encontrado) {
        pos = -1;
    }
    return pos;
} // buscaCliente


void muestraCliente(tCliente cliente) {
    cout << cliente.nif << endl;
    for (int i = 0; i < cliente.lista.contador; ++i) {
        cout << "     ";
        muestraLlamada(cliente.lista.llamadas[i]);
    }
    cout << "Coste total de las llamadas: " << setprecision(2) << cliente.gasto << " Eur" << endl;
} // muestraCliente


void muestraClientes(const tListaClientes &lista) {
    for (int i = 0; i < lista.contador; i++) {
        muestraCliente(lista.clientes[i]);
    }
    cout << endl;
} // muestraClientes


void descuento(tListaClientes &lista) {
    tLlamada llamada;
    double porciento;
    for (int i = 0; i < lista.contador; i++) {
        lista.clientes[i].gasto = 0;
        for (int j = 0; j < lista.clientes[i].lista.contador; j++) {
            if (lista.clientes[i].lista.llamadas[j].duracion > 180) {
                porciento = lista.clientes[i].lista.llamadas[j].coste * DESCUENTO / 100;
                lista.clientes[i].lista.llamadas[j].coste -= porciento;
            }
            lista.clientes[i].gasto += lista.clientes[i].lista.llamadas[j].coste;
        }
    }
} // descuento


void libera(tListaClientes &lista) {
    for (int i = 0; i < lista.contador; i++) {
        if (lista.clientes[i].lista.contador != 0) {
            delete[] lista.clientes[i].lista.llamadas;
        }
    }
} // libera
