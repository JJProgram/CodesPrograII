#ifndef FCUSADAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FcPilaEstatica.h"
#define FCUSADAS_H_INCLUDED
#define esNumero(x)((x)>='0'&&(x)<='9')
#define esFinPila(x)((x)=='#')
#define CON_MSJ 1

int abrirArchivo (FILE** ,char* ,char* ,int );
void archivarSuma(int ,FILE* );
int sumarPilas(t_pila* ,t_pila* ,FILE* );
int cargarySumarPilas (void);

#endif // FCUSADAS_H_INCLUDED
