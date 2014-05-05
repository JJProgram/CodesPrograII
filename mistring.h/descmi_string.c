#include "mi_string.h"
#define aMayusc(X) (X)>='a'&&(X)<='z'?(X)-32:(X)
#define aMinusc(X) (X)>='A'&&(X)<='Z'?(X)+32:(X)

char * str_chr(const char* cbus,int c)
{
    while(*cbus&&*cbus!=c)
        cbus++;
    return *cbus==c?cbus:NULL;
}

int str_cmp (const char* cad1,const char* cad2)
{
    while(*cad1&&*cad2&&!(*cad1-*cad2))
    {
        cad1++;
        cad2++;
    }
    return *cad1-*cad2;
}
int str_cmpi(const char* cad1,const char* cad2)
{
    while(*cad1&&*cad2&&!((aMinusc(*cad1))-(aMinusc(*cad2))))
    {
        cad1++;
        cad2++;
    }
    return ((aMinusc(*cad1))-(aMinusc(*cad2)));
}

int str_ncmp(const char* c1, const char* c2,int cmax)
{
    while(cmax>0&&*c1&&*c2&&!(*c1-*c2))
    {
        c1++;
        c2++;
        cmax--;
    }
    return *c1-*c2;
}

char * str_str (const char* cad, const char* subcad)
{
    char* caux=cad,*saux=subcad;
    int largo=0,ccoinc=0;
    if(!*cad||!*subcad)
        return NULL;
    while(*subcad)
    {
        subcad++;
        largo++;
    }
    subcad=saux;
    while(caux&&*cad)
    {
        caux=cad;
        while(*cad==*subcad&&ccoinc!=largo&&*cad&&*subcad)
        {
            ccoinc++;
            cad++;
            subcad++;
            if(ccoinc==largo)
                return cad-ccoinc;
            if(*cad!=*subcad)
            {
                cad=caux+1;
                caux++;
                ccoinc=0;
                subcad=saux;
            }
        }
        cad++;
    }
    return NULL;
}
char * str_cat (char* cad1,const char* cad2)
{
    char* aux=cad1;
    if(!*cad2)
        return cad1;
    while(*cad1)
        cad1++;
    while(*cad2)
    {
        *cad1=*cad2;
        cad1++;
        cad2++;
    }
    *cad1='\0';
    return aux;
}

char * str_cpy (char* cad1,const char* cad2)
{
    char* aux=cad1;
    while(*cad2)
    {
        *cad1=*cad2;
        cad1++;
        cad2++;
    }
    *cad1='\0';
    return aux;
}

int str_len (const char* cad)
{
    int c=0;
    while(*cad)
    {
        c++;
        cad++;
    }
    return c;
}

char * str_upr (char* cad)
{
    char* caux=cad;
    while(*cad)
    {
        *cad=aMayusc(*cad);
        cad++;
    }
    return caux;
}

char * str_lwr (char* cad)
{
    char* caux=cad;
    while(*cad)
    {
        *cad=aMinusc(*cad);
        cad++;
    }
    return caux;
}
