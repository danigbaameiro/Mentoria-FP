#include <iostream>
using namespace std;
#include"windows.h"

void colorFondo(int color);

int main(){
  for(int i = 0; i < 16; i++){
    colorFondo(i);
    cout << i << " Hola Mundo" << endl;
    colorFondo(0);
  }

  return 0;
}

void colorFondo(int color) {
   HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleTextAttribute(handle, 15 | (color « 4));
}
