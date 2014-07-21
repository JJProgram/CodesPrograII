#include <iostream>
#include "Carta.h"
using namespace std;

int main()
{
    Carta c1;
    c1.mostrarCarta();
    Carta c2("Razon","Argentina",20);
    c2.mostrarCarta();
    c1=c2;
    c1.mostrarCarta();
    (++c1).mostrarCarta();
    c1.mostrarCarta();
    (++c1).mostrarCarta();
    Carta c3;
    cin >> c3;
    c3.mostrarCarta();
    cout << "Espero le haya gustado :D" << endl;
    return 0;
}
