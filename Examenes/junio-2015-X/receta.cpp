#include <iostream>
#include "receta.h"


void crea(tReceta &receta) {
    receta.componentes = new tComponente[MAX_COMPONENTES];
    receta.contador = 0;
    cout << "Nombre de la receta: ";
    getline(cin, receta.nombre);
    cout << endl;
} // crea


void inserta(tReceta &receta, tComponente componente, bool &ok) {
    ok = true;
    if (receta.contador == MAX_COMPONENTES) {
        ok = false;
    }
    else {
        receta.componentes[receta.contador] = componente;
        receta.contador++;		
    }
} // inserta


void muestra(const tReceta &receta) {
    int total = 0;
    cout << "Receta: " << receta.nombre << endl;
    for (int i = 0; i < receta.contador; i++) {
        muestra(receta.componentes[i]);
        total += receta.componentes[i].cantidad * receta.componentes[i].puntero->calorias / 100;
    }
    cout << "Total de calorias = " << total << endl;
    cout << endl;	
} // muestra


void libera(tReceta &receta) {
    delete[] receta.componentes;
    receta.contador = 0;
} // libera
