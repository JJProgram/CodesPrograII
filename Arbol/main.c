#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FcArbol.h"
#define aMayusc(X)((X)>='a'&&(X)<='z'?(X)-32:(X))
#define CON_MSJ 1
int abrirArchivo(FILE** ,char* , char* ,int );
char selecSimp(void);
int main()
{
    char op;
    int car;
    t_arbol arbol;
    t_info dato;
    FILE*pf;
    crearArbol(&arbol);
    op=selecSimp();
    while(op!='0')
    {
        switch(op)
        {
            case 'A': /*Insertar Recursivo*/
                printf("Ingrese el dato a cargar (entero): ");
                scanf("%d",&dato.clave);
                car=insertarNodoRec(&arbol,&dato);
                printf("El nodo %s",car==0?"no fue insertado (Sin memoria)\n":car==-1?"no fue insertado (Duplicado)\n":"fue insertado\n");
                printf("Presione una tecla para continuar...");
                getch();
                system("cls");
            break;
            case 'B': /*Insertar Iterativo*/
                printf("Ingrese el dato a cargar (entero): ");
                scanf("%d",&dato.clave);
                car=insertarNodoIt(&arbol,&dato);
                printf("El nodo %s",car==0?"no fue insertado (Sin memoria)\n":car==-1?"no fue insertado (Duplicado)\n":"fue insertado\n");
                printf("Presione una tecla para continuar...");
                getch();
                system("cls");
            break;
            case 'C': /*Mostrar Arbol en PreOrden*/
                preOrdenR(&arbol);
                printf("Presione una tecla para continuar...");
                getch();
                system("cls");
            break;
            case 'D': /*Mostrar Arbol en InOrden*/
                inOrdenR(&arbol);
                printf("Presione una tecla para continuar...");
                getch();
                system("cls");
            break;
            case 'E': /*Mostrar Arbol en PosOrden*/
                posOrdenR(&arbol);
                printf("Presione una tecla para continuar...");
                getch();
                system("cls");
            break;
            case 'F': /*Guardar Arbol en Archivo*/
                if(abrirArchivo(&pf,"arbol.bin","wb",1))
                {
                    guardarArbolEnArchivo(&arbol,&pf);
                    printf("Arbol guardado correctamente!\n");
                    fclose(pf);
                }
                printf("Presione una tecla para continuar...");
                getch();
                system("cls");
            break;
            case 'G': /*Recuperar Arbol desde Archivo*/
                if(abrirArchivo(&pf,"arbol.bin","rb",1))
                {
                    eliminarArbol(&arbol);
                    if(cargarArbolDeArchivo(&arbol,&pf))
                    {
                        printf("Se cargo el Arbol desde arbol.bin exitosamente\n");
                        fclose(pf);
                    }
                    else
                        printf("Hubo un error al cargar el Arbol desde arbol.bin\n");

                }
                printf("Presione una tecla para continuar...");
                getch();
                system("cls");
            break;
            case 'H':
                printf("El arbol tiene %d nodos\n",contarNodos(&arbol));
                printf("Presione una tecla para continuar...");
                getch();
                system("cls");
            break;
            case 'I':
                printf("El arbol tiene %d hojas\n",contarHojas(&arbol));
                printf("Presione una tecla para continuar...");
                getch();
                system("cls");
            break;
            case 'J':
                printf("El arbol tiene %d hojas\n",contaryMostrarHojas(&arbol));
                printf("Presione una tecla para continuar...");
                getch();
                system("cls");
            break;
            case 'K':
                printf("El arbol tiene %d nodos no-hojas\n",contarNoHojas(&arbol));
                printf("Presione una tecla para continuar...");
                getch();
                system("cls");
            break;
            case 'L':
                printf("El arbol tiene %d nodos con hijos x izquierda\n",contarNodosConHijosIzq(&arbol));
                printf("Presione una tecla para continuar...");
                getch();
                system("cls");
            break;
            case 'M':
                printf("El arbol tiene %d nodos con solo hijos x derecha\n",contarNodosSoloHijosDer(&arbol));
                printf("Presione una tecla para continuar...");
                getch();
                system("cls");
            break;
            case 'N':
                printf("El arbol tiene %d nodos con clave par\n",contarNodosClavePar(&arbol));
                printf("Presione una tecla para continuar...");
                getch();
                system("cls");
            break;
            case 'O':
                printf("El subarbol izquierdo tiene %d nodos\n",contarNodosSubArbolIzq(&arbol));
                printf("Presione una tecla para continuar...");
                getch();
                system("cls");
            break;
            case 'P':
                do
                {
                   printf("Esta seguro de que desea eliminar %d nodos del arbol? 1- SI 0- NO: ",contarNodos(&arbol));
                   scanf("%d",&car);
                   system("cls");
                }while(car!=1&&car!=0);
                if(car==1)
                {
                    eliminarArbol(&arbol);
                    printf("Todos los nodos fueron eliminados con exito!\n");
                }
                else
                    printf("Operacion abortada\n");
                printf("Presione una tecla para continuar...");
                getch();
                system("cls");
            break;
        }
        op=selecSimp();
    }
    eliminarArbol(&arbol);
}

int abrirArchivo(FILE** ppf,char* ruta, char* modo,int msj)
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
char selecSimp(void)
{
    char o,menu[]={"0ABCDEFGHIJKLMNOP"};
    do
    {
        printf("Menu de opciones:\n0- Salir\nA- Insertar Recursivo\nB- Insertar Iterativo\n"
               "C- Mostrar Preorden\nD- Mostrar Inorden\nE- Mostrar Posorden\n"
               "F- Guardar arbol en Archivo\nG- Recuperar arbol desde Archivo\n"
               "H- Contar nodos\nI- Contar hojas\nJ- Contar y mostrar hojas\n"
               "K- Contar No hojas\nL- Contar nodos c/ hijos x izq\n"
               "M- Contar nodos solo c/ hijos x der\nN- Contar los nodos cuya clave es par\n"
               "O- Contar nodos subarbol izquierdo\nP- Eliminar todos los nodos\n"
               "Ingrese la opcion deseada: ");
        scanf("%c",&o);
        o=aMayusc(o);
        system("cls");
    }while(!strchr(menu,o));
    return o;
}
