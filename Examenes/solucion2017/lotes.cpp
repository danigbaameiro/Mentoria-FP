#include <string>
#include <iomanip>
#include <iostream>
#include "lotes.h"
using namespace std;


bool operator<(tLotes lote1, tLotes lote2) {
    return ((lote1.tipo < lote2.tipo) || ((lote1.tipo == lote2.tipo) && (lote1.identificador < lote2.identificador)));
} // operator<


bool operator==(tLotes lote1, tLotes lote2) {
    return lote1.identificador == lote2.identificador;
} // operator==


void mostrarLote(tLotes lote) {
    cout << "Lote: " << setw(10) << lote.identificador;
    cout << setw(10) << ' ';
    cout << "Peso del lote: "  << fixed << setprecision(2) << lote.peso << endl;
    cout << "Tipo: " << setw(10) << lote.tipo;
    cout << setw(10) << ' ';
    cout << "Precio de salida: " << fixed << setprecision(2) << lote.precio << endl;
} // mostrarLote


void mostrarPrecio(tLotes lote) {
    cout << "Lote: " << setw(10) << lote.identificador;
    cout << setw(10) << ' ';
    cout << "Comprador: "  << fixed << setprecision(2) << lote.comprador << endl;
    cout << "Tipo: " << setw(10) << lote.tipo;
    cout << setw(10) << ' ';
    cout << "Precio de compra: " << fixed << setprecision(2) << lote.precio << endl;
} // mostrarPrecio


void modificarLote(tLotes &lote, long long int comprador, float precio) {
	lote.precio = precio;
	lote.comprador = comprador;
} // modificarLote