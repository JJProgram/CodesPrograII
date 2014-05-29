#include "FcPilaEstatica.h"
void crearPila (t_pila* p)
{
    p->tope=0;
}

int pilaVacia (t_pila* p)
{
    return (p->tope == 0);
}

int pilaLlena (t_pila* p)
{
    return (p->tope == TAM);
}

int apilar (t_pila* p,const t_info* d)
{
    if(p->tope==TAM)
        return 0;
    p->pila[p->tope] = *d;
    p->tope++;
    return 1;
}

int desapilar (t_pila* p,t_info* d)
{
    if(p->tope == 0)
        return 0;
    p->tope--;
    *d=p->pila[p->tope];
    return 1;
}

int verTope (t_pila* p,t_info* d)
{
    if(p->tope == 0)
        return 0;
    *d=p->pila[(p->tope)-1];
    return 1;
}

int vaciarPila (t_pila* p)
{
    p->tope=0;
}
