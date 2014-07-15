#include "FcEjercicio.h"
int comparar(const t_reg* d1, const t_reg* d2)
{
    return (d1->clave - d2->clave);
}
int abrirArchivo(FILE** ppf,char* ruta,char* modo,int msj)
{
    *ppf=fopen(ruta,modo);
    if(!*ppf)
    {
        if(msj == 1)
            printf("ERROR: No se pudo abrir %s en modo %s",ruta,modo);
        return 0;
    }
    return 1;
}
void crearColaCircular(t_cola* pc)
{
    *pc=NULL;
}
int ponerEnColaCircular(t_cola* pc,const t_reg* d)
{
    t_nodoC* nue=(t_nodoC*)malloc(sizeof(t_nodoC));
    if(!nue)
        return 0; //sin memoria
    nue->info=*d;
    if(*pc==NULL)
        nue->sig=nue;
    else
    {
        nue->sig=(*pc)->sig;
        (*pc)->sig=nue;
    }
    *pc=nue;
    printf("%d || %c\n",nue->info.clave,nue->info.info.letra);
    return 1; // todo bien
}
int sacardeColaCircular(t_cola* pc,t_reg* d)
{
    t_nodoC* aux;
    if(*pc==NULL)
        return 0; // cola vacia
    aux=(*pc)->sig;
    *d=aux->info;
    if(*pc==aux)
        *pc=NULL;
    else
        (*pc)->sig=aux->sig;
    free(aux);
    return 1;
}
void vaciarCola(t_cola* pc)
{
    t_nodoC* aux;
    while(*pc)
    {
        aux=(*pc)->sig;
        if(*pc==aux)
            *pc=NULL;
        else
            (*pc)->sig=aux->sig;
        free(aux);
    }
}
void crearArbol(t_arbol* pa)
{
    *pa=NULL;
}
int insertarEnArbolIt(t_arbol* pa,const t_reg* d)
{
    int cmp;
    while(*pa)
    {
        if((cmp=comparar(d,&(*pa)->info))==0)
            return -1; // DUPLICADO
        if(cmp<0)
            pa=&(*pa)->izq;
        else
            pa=&(*pa)->der;
    }
    *pa=(t_nodoA*)malloc(sizeof(t_nodoA));
    if(!*pa)
        return 0; // sin memoria
    (*pa)->info=*d;
    (*pa)->izq=NULL;
    (*pa)->der=NULL;
    return 1;
}
void mostrarArbolInOrden(t_arbol* pa)
{
    if(*pa)
    {
        mostrarArbolInOrden(&(*pa)->izq);
        printf("Clave: %d || Info: %c\n",(*pa)->info.clave,(*pa)->info.info.letra);
        mostrarArbolInOrden(&(*pa)->der);
    }
}
void arbolAArchivo(FILE** ppf,t_arbol* pa)
{
    if(*pa)
    {
        fwrite(&(*pa)->info,sizeof(t_reg),1,*ppf);
        arbolAArchivo(ppf,&(*pa)->izq);
        arbolAArchivo(ppf,&(*pa)->der);
    }
}
int archivoAArbol(FILE** ppf,t_arbol* pa)
{
    t_reg aux;
    fseek(*ppf,0,SEEK_SET);
    fread(&aux,sizeof(t_reg),1,*ppf);
    while(!feof(*ppf))
    {
        if(!insertarEnArbolIt(pa,&aux))
            return 0; // fallo por no haber memoria
        fread(&aux,sizeof(t_reg),1,*ppf);
    }
    return 1;
}
void eliminarArbol(t_arbol* pa)
{
    if(*pa)
    {
        eliminarArbol(&(*pa)->izq);
        eliminarArbol(&(*pa)->der);
        free(*pa);
        *pa=NULL;
    }
}
int fcCentral(t_arbol* pa,t_cola* pc)
{
    if(*pa)
    {
        if((*pa)->izq==NULL&&(*pa)->der==NULL&&((*pa)->info.clave%2)==0)
        {

            if(!ponerEnColaCircular(pc,&(*pa)->info))
                return 0;
            return (1 + fcCentral((*pa)->izq,pc) + fcCentral((*pa)->der,pc));
        }
        else
            return (fcCentral((*pa)->izq,pc) + fcCentral((*pa)->der,pc));
    }
    return 0;
}
int hojasParesAColaCircular(t_arbol* pa, t_cola* pc)
{
    return ((*pa)?fcCentral(&(*pa)->der,pc):0);
}
