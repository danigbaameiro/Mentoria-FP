#include <iostream>
using namespace std;

int main(){
  locale::global(locale("spanish"));
  bool ok = true;

  /********************************* Sawyer ******************************
   * Cuando se realiza una comparación del estilo 
   * if(num == 5), por debajo se hace la comparacion y "nos 
   * devuelve" 1 en caso de ser una comparación acertada o 0 en
   * caso de que num no valga 5, luego "vuelve" y tendriamos if(0)
   * o if(1). En caso de ser 1 entramos dentro del if. Ahora bien, 
   * nosotros sabemos que un booleano tiene solo dos valores, o true
   * cuyo valor es 1 o false, cuyo valor es 0. Podemos poner
   * directamente la variable booleana, dado que será if(ok) teniendo ok
   * como 0 (false -> if(0) ) o 1 (true -> if(1) ).
   ************************************************************************/
  
  if(ok){
    cout << "Todo correcto señor!" << endl;
  }

  else {
    cout << "Algo salió mal :(" << endl;
  }

  //También podemos poner lo contrario a lo que buscamos haciendo uso de !
  if(!ok){
    cout << "Sep... Algo salió mal..." << endl;
  }

  else {
    cout << "Ulala!! Todo correcto :D" << endl;
  }
  
  // system("PAUSE");
  return 0;
}
