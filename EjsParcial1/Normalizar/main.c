#include <stdio.h>
#include <stdlib.h>

#define esBlanco(x)((x)==' '||(x)=='\t')
#define aMayusc(x)((x)>='a'&&(x)<='z'?(x)-32:(x))
#define aMinusc(x)((x)>='A'&&(x)<='Z'?(x)+32:(x))

char* normalizar (char *);
int main()
{
    char cad1[100]={"\t UN\teJEmPlo   ADeCUAdo\t  "};
    char cad2[100]={"   "};
    char cad3[100]={"\tUufFFc Jf \t\t  "};
    printf("\"%s\"\n",normalizar(cad1));
    printf("\"%s\"\n",normalizar(cad2));
    printf("\"%s\"\n",normalizar(cad3));
    return 0;
}

char * normalizar (char * cad)
{
    char*pe,*pl; //puntero escritura, puntero lectura
    pe=pl=cad;
    while(*pl)
    {
        while(esBlanco(*pl)&&*pl)
            pl++;
        if(*pl)
        {
            *pe=aMayusc(*pl);
            pe++;
            pl++;
            while(*pl&&!esBlanco(*pl))
            {
                *pe=aMinusc(*pl);
                pe++;
                pl++;
            }
            if(esBlanco(*pl))
            {
                *pe=' ';
                pe++;
                pl++;
            }
        }
    }
    if(pe>cad) //eliminar el ultimo blanco, si todos fueran blancos no retrocede
         pe--;
    *pe='\0';
    return cad;
}
