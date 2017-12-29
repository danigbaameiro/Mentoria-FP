#include <iostream>
using namespace std;
#include <math.h>

/*******************************************************************************
 * Url ejercicio: https://aceptaelreto.com/problem/statement.php?id=140&cat=48 *
 * Resuelto por: Daniel García Baameiro                                        *
 *******************************************************************************/

int sumaDig(int n, int &tamanio);

int main(){
  int num = 0, xsuma = 0, tamanio = 0, division = 0;

  cin >> num;
  while(num != -1){
    tamanio = 1;
    division = 0;
    suma = sumaDig(num, tamanio);

    for(int i = tamanio-1; i > 0; i--){
      division = num/(pow(10,(i-1)));
      num = num - division*(pow(10,(i-1)));
      cout << division;
      
      if(i != 1)
	cout << " + ";
      else
	cout << " = ";
    }

    cout << suma << endl;
    cin >> num;
  }


  return 0;
}

int sumaDig(int n, int &tamanio){
   int suma=0;
   
   if (n < 0)
     n=-n;
   else if(n == 0)
     tamanio++;
   
   while (n!=0) {  
     suma = (n%10) + suma;
     n = n/10;
     tamanio++;
   }

   return suma;
}
