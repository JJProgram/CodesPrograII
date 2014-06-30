#ifndef EJARBOL+LISTA_H_INCLUDED
#define EJARBOL+LISTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    long int nProd;
    long int stock;
}t_infoA;
typedef struct
{
    t_infoA info;
    int nivelNodo;
}t_infoL;
typedef struct s_nodoA
{
    struct s_nodoA* izq;
    t_infoA info;
    struct s_nodoA* der;
}t_nodoA;
typedef struct s_nodoL
{
    struct s_nodoL* ant;
    t_infoL info;
    struct s_nodoL*sig;
}t_nodoL;
typedef t_nodoA* t_arbol;
typedef t_nodoL* t_lista;
// FC Genericas
void mostrarDato(t_infoA* d);
int comparar(t_infoA* ,t_infoA* );
// FC Arbol
void crearArbol(t_arbol* );
int insertarNodoIt(t_arbol* ,t_infoA* );
int cargarArbolDeArchivo(t_arbol* ,FILE** );
void eliminarArbol(t_arbol* );
void preOrdenR(t_arbol* );
// FC Lista Doble + Arbol
void crearLista(t_lista* );
int insOptimaEnListaDobleOrd(t_lista* ,t_infoL* );
int arbolAListaDoble(t_arbol* ,t_lista* ,int );
void mostrarListaDoble(t_lista* );
void vaciarLista(t_lista* );

#endif // EJARBOL+LISTA_H_INCLUDED
