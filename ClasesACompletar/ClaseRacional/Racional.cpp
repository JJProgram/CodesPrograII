#include <iostream>
#include "Racional.h"
#define modulo(X)((X)<0?-(X):(X))

void Racional::normalizarRacional(int& n,int& d)
{
    int divisor=2;
    if(d==0)
    {
        d=1;
        cout << "No esta permitido un denominador = 0, cambiado a 1" << endl;
    }
    else
    {
        //AGREGAR CORRECCION NEGATIVOS!!!
        if(n==d)
        {
            n/=n;
            d/=d;
            return;
        }
        else
            while(divisor<=(n/2)||divisor<=(d/2))
            {
                if(n%divisor==0&&d%divisor==0)
                {
                    n/=divisor;
                    d/=divisor;
                }
                divisor++;
            }
    }
}
void Racional::mostrarRacional(void)
{
    cout << numerador << "/" << denominador << endl;
}

Racional::Racional(int numerador,int denominador)
{
    normalizarRacional(numerador,denominador);
    this->numerador=numerador;
    this->denominador=denominador;
}

Racional::~Racional()
{
}
Racional& Racional::operator=(const Racional& obj)
{
    numerador=obj.numerador;
    denominador=obj.denominador;
    return (*this);
}
/*
Racional Racional::operator+(const Racional& obj)const
{

}
*/
