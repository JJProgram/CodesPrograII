#include "FcEjercicio.h"
#define CLAVE_DUPLICADA -1

//FUNCIONES GENERICAS
void mostrarDato(t_infoA* d)
{
    printf("Nro Producto: %ld|Stock: %ld\n",d->nProd,d->stock);
}
int comparar(t_infoA* d1,t_infoA* d2)
{
    return (d1->nProd - d2->nProd);
}

// FUNCIONES ARBOL

void crearArbol(t_arbol* pa)
{
    *pa=NULL;
}
int insertarNodoIt(t_arbol* pa,t_infoA* d)
{
    int cmp;
    while(*pa)
    {
        if((cmp=comparar(d,&(*pa)->info))==0)
            return CLAVE_DUPLICADA;
        if(cmp>0)
            pa=&(*pa)->der;
        else
            pa=&(*pa)->izq;
    }
    *pa=(t_nodoA*)malloc(sizeof(t_nodoA));
    if(!*pa)
        return 0;//SIN MEMORIA
    (*pa)->izq=NULL;
    (*pa)->der=NULL;
    (*pa)->info=*d;
    return 1;
}
int cargarArbolDeArchivo(t_arbol* pa,FILE** ppf)
{
    t_infoA aux;
    fread(&aux,sizeof(t_infoA),1,*ppf);
    while(!feof(*ppf))
    {
        if(!insertarNodoIt(pa,&aux))
           return 0;//No habia memoria y no pudo insertar el dato
        fread(&aux,sizeof(t_infoA),1,*ppf);
    }
    return 1; //Todo bien
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
void preOrdenR(t_arbol* pa)
{
    if(*pa)
    {
        mostrarDato(&(*pa)->info);
        preOrdenR(&(*pa)->izq);
        preOrdenR(&(*pa)->der);
    }
}

// FUNCIONES LISTA DOBLE
void crearLista(t_lista* p)
{
    *p=NULL;
}
int insOptimaEnListaDobleOrd(t_lista* p,t_infoL* d)
{
    t_nodoL* nue;
    nue=(t_nodoL*)malloc(sizeof(t_nodoL));
    if(!nue)
        return 0; //SIN MEMORIA
    nue->info=*d;
    nue->sig=*p;
    if(*p)
        (*p)->ant=nue;
    else
        nue->ant=*p;
    *p=nue;
    return 1; //todo bien
}
int arbolAListaDoble(t_arbol* pa,t_lista* p,int niv)
{
    /*Es mejor Inorden inverso ya que obtengo los nodos del arbol de mayor a menor,
    lo que luego me permite guardarlos en la lista doble hacia la "izquierda"
    (nue<->39<->40<->41) y cada vez que guardo 1 nodo, la lista queda apuntando
    a ese nodo. De esa forma, al mostrar, buscar o mostrar, solamente tengo que
    recorrer hacia la "derecha" (nodo1<->nodo2<->nodo3)*/
    t_infoL aux;
    if(*pa)
    {
        aux.info=(*pa)->info;
        aux.nivelNodo=niv;
        arbolAListaDoble(&(*pa)->der,p,niv+1);
        if(!insOptimaEnListaDobleOrd(p,&aux))
            return -1; //no habia memoria
        arbolAListaDoble(&(*pa)->izq,p,niv+1);
        return 1; //todo bien
    }
    return 0; // no hay nodos
}
void mostrarListaDoble(t_lista* p)
{
    printf("Lista:\n");
    while(*p)
    {
        printf("Nro producto: %ld | Stock: %ld | Nivel: %d\n",(*p)->info.info.nProd,(*p)->info.info.stock,(*p)->info.nivelNodo);
        p=&(*p)->sig;
    }
}
void vaciarLista(t_lista* p)
{
    t_nodoL* aux;
    while(*p)
    {
        aux=*p;
        printf("Vaciando-> Nro producto: %ld | Stock: %ld | Nivel: %d\n",(*p)->info.info.nProd,(*p)->info.info.stock,(*p)->info.nivelNodo);
        *p=aux->sig; // *p=(*p)->sig
        free(aux);
    }
    *p=NULL;
}
