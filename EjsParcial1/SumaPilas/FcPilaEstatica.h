#ifndef FCPILAESTATICA_H_INCLUDED
#define FCPILAESTATICA_H_INCLUDED
#define TAM 100000
typedef struct
{
    int num;
}t_info;
typedef struct
{
    t_info pila [TAM];
    int tope;
}t_pila;

void crearPila (t_pila* );
int pilaVacia (t_pila* );
int pilaLlena (t_pila* );
int apilar (t_pila* ,const t_info* );
int desapilar (t_pila* ,t_info* );
int verTope (t_pila* ,t_info* );
int vaciarPila (t_pila* );
#endif // FCPILAESTATICA_H_INCLUDED
