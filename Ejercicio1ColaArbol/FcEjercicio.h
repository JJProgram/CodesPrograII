#ifndef FCEJERCICIO_H_INCLUDED
#define FCEJERCICIO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char letra;
}t_info;
typedef struct
{
    int clave;
    t_info info;
}t_reg;
typedef struct s_nodoC
{
    t_reg info;
    struct s_nodoC* sig;
}t_nodoC;
typedef struct s_nodoA
{
    struct s_nodoA* izq;
    t_reg info;
    struct s_nodoA* der;
}t_nodoA;
typedef t_nodoC* t_cola;
typedef t_nodoA* t_arbol;

int comparar(const t_reg* , const t_reg* );
int abrirArchivo(FILE** ,char* ,char* ,int );
void crearColaCircular(t_cola* );
int ponerEnColaCircular(t_cola* ,const t_reg* );
int sacardeColaCircular(t_cola* ,t_reg* );
void vaciarCola(t_cola* );
void crearArbol(t_arbol* );
int insertarEnArbolIt(t_arbol* ,const t_reg* );
void mostrarArbolInOrden(t_arbol* );
void arbolAArchivo(FILE** ,t_arbol* );
int archivoAArbol(FILE** ,t_arbol* );
void eliminarArbol(t_arbol* );
int fcCentral(t_arbol* ,t_cola* );
int fcCentral(t_arbol* , t_cola* );
int hojasParesAColaCircular(t_arbol* , t_cola* );

#endif // FCEJERCICIO_H_INCLUDED
