#include "FcArbol.h"

int comparar(t_info* d1,t_info* d2)
{
    return (d1->clave - d2->clave);
}
void mostrarDato(t_info* d)
{
    printf("%d\n",d->clave);
}
void crearArbol(t_arbol* pa)
{
    *pa=NULL;
}
int insertarNodoRec(t_arbol* pa,t_info* d)
{
    int cmp;
    if(*pa)
    {
        if((cmp=comparar(d,&(*pa)->info))==0)
            return CLAVE_DUPLICADA;
        if(cmp>0)
            return insertarNodoRec(&(*pa)->der,d);
        else
            return insertarNodoRec(&(*pa)->izq,d);
    }
    *pa=(t_nodo*)malloc(sizeof(t_nodo));
    if(!*pa)
        return 0;//SIN MEMORIA
    (*pa)->izq=NULL;
    (*pa)->der=NULL;
    (*pa)->info=*d;
    return 1;
}
int insertarNodoIt(t_arbol* pa,t_info* d)
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
    *pa=(t_nodo*)malloc(sizeof(t_nodo));
    if(!*pa)
        return 0;//SIN MEMORIA
    (*pa)->izq=NULL;
    (*pa)->der=NULL;
    (*pa)->info=*d;
    return 1;
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
void inOrdenR(t_arbol* pa)
{
    if(*pa)
    {
        inOrdenR(&(*pa)->izq);
        mostrarDato(&(*pa)->info);
        inOrdenR(&(*pa)->der);
    }
}
void posOrdenR(t_arbol* pa)
{
   if(*pa)
    {
        posOrdenR(&(*pa)->izq);
        posOrdenR(&(*pa)->der);
        mostrarDato(&(*pa)->info);
    }
}
void guardarArbolEnArchivo(t_arbol* pa,FILE** ppf)
{
    if(*pa)
    {
        fwrite(&(*pa)->info,sizeof(t_info),1,*ppf);
        guardarArbolEnArchivo(&(*pa)->izq,ppf);
        guardarArbolEnArchivo(&(*pa)->der,ppf);
    }
}
int cargarArbolDeArchivo(t_arbol* pa,FILE** ppf)
{
    t_info aux;
    fread(&aux,sizeof(t_info),1,*ppf);
    while(!feof(*ppf))
    {
        if(!insertarNodoIt(pa,&aux))
           return 0;//No habia memoria y no pudo insertar el dato
        fread(&aux,sizeof(t_info),1,*ppf);
    }
    return 1; //Todo bien
}
t_nodo* buscarDirNodoyDatoIt(t_arbol* pa,t_info* d)
{
    int cmp;
    while(*pa)
    {
        cmp=comparar(d,&(*pa)->info);
        if(cmp==0)
        {
            *d=(*pa)->info;
            return *pa;
        }
        if(cmp>0)
            pa=&(*pa)->der;
        else
            pa=&(*pa)->izq;
    }
    return NULL;
}
t_nodo* buscarDirNodoyDatoR(t_arbol* pa,t_info* d)
{
    int cmp;
    if(*pa)
    {
        cmp=comparar(d,&(*pa)->info);
        if(cmp==0)
        {
            *d=(*pa)->info;
            return *pa;
        }
        if(cmp>0)
            buscarDirNodoyDatoR(&(*pa)->der,d);
        else
            buscarDirNodoyDatoR(&(*pa)->izq,d);
    }
    return NULL;
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
int contarNodos(t_arbol* pa)
{
        return *pa?contarNodos(&(*pa)->izq)+contarNodos(&(*pa)->der)+1:0;
}
int contarHojas(t_arbol* pa)
{
    if(*pa) //tambien se puede usar (*pa)->izq==(*pa)->der pero esto es mas claro
        return (*pa)->izq==NULL&&(*pa)->der==NULL?1:contarHojas(&(*pa)->izq)+contarHojas(&(*pa)->der);
    return 0;
}
int contaryMostrarHojas(t_arbol* pa)
{
    if(*pa)
    {
        if((*pa)->izq==(*pa)->der)
        {
            mostrarDato(&(*pa)->info);
            return 1;
        }
        else
            return contaryMostrarHojas(&(*pa)->izq)+contaryMostrarHojas(&(*pa)->der);
    }
    return 0;
}
int contarNoHojas(t_arbol* pa)
{
    if(*pa) //igual que en ContarHojas, podria usar (*pa)->izq==(*pa)->der pero no es tan claro como esta forma
        return (*pa)->izq==NULL&&(*pa)->der==NULL?0:1+contarNoHojas(&(*pa)->izq)+contarNoHojas(&(*pa)->der);
    return 0;
}
int contarNodosConHijosIzq(t_arbol* pa)
{
    if(*pa)
        return ((*pa)->izq==NULL?0:1)+contarNodosConHijosIzq(&(*pa)->izq)+contarNodosConHijosIzq(&(*pa)->der);
    return 0;
}
int contarNodosSoloHijosDer(t_arbol* pa)
{
    if(*pa)
        return ((*pa)->izq==NULL&&(*pa)->der!=NULL?1:0)+contarNodosSoloHijosDer(&(*pa)->izq)+contarNodosSoloHijosDer(&(*pa)->der);
    return 0;
}
int contarNodosClavePar(t_arbol* pa)
{
    if(*pa)
        return ((*pa)->info.clave%2==0?1:0)+contarNodosClavePar(&(*pa)->izq)+contarNodosClavePar(&(*pa)->der);
    return 0;
}
int contarNodosSubArbolIzq(t_arbol* pa)
{
    return (*pa)?contarNodos(&(*pa)->izq):0;
}
