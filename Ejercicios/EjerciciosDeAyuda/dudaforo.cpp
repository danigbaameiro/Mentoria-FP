#include <iostream>
using namespace std;

int main() {
    // your code goes here

    int i;
    i = 382;

    cout << "Añadiendo 0 a la izquierda: ";
    cout.fill  ('0');    
    cout.width ( 8 );
    cout << i << endl << endl;
    
    return 0;
}
