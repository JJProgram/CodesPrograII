#ifndef FCEJERCICIO_H_INCLUDED
#define FCEJERCICIO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
// REGISTRO ARCHIVO
typedef struct
{
    char nombreArt[20];
    float cantAct;
}t_reg;

// ESTRUCTURAS LISTA
typedef struct
{
    char codRubro;
    float cantTotRubro;
}t_infoL;
typedef struct s_nodoL
{
    struct s_nodoL* ant;
    t_infoL info;
    struct s_nodoL* sig;
}t_nodoL;
typedef t_nodoL* t_lista;
// ESTRUCTURAS ARBOL
typedef struct
{
    int codArticulo;
    char codRubro;
    float cantidad;
}t_infoA;
typedef struct s_nodoA
{
    struct s_nodoA* izq;
    t_infoA info;
    struct s_nodoA* der;
}t_nodoA;
typedef t_nodoA* t_arbol;

// Funciones extra
void crearLista(t_lista* );
void crearArbol(t_arbol* );
int compararL(const t_infoA* ,const t_infoA* );
int compararA(const t_infoA* ,const t_infoA* );
int insertarEnArbol(t_arbol* ,t_infoA* );
void eliminarArbol(t_arbol* );
int abrirArchivo(FILE** ,const char* ,const char* ,int );
void vaciarLista(t_lista* );
void mostrarLista(t_lista* );
void inicializarArbol(t_arbol* );
void mostrarContenidoBinario(FILE** );
void mostrarPreOrden(t_arbol* );
// Funciones oficiales
int ponerEnListaDobleOrd(t_lista* ,const t_infoA* );
void actualizarArchivo(FILE** ,const t_infoA* );
int procesarAlturaArbol(FILE** ,t_arbol* ,t_lista* ,int );

#endif // FCEJERCICIO_H_INCLUDED
