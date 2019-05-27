#include <fstream>
#include <string>
#include <iostream>
#include "listalonja.h"
using namespace std;


void inicializa (tListaLonja &lista) {
    lista.contador = 0;
} // inicializa


int numLotes(const tListaLonja &lista) {
	return lista.contador;
} // numLotes


void inserta(tListaLonja &lista, tLotes lote, bool &ok) {
    ok = true;
    if (lista.contador == MAX_LOTES_LONJA) {
        ok = false;
    }
    else {
        int i = 0;
        while ((i < lista.contador) && *(lista.lonja[i]) < lote) {
            i++;
        }
        for (int j = lista.contador; j > i; j--) {
            lista.lonja[j] = lista.lonja[j - 1];
        }
        lista.lonja[i] = new tLotes(lote);
        lista.contador++;
    }
} // inserta


void carga(tListaLonja &lista, ifstream &archivo, bool &ok) {
    ok = true;
    while (!archivo.eof() && ok) {
        tLotes lote;
        archivo >> lote.identificador;
        archivo >> lote.tipo;
        archivo >> lote.peso;
        archivo >> lote.precio;
        inserta(lista, lote, ok);
    }
} // carga


bool busca(const tListaLonja &lista, tLotes lote, int &pos) {
    return buscaBin(lista, lote, 0, lista.contador - 1, pos);
} // busca


bool buscaBin(const tListaLonja &lista, tLotes lote, int ini, int fin, int &pos) {
    bool encontrado = false;
    if (ini == fin) {
        pos = -1;
        encontrado = false;
    }
    else {
        int mitad = (ini + fin) / 2;
        if (*(lista.lonja[mitad]) == lote) {
            pos = mitad;
            encontrado = true;
        }
        else if (*(lista.lonja[mitad]) < lote) {
            encontrado = buscaBin(lista, lote, mitad + 1, fin, pos);
        }
        else {
            encontrado = buscaBin(lista, lote, ini, mitad - 1, pos);
        }
    }
    return encontrado;
} // buscaBin


void obtenerLote(const tListaLonja &lista, tLotes &lote, int pos) {
	if ((pos > 0) && (pos < lista.contador)) 
		lote = *(lista.lonja[pos]);
} // obtenerLote


void mostrar(const tListaLonja &lista) {
    for (int i = 0; i < lista.contador; ++i) {
        mostrarPrecio(*(lista.lonja[i]));
    }
    cout << endl;
} // mostrar


void libera(tListaLonja &lista) {
    for (int i = 0; i < lista.contador; ++i) {
        delete lista.lonja[i];
    }
} // libera
