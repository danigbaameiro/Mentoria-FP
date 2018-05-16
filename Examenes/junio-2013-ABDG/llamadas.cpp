#include <iostream>
#include <iomanip>
#include "llamadas.h"
using namespace std;


void insertaLlamada(tListaLlamadas &lista, tLlamada registro, bool &ok) {
    ok = true;
    if (lista.contador == MAX_LLAMADAS) {
        ok = false;
    }
    else {
        int i = 0;
        while ((i < lista.contador) && (lista.llamadas[i] < registro)) {
            i++;
        }
        for (int j = lista.contador; j > i; j--) {
            lista.llamadas[j] = lista.llamadas[j - 1];
        }
        lista.llamadas[i] = registro;
        lista.contador++;
    }
} // insertaLlamada


void muestraLlamada(tLlamada registro) {
	// Salida segun formato
    cout << registro.fecha << " ";
    cout << setw(5) << registro.duracion << " seg. ";
    cout << setprecision(2) << registro.coste << " Eur" << endl;
} // muestraLlamada


bool operator<(tLlamada reg1, tLlamada reg2) {
    return reg1.fecha < reg2.fecha;
}
