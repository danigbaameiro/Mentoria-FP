#include <iostream>
using namespace std;
#include <fstream>

const int PARTIDOS = 5;
const int CIRCUN = 3;

typedef struct {
  string nombre;
  int ideologia;
  int politica;
}tPartido;

typedef tPartido tListaPartido[PARTIDOS];

typedef int tVotos[PARTIDOS];

typedef struct {
  string nombre;
  tVotos votos;
}tCircun;

typedef tCircun tListaCircun[CIRCUN];



bool cargar(tListaCircun listaCircun, tListaPartido listaPartido);
void recuentoVotos(const tListaCircun listaCircun, const tListaPartido listaPartido);
void recuentoPorIdeologia(const tListaCircun listaCircun, const tListaPartido listaPartido);
void recuentoPorRama(const tListaCircun listaCircun, const tListaPartido listaPartido);


int main(){
  tListaCircun listaCircun;
  tListaPartido listaPartido;

  // Cargo del fichero a las estructuras
  if(cargar(listaCircun, listaPartido)){
    cout << "Datos cargados" << endl;
    cout << endl << "--------------- Votos a partidos ---------------" << endl;
    recuentoVotos(listaCircun, listaPartido);
    cout << endl << "---------------- Votos ideologia ---------------" << endl;
    recuentoPorIdeologia(listaCircun, listaPartido);
    cout << endl << "------------------ Votos rama ------------------" << endl;
    recuentoPorRama(listaCircun, listaPartido);
    cout << "------------------------------------------------" << endl << endl;
  }

  return 0;
}

bool cargar(tListaCircun listaCircun, tListaPartido listaPartido){
  bool ok = false;
  ifstream archivo;

  archivo.open("datos.txt");

  if(archivo.is_open()){
    ok = true;
    // Cargo los partidos
    for(int i = 0; i < PARTIDOS; i++){
      archivo >> listaPartido[i].nombre;
      archivo >> listaPartido[i].ideologia;
      archivo >> listaPartido[i].politica;
    } 
    // Cargo las cincunscripciones
    for(int i = 0; i < CIRCUN; i++){
      archivo >> listaCircun[i].nombre;
      for(int j = 0; j < PARTIDOS; j++){
	archivo >> listaCircun[i].votos[j];
      }
    }
    
  }else{
    ok = false;
    cout << "ERROR: No se ha podido abrir el archivo" << endl;
  }
  
  return ok;
}

void recuentoVotos(const tListaCircun listaCircun, const tListaPartido listaPartido){
  int recuento = 0;
  for(int i = 0; i < PARTIDOS; i++){
    for(int j = 0; j < CIRCUN; j++){
      recuento += listaCircun[j].votos[i];
    }
    cout << " Votos del partido " << listaPartido[i].nombre << ": " << recuento << endl;
    recuento = 0;
  }
}

void recuentoPorIdeologia(const tListaCircun listaCircun, const tListaPartido listaPartido){
  int izquierda = 0, centro = 0, derecha = 0;

  for(int i = 0; i < PARTIDOS; i++){
    for(int j = 0; j < CIRCUN; j++){
      if(listaPartido[j].ideologia == 1){
	izquierda += listaCircun[j].votos[i];
      }
      else if(listaPartido[j].ideologia == 2){
	centro += listaCircun[j].votos[i];
      }
      else{
	derecha += listaCircun[j].votos[i];
      }
    }
  }
    cout << " Votos de la izquierda: " << izquierda << endl;
    cout << " Votos de la izquierda-centro: " << izquierda+centro << endl;
    cout << " Votos de la centro: " << centro << endl;
    cout << " Votos de la centro+derecha: " << derecha+centro << endl;
    cout << " Votos de la derecha: " << derecha << endl;
}

void recuentoPorRama(const tListaCircun listaCircun, const tListaPartido listaPartido){
  int centralista = 0, federalista = 0, independentista = 0;

  for(int i = 0; i < CIRCUN; i++){
    for(int j = 0; j < PARTIDOS; j++){
      if(listaPartido[j].politica == 1){
        centralista += listaCircun[j].votos[i];
      }
      else if(listaPartido[j].politica == 2){
        federalista += listaCircun[j].votos[i];
      }
      else{
        independentista += listaCircun[j].votos[i];
      }
    }

    if((centralista+federalista) < independentista){
      cout << " ¡Peligro!¡Indepes ganando en " << listaCircun[i].nombre << "!" << endl;
    }
    centralista = 0; federalista = 0; independentista = 0;
  }
}

