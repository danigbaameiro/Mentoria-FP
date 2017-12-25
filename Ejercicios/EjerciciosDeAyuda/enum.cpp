#include <iostream>
using namespace std;

/************************* Sawyer ****************************
 * Declaramos un tipo enumerado llamado tDias
 * Recordad que empezamos desde el 0 - lunes, 1 - martes, ...
 *************************************************************/
typedef enum {lunes, martes, miercoles, jueves, viernes, sabado, domingo} tDias;

tDias eleccionDia();

int main(){
  locale::global(locale("spanish"));
  tDias dia;

  // La funcion es tDias, por tanto recogemos el valor con la variable tDias dias
  dia = eleccionDia();

  /****************************************************************************** 
   * Si nos fijamos en el switch, el enumerado nos sirve para poner un nombre en
   * lugar de poner el valor numerico tal cual. A la hora de leerlo nos facilita
   * la comprensión del código.
  *******************************************************************************/

  switch(dia){
    case lunes: cout << "Pff... lunes... Quiero dormir..." << endl; break;
    case martes: cout << "Martes... Otra vez a la uni..." << endl; break;
    case miercoles: cout << "Miercoles... ¡Montaditos a un pavo! :D" << endl; break;
    case jueves: cout << "2x1 en el TGB!!!!!!! :D" << endl; break;
    case viernes: cout << "VIVAN LOS VIERNES!! A BEBER!! Digo estudiar (:" << endl; break;
    default: cout << "Pero en qué día vives!?" << endl;
  }
  
  return 0;
}

// Pasando de un entero a un enumerado
tDias eleccionDia(){
  int num;

  cout << "Digame un día del 1 al 7: ";
  cin >> num;
  cout << endl;

  //Podemos devolver una conversion de un entero. Hacemos num-1 porque el primer valor del enumerado equivale al  0 el cual es el lunes, el 1 al martes y así sucesivamente.
  return tDias(num-1);
}
