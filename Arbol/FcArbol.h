#ifndef FCARBOL_H_INCLUDED
#define FCARBOL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define CLAVE_DUPLICADA -1

/*Nota: Los arboles que utilizamos son arboles binarios de busqueda. Por ende,
 cada nodo tiene 2 hijos como maximo, los elementos menores van a la izquierda,
 los mayores a la derecha y si el elemento ya fue insertado se lo descarta.

 De las funciones de insercion, la Iterativa acaba siendo mejor que la recursiva

 Se incluyeron funciones necesarias para las funciones principales, como mostrarDato
 y comparar.*/
typedef struct
{
    int clave;
}t_info;
typedef struct s_nodo
{
    struct s_nodo *izq;
    t_info info;
    struct s_nodo *der;
}t_nodo;
typedef t_nodo* t_arbol;

int comparar(t_info* ,t_info* );
void mostrarDato(t_info* );
void crearArbol(t_arbol* );
int insertarNodoRec(t_arbol* ,t_info* );
int insertarNodoIt(t_arbol* ,t_info* );
void preOrdenR(t_arbol* );
void inOrdenR(t_arbol* );
void posOrdenR(t_arbol* );
void guardarArbolEnArchivo(t_arbol* ,FILE** );
int cargarArbolDeArchivo(t_arbol* ,FILE** );
t_nodo* buscarDirNodoyDatoIt(t_arbol* ,t_info* );
t_nodo* buscarDirNodoyDatoR(t_arbol* ,t_info* );
void eliminarArbol(t_arbol* );
int contarNodos(t_arbol* );
int contarHojas(t_arbol* );
int contaryMostrarHojas(t_arbol* );
int contarNodosConHijosIzq(t_arbol* );
int contarNodosSoloHijosDer(t_arbol* );
#endif // FCARBOL_H_INCLUDED
