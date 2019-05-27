#include <iostream>
#include <iomanip>
#include "listacompradores.h"
using namespace std;


void inicializa(tListaComprador &lista) {
    lista.tamanyo = MAX_INI_COMPRADORES;
    lista.contador = 0;
    lista.compradores = new tComprador[MAX_INI_COMPRADORES];
} // inicializa


void aumentar(tListaComprador &lista) {
    tListaComprador aux;
    aux.contador = lista.contador;
    aux.tamanyo = 2 * lista.tamanyo + 1;
    aux.compradores = new tComprador[aux.tamanyo];
    for (int i = 0; i < aux.contador; ++i) {
        aux.compradores[i] = lista.compradores[i];
    }
    delete[] lista.compradores;
    lista = aux;
} // aumentar


void insertar(tListaComprador &lista, long long int comprador, float precio) {
    int pos;
    if (lista.contador == lista.tamanyo) {
        aumentar(lista);
    }
    if (buscar(lista, comprador, pos)) {
        lista.compradores[pos].total += precio;
    }
    else {
        lista.compradores[lista.contador].numero = comprador;
        lista.compradores[lista.contador].total = precio;
        lista.contador++;
    }
} // insertar


bool buscar(const tListaComprador &lista, long long int comprador, int &pos) {
    bool encontrado = false;
    int i = 0;
    while ((i < lista.contador) && !encontrado) {
        if (lista.compradores[i].numero == comprador) {
            encontrado = true;
        }
        else {
            i++;
        }
    }
    if (encontrado){
        pos = i;
    }
    return encontrado;
} // buscar


void mostrar(const tListaComprador &lista) {
    for (int i = 0; i < lista.contador; ++i) {
        cout << "Comprador: " << setw(10) << lista.compradores[i].numero;
        cout << setw(10) << ' ';
        cout << "Total: " << lista.compradores[i].total << endl;
    }
} // mostrar

void libera(tListaComprador &lista) {
    delete[] lista.compradores;
} // libera
