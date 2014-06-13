#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 100
#define aMayusc(x)((x)>='a'&&(x)<='z'?(x)-32:(x))
typedef struct
{
    char num;
}t_info;
typedef struct s_nodo
{
    t_info info;
    struct s_nodo *sig;
}t_nodo;
typedef t_nodo* t_pila;

int selecSimp(void);
void crearPila(t_pila* );
int apilar(t_pila* ,t_info* );
int desapilar (t_pila* ,t_info* );
char* convertirDec(int ,int );
int main()
{
    char *numeroRes;
    int numero,base;
    base=selecSimp();
    while(base!='S')
    {
        printf("Ingrese el numero a convertir: ");
        scanf("%d",&numero);
        if(numero<0)
            numero=-numero;
        numeroRes=convertirDec(numero,base);
        printf("\"%d\" (10) = \"%s\" (%d)\n",numero,numeroRes,base);
        printf("Presione una tecla para continuar...");
        getch();
        system("cls");
        base=selecSimp();
    }
    return 1;
}
int selecSimp(void)
{
    char opciones[]={"BOHS"},base;
    do
    {
       printf("Menu de opciones:\n"
           "B- Convertir decimal a Base 2\n"
           "O- Convertir decimal a Base 8\n"
           "H- Convertir decimal a Base 16\n"
           "S- Salir\n"
           "Ingrese la opcion deseada: ");
        scanf("%c",&base);
        base=aMayusc(base);
        system("cls");
    }while(!strchr(opciones,base));
    return (base=='B'?2:(base=='O'?8:base=='S'?'S':16));
}
void crearPila(t_pila* p)
{
    *p=NULL;
}
int apilar(t_pila* p,t_info* d)
{
    t_nodo* nue=(t_nodo*)malloc(sizeof(t_nodo));
    if(!nue)
        return 0;
    nue->info=*d;
    nue->sig=*p;
    *p=nue;
    return 1;
}
int desapilar (t_pila* p,t_info* d)
{
    t_nodo* aux;
    if(!*p)
        return 0;
    aux=*p;
    *d=aux->info;
    *p=aux->sig;
    free(aux);
    return 1;
}
char* convertirDec(int num,int base)
{
    const char valNum[]={"0123456789ABCDEF"};
    char* cfinal,*aux;
    int contdigitos=0;
    t_info resparcial;
    t_pila pila;
    crearPila(&pila);
    if(num==0)
    {
        cfinal=(char*)malloc(sizeof(char));
        *cfinal='0';
        return cfinal;
    }
    while(num!=0)
    {
        resparcial.num=valNum[num%base];
        num=num/base;
        if(!apilar(&pila,&resparcial))
           return NULL;
        contdigitos++;
    }
    cfinal=(char*)malloc(sizeof(char)*(contdigitos+1)); //+1 por el \0
    aux=cfinal;
    while(desapilar(&pila,&resparcial))
    {
        *aux=resparcial.num;
        aux++;
    }
    *aux='\0';
    return cfinal;
}
