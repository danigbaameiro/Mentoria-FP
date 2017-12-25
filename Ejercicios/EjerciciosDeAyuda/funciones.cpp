#include <iostream>
using namespace std;

/***************Sawyer*************
 * Tipos de funciones y llamadas
 *********************************/

//Declaramos las funciones
int suma(int max, int min);
double dec(int max, double minD);
bool comp(int num, int tres);

int main(){
  locale::global(locale("spanish"));
  int max = 0, min = 0, noTira = 0, tres = 0;
  double minD = 0;
  bool ok = true;
  
  cout << "Introduzca el primer valor: ";
  cin >> max;

  cout << "Introduzca el segundo valor: ";
  cin >> min;
  cout << endl << endl;

  cout << "Hemos procedido a hacer la suma: "<< max << "+" << min << "=" << suma(max, min) << endl;
  cout << "Y ahora como soy una IA catalana independiente hago la siguiente suma: 13-3=" << suma(13, -3) << endl;
  cout << "Y bueno... Le quito 0.5 al valor min" << endl << endl;

  minD = min-0.5;
  
  cout << "La suma ahora tiene esta forma: " << max << "+" << minD << "=" << dec(max, minD) << endl;
  cout << "Y ahora usaré pueees, bueno hago esto: 13+" << minD << "=" << dec(13, minD) << endl << endl; 

  cout << "El numero 3 es igual al número (escribe un 3): ";
  cin >> tres;

  if(comp(3, tres)){
    cout << "¡Enhorabuena! Son iguales :)" << endl;
  }

  else{
    cout << "... ¡Repite!" << endl;
  }
  
  cout << "Ha salido todo bien? (Responderé por ti)" << endl;
  cout << "El usuario dice: ";

  if(ok)
    cout << "¡Todo perfecto! ¡Eres una máquina bestial!" << endl << endl;
  else
    cout << "Algo salió como no debia... :(" << endl << endl;

  cout << "Como siempre querido usuario, ¡ha sido un placer!" << endl;
  
  //system(PAUSE);
  return 0;
}


int suma(int max, int min){
  int sum = 0;

  sum = max + min;

  //Esta variable al no devolverse se perderá
  int noTira = 156523;
  
  return sum;
}

//Se escribe el contenido de las funciones
double dec(int max, double minD){
  double sumDec = 0;

  sumDec = max + minD;
  
  return sumDec;
}

bool comp(int num, int tres){
  bool ok = false;

  if(num == tres){
    ok = true;
    cout << "-------Por debajo todo guay------" << endl;
  }
  else{
   ok = false;
   cout << "--------Por debajo algo no encaja-------" << endl;
  }

  return ok;
}
