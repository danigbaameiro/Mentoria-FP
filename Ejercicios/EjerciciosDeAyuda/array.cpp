#include <iostream>
using namespace std;

const int MAX = 10;

typedef int tNum[MAX];

/* Un array es:
  0     1    2    3   4    5    6    7  
┌----┬----┬----┬----┬----┬----┬----┬----┐
|    |    |    |    |    |    |    |    |
└----┴----┴----┴----┴----┴----┴----┴----┘
*/
  
int main(){
  tNum num;

  if(MAX == 10){
    cout << "Demostrando constante con valor:" << MAX << endl;
  }

  //MAX = 3;

  for(int i = 0; i < MAX; i++){
    num[i] = i;
    cout << "Valor " << num[i] << "es: " << num[i] << endl;
  }

  string cadena;
  
  cout << "Introduce una cadena: " << endl;
  //cin >> cadena;
  getline(cin, cadena);
  cout << cadena;
  
  cout << "Primer caracter: " << cadena[0] << "del tamaño de cadena: " << cadena.length() << endl;
  
  return 0;
}
