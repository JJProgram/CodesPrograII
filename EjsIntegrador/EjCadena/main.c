#include <stdio.h>
#include <stdlib.h>

int main()
{
    char cadena1[40]={"Copa lata"},cadena2[40]={"Hola lorena"};
    printf("\"%s\" y \"%s\"\n",cadena1,cadena2);
    printf("Se encontraron %d ocurrencias\n",eliminarOcurrencias(cadena1,cadena2));
    printf("\"%s\" y \"%s\"\n",cadena1,cadena2);
    return 0;
}
int eliminarOcurrencias(char* cad1,char* cad2)
{
    int contCoinc;
    char* pl1,*pe1,*pl2,*pe2;
    if(!*cad1||!*cad2)
        return 0; //si alguna de las cadenas es nula, directamente se que no habra coincidencias
    contCoinc=0;
    pl1=pe1=cad1;
    pl2=pe2=cad2;
    while(*pl1&&*pl2)
    {
        if(*pl1!=*pl2)
        {
            *pe1=*pl1;
            *pe2=*pl2;
            pl1++;
            pl2++;
            pe1++;
            pe2++;
        }
        else
        {
            contCoinc++;
            pl1++;
            pl2++;
        }
    }
    while(*pl1)
    {
        *pe1=*pl1;
        pl1++;
        pe1++;
    }
    while(*pl2)
    {
        *pe2=*pl2;
        pl2++;
        pe2++;
    }
    *pe1='\0';
    *pe2='\0';
    return contCoinc;
}
