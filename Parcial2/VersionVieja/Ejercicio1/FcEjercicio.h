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
    struct s_nodo* izq;
    t_infoA info;
    struct s_nodo* der;
}t_nodoA;
typedef t_nodoA* t_arbol;

int comparar(const char* ,const char* );
int abrirArchivo(FILE** ,char* , char* , int );
int ponerEnListaDobleOrd(t_lista* ,t_infoA* );
void actualizarArchivo(FILE** ,t_infoA* );
int procesarNodosXAltura(FILE** ,t_arbol* ,t_lista* ,int* ,int);
int insertarenArbolIt(t_arbol* ,t_infoA* );
int archivoAArbol(FILE** ,t_arbol* );
void crearListaDoble(t_lista* );
#endif // FCEJERCICIO_H_INCLUDED
