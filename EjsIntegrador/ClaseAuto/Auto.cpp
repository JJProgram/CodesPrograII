#include <iostream>
#include "Auto.h"
char* str_cpy(char* c1,const char* c2)
{
    char* aux=c1;
    while(*c2)
    {
        *c1=*c2;
        c1++;
        c2++;
    }
    *c1='\0';
    return aux;
}
Auto::Auto()
{
    str_cpy(modelo,"***");
    str_cpy(marca,"*******");
    precio=0;
    anio=2014;
}
Auto::Auto (char* mod,char* mar,float pr,int a)
{
    str_cpy(modelo,mod);
    str_cpy(marca,mar); //this->marca=m;
    precio=pr; //this->precio=pr;
    anio=a; //this->anio=a;
}
Auto::~Auto()
{
    //destructor
}
void Auto::mostrarAuto()
{
    cout << marca << " marca: " << modelo << " precio: "
        << precio << " anio: " << anio<< endl;
}
