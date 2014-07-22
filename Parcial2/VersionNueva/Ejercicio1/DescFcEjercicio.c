#include "FcEjercicio.h"

void crearLista(t_lista* pl)
{
    *pl=NULL;
}
void crearArbol(t_arbol* pa)
{
    *pa=NULL;
}
int compararL(const t_infoA* d1,const t_infoA* d2)
{
    return (d1->codRubro - d2->codRubro);
}
int compararA(const t_infoA* d1,const t_infoA* d2)
{
    return (d1->codArticulo - d2->codArticulo);
}
int insertarEnArbol(t_arbol* pa,t_infoA* d)
{
    int cmp;
    while(*pa)
    {
        if((cmp=compararA(d,&(*pa)->info))==0)
            return -1; //duplicado
        if(cmp>0)
            pa=&(*pa)->der;
        else
            pa=&(*pa)->izq;
    }
    *pa=(t_nodoA*)malloc(sizeof(t_nodoA));
    if(!*pa)
        return 0;
    (*pa)->info=*d;
    (*pa)->izq=NULL;
    (*pa)->der=NULL;
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
int abrirArchivo(FILE** ppf,const char* ruta,const char* modo,int msj)
{
    *ppf=fopen(ruta,modo);
    if(!*ppf)
    {
        if(msj==1)
            printf("ERROR: No se pudo abrir %s en modo %s\n",ruta,modo);
        return 0;
    }
    printf("Apertura de %s en modo %s exitosa\n",ruta,modo);
    return 1;
}
void vaciarLista(t_lista* pl)
{
    t_nodoL* aux;
    while(*pl&&(*pl)->ant)
        *pl=(*pl)->ant;
    while(*pl)
    {
        aux=*pl;
        *pl=aux->sig;
        free(aux);
    }
}
void mostrarLista(t_lista* pl)
{
    int cont=0;
    while(*pl&&(*pl)->ant)
        pl=&(*pl)->ant;
    while(*pl)
    {
        printf("Nodo %d || Rubro: %c || Cant: %f\n",cont+1,(*pl)->info.codRubro,(*pl)->info.cantTotRubro);
        pl=&(*pl)->sig;
        cont++;
    }
}
void inicializarArbol(t_arbol* pa)
{
    //esta funcion solo esta para no hacer el ingreso a mano de cada nodo;
    t_infoA aux;
    aux.codArticulo=5;
    aux.codRubro='m';
    aux.cantidad=15;
    insertarEnArbol(pa,&aux);
    aux.codArticulo=3;
    aux.codRubro='l';
    aux.cantidad=9;
    insertarEnArbol(pa,&aux);
    aux.codArticulo=1;
    aux.codRubro='j';
    aux.cantidad=2;
    insertarEnArbol(pa,&aux);
    aux.codArticulo=5;
    aux.codRubro='m';
    aux.cantidad=15;
    insertarEnArbol(pa,&aux);
    aux.codArticulo=7;
    aux.codRubro='l';
    aux.cantidad=10;
    insertarEnArbol(pa,&aux);
    aux.codArticulo=6;
    aux.codRubro='i';
    aux.cantidad=18;
    insertarEnArbol(pa,&aux);
    aux.codArticulo=8;
    aux.codRubro='j';
    aux.cantidad=200;
    insertarEnArbol(pa,&aux);
}
void mostrarContenidoBinario(FILE** ppf)
{
    t_reg aux;
    int cont=0;
    rewind(*ppf);
    printf("Contenido de stock.bin:\n");
    fread(&aux,sizeof(t_reg),1,*ppf);
    while(!feof(*ppf))
    {
        printf("Registro %d -> %s || %f\n",cont+1,aux.nombreArt,aux.cantAct);
        fread(&aux,sizeof(t_reg),1,*ppf);
        cont++;
    }
    printf("Fin de stock.bin\n");
}
void mostrarPreOrden(t_arbol* pa)
{
    if(*pa)
    {
        printf("CodArticulo: %d || CodRubro: %c || Cantidad: %f\n",(*pa)->info.codArticulo,(*pa)->info.codRubro,(*pa)->info.cantidad);
        mostrarPreOrden(&(*pa)->izq);
        mostrarPreOrden(&(*pa)->der);
    }
}
int ponerEnListaDobleOrd(t_lista* pl,const t_infoA* d)
{
    t_nodoL* nue,*act=*pl,*ant;
    int cmp;
    if(act)
    {
        while(act->sig&&(cmp=compararL(d,&act->info))>0)
            act=act->sig;
        while(act->ant&&(cmp=compararL(d,&act->info))<0)
            act=act->ant;
        if((cmp=compararL(d,&act->info))==0) // duplicados
        {
            act->info.cantTotRubro+=d->cantidad;
            return -1;
        }
        if(cmp>0)
        {
            ant=act;
            act=act->sig;
        }
        else
            ant=act->ant;
    }
    else
        ant=NULL;
    nue=(t_nodoL*)malloc(sizeof(t_nodoL));
    if(!nue)
        return 0; // sin memoria
    nue->info.cantTotRubro=d->cantidad;
    nue->info.codRubro=d->codRubro;
    nue->ant=ant;
    nue->sig=act;
    if(act)
        act->ant=nue;
    if(ant)
        ant->sig=nue;
    *pl=nue;
    return 1; //todo bien
}

void actualizarArchivo(FILE** ppf,const t_infoA* d)
{
    t_reg aux;
    fseek(*ppf,(d->codArticulo-1)*sizeof(t_reg),SEEK_SET);
    fread(&aux,sizeof(t_reg),1,*ppf);
    fseek(*ppf,-1L*sizeof(t_reg),SEEK_CUR); //reposicionar puntero para escritura.
    fseek(*ppf,0,1); //reorientar puntero
    //las 2 lineas de arriba son reemplazables por el fseek del principio
    aux.cantAct+=d->cantidad;
    fwrite(&aux,sizeof(t_reg),1,*ppf);
}
int procesarAlturaArbol(FILE** ppf,t_arbol* pa,t_lista* pl,int alt)
{
    if(*pa)
    {
        if(alt==1)
        {
            if(!ponerEnListaDobleOrd(pl,&(*pa)->info))
                return 0;
            actualizarArchivo(ppf,&(*pa)->info);
            return 1;
        }
        return (procesarAlturaArbol(ppf,&(*pa)->izq,pl,alt-1)+procesarAlturaArbol(ppf,&(*pa)->der,pl,alt-1));
    }
    return 0;
}

