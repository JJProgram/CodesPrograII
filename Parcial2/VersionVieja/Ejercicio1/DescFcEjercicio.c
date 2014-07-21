#include "FcEjercicio.h"
int comparar(const char* c1,const char* c2)
{
    return c1 - c2;
}
int abrirArchivo(FILE** ppf,char* ruta, char* modo, int msj)
{
    *ppf=fopen(ruta,modo);
    if(!*ppf)
    {
        if(msj==1)
            printf("ERROR: No se pudo abrir el archivo %s en modo %s\n",ruta,modo);
        return 0;
    }
    return 1;
}
int ponerEnListaDobleOrd(t_lista* pl,t_infoA* infoArbol)
{
    t_nodoL* nue;
    t_nodoL* act=*pl;
    int cmp;
    if(act)
    {
        while(act->sig&&(cmp=comparar(&(act->sig->info.codRubro),&(infoArbol->codRubro)))>0)
            act=&(act)->sig;
        while(act->ant&&(cmp=comparar(&(act->ant->info.codRubro),&(infoArbol->codRubro)))<0)
            act=&(act)->ant;
        if(cmp==0)
        {
            (act)->info.cantTotRubro+=infoArbol->cantidad; //duplicado, caso de acumulacion
            return -1;
        }
    }
    nue=(t_nodoL*)malloc(sizeof(t_nodoL));
    if(!nue)
        return 0; // sin memoria
    nue->info.codRubro=infoArbol->codRubro;
    nue->info.cantTotRubro=infoArbol->cantidad;
    if(cmp<0)
    {
        nue->sig=act;
        nue->ant=act->sig;
    }
    else
    {
        nue->sig=act->sig;
        nue->ant=act;
    }
    if(act==NULL)
    {
        nue->ant=NULL;
        nue->sig=NULL;
        *pl=nue;
    }
    return 1;
}
void actualizarArchivo(FILE** ppf,t_infoA* infoArbol)
{
    t_reg aux;
    fseek(*ppf,((infoArbol->codArticulo)-1)*sizeof(t_reg),SEEK_SET);
    if(!feof(*ppf))
    {
        fread(&aux,sizeof(t_reg),1,*ppf);
        fseek(*ppf,-1L*sizeof(t_reg),SEEK_CUR);
        fseek(*ppf,0,SEEK_CUR);
        aux.cantAct+=(infoArbol->cantidad);
        fwrite(&aux,sizeof(t_reg),1,*ppf);
    }
}
int procesarNodosXAltura(FILE** ppf,t_arbol* pa,t_lista* pl,int* alt,int altAct)
{
    if(*pa)
    {
        if(altAct==alt)
        {
            if(!ponerEnListaDobleOrd(pl,&(*pa)->info))
                return 0;
            actualizarArchivo(ppf,&(*pa)->info);
            return 1;
        }
        else
            return procesarNodosXAltura(ppf,&(*pa)->izq,pl,alt,altAct+1)+procesarNodosXAltura(ppf,&(*pa)->der,pl,alt,altAct+1);
    }
    return 0;
}
int insertarenArbolIt(t_arbol* pa,t_infoA* d)
{
    int cmp;
    while(*pa)
    {
        if((cmp=comparar(d->codRubro,&(*pa)->info.codRubro))==0)
            return -1; // DUPLICADO
        if(cmp<0)
            pa=&(*pa)->izq;
        else
            pa=&(*pa)->der;
    }
    *pa=(t_nodoA*)malloc(sizeof(t_nodoA));
    if(!*pa)
        return 0;
    (*pa)->izq=NULL;
    (*pa)->der=NULL;
    (*pa)->info=*d;
    return 1;
}
int archivoAArbol(FILE**ppf, t_arbol* pa)
{
    t_infoA auxA;
    int cont=0;
    rewind(*ppf);
    fread(&auxA,sizeof(t_infoA),1,*ppf);
    while(!feof(*ppf))
    {
        if(!insertarenArbolIt(pa,&auxA))
            return 0; // sin memoria al insertar en arbol
        cont++;
        fread(&auxA,sizeof(t_infoA),1,*ppf);
    }
    return cont;
}
void crearListaDoble(t_lista* pl)
{
    *pl=NULL;
}
void crearArbol(t_arbol* pa)
{
    *pa=NULL;
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
void mostrarArbol(t_arbol* pa)
{
    if(*pa)
    {
        printf("%d || %c || %f\n",(*pa)->info.codArticulo,(*pa)->info.codRubro,(*pa)->info.cantidad);
        mostrarArbol(&(*pa)->izq);
        mostrarArbol(&(*pa)->der);
    }
}
