#include <stdio.h>
#include <stdlib.h>
#include "FcPilaEstatica.h"
#define CON_MSJ 1
int selecsimp(void);
int cargarDato(t_info* );
void mostrarDato(t_info* );
int abrirArchivo (FILE** ,char* ,char* ,int );

int main()
{
    t_pila pila;
    t_info dato;
    int op,seguir=1;
    op=selecsimp();
    crearPila(&pila);
    while(op!=7)
    {
        switch(op)
        {
            case 1: /*Apilar*/
            while(seguir&&cargarDato(&dato)) //no quiero que siga si el usuario lo dice o la pila se lleno
            {
                seguir=apilar(&pila,&dato);
                printf("El dato %s",seguir?"fue apilado\n":"no fue apilado\n");
            }
            seguir=1; //sino en la proxima llamada a la opcion apilar nunca va a entrar
            printf("Presione una tecla para continuar...");
            getch();
            system("cls");
            break;
            case 2: /*Desapilar*/
                do
                {
                    printf("Desea desapilar 1 elemento? 1-SI 0-NO: ");
                    scanf("%d",&seguir);
                }while(seguir<0||seguir>1);
                while(seguir&&desapilar(&pila,&dato)) //si desapilar retorna 0 es porque estaba vacia
                {
                    printf("Desapilado: ");
                    mostrarDato(&dato);
                    printf("\n");
                    do
                    {
                        printf("Desea desapilar 1 elemento? 1-SI 0-NO: ");
                        scanf("%d",&seguir);
                    }while(seguir<0||seguir>1);
                }
                printf("Presione una tecla para continuar...");
                getch();
                system("cls");
            break;
            case 3: /*Ver Estado de la Pila*/
                printf("La pila %s",pilaLlena(&pila)?"esta llena...\n":"no esta llena...\n");
                if(pilaVacia(&pila))
                    printf("La pila esta vacia...\n");
                else
                    {
                        printf("La pila no esta vacia...\n");
                        printf("El tope es: ");
                        verTope(&pila,&dato);
                        mostrarDato(&dato);
                        printf("\n");
                    }
                printf("Presione una tecla para continuar...");
                getch();
                system("cls");
            break;
            case 4: /*Vaciar Pila*/
            printf("Vaciando Pila...\n");
            vaciarPila(&pila);
            printf("Operacion terminada, presione una tecla para continuar...\n");
            getch();
            system("cls");
            break;
            case 5: /*Guardar Pila en Archivo*/
                if(!guardarPilaenArchivo(&pila))
                    printf("Hubo un inconveniente al guardar la Pila\n");
                else
                    printf("Pila guardada correctamente\n");
                printf("Operacion terminada, presione una tecla para continuar...\n");
                getch();
                system("cls");
            break;
            case 6: /*Cargar Pila desde Archivo*/
                if(!cargarPilaconArchivo(&pila))
                    printf("Hubo un inconveniente al cargar la Pila\n");
                else
                    printf("Pila cargada correctamente\n");
                printf("Operacion terminada, presione una tecla para continuar...\n");
                getch();
                system("cls");
            break;
        }
        op=selecsimp();
    }
    printf("Vaciando Pila...\n");
    vaciarPila(&pila);
    return 1;
}
int selecsimp(void)
{
    int o;
    do
    {
        printf("Menu:\n\n1- Apilar\n2- Desapilar\n3- Ver estado de la Pila\n"
                "4- Vaciar Pila\n5- Guardar Pila en Archivo\n6- Cargar Pila desde Archivo\n"
                "7- Salir\nIngrese la opcion deseada: ");
        scanf("%d",&o);
    }while(o<1||o>7);
    return o;
}
void mostrarDato(t_info *d)
{
    printf("%d",d->dato);
}
int cargarDato (t_info* d)
{
    int opc;
    do
    {
        printf("Desea cargar un dato? 1- SI 0- NO: ");
        scanf("%d",&opc);
        system("cls");
    }while(opc<0||opc>1);
    if(opc)
    {
        printf("Inserte el valor a ingresar a la Pila: ");
        scanf("%d",&d->dato);
        return 1;
    }
    return 0;
}
int abrirArchivo (FILE **ppf,char* ruta,char* modo,int msj)
{
    *ppf=fopen(ruta,modo);
    if(!*ppf)
    {
        if(CON_MSJ==msj)
            printf("ERROR: No se pudo abrir %s en modo %s\n",ruta,modo);
        return 0;
    }
    return 1;
}
int guardarPilaenArchivo (t_pila* pp)
{
    t_info dato;
    FILE* pf;
    int nreg=0;
    if(!abrirArchivo(&pf,"PilaInt.jjp","wb",1))
        return 0;
    fseek(pf,0,SEEK_SET);
    while(desapilar(pp,&dato))
    {
        fwrite(&dato,sizeof(t_info),1,pf);
        nreg++;
    }
    printf("Guardados %d registro(s)\n",nreg);
    fclose(pf);
    return 1;
}
int cargarPilaconArchivo (t_pila* pp)
{
    t_info dato;
    FILE* pf;
    int nreg,cont=0;
    if(!abrirArchivo(&pf,"PilaInt.jjp","rb",1))
        return 0;
    fseek(pf,0,SEEK_END);
    nreg=ftell(pf)/sizeof(t_info);
    fseek(pf,-1*sizeof(t_info),SEEK_END);
    fread(&dato,sizeof(t_info),1,pf);
    while(nreg)
    {
        cont++;
        apilar(pp,&dato);
        fseek(pf,-2*sizeof(t_info),SEEK_CUR);
        fread(&dato,sizeof(t_info),1,pf);
        nreg--;
    }
    printf("Se cargaron %d registros\n",cont);
    fclose(pf);
    return 1;
}
