#include <iostream>
#include <iomanip>
#include "componente.h"


tComponente leeComponente(const tListaIngredientes &lista) {
    tComponente componente;
    int i = 0;
    bool encontrado = false;
    string nombre = selecIngred(lista);
    while ((i < lista.contador) && !encontrado) {
        if (nombre == lista.ingredientes[i]->nombre) {
            encontrado = true;
        }
        else {
            i++;
        }
    }
    if (encontrado) {
        componente.puntero = lista.ingredientes[i];
        cout << "Cantida en gr.: ";
        cin >> componente.cantidad;
    }
    else {
        cout << "Error. Ingrediente no encontrado." << endl;
    }
    cout << endl;
    return componente;
} // leeComponente


void muestra(tComponente componente) {
    cout << setw(5) << "";
    cout << fixed << right << setw(4) << componente.cantidad;
    cout << " gr. de " << componente.puntero->nombre << endl;
} // muestra
