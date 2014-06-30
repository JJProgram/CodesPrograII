#include "FcEjercicio.h"
int main()
{
    t_lista lista;
    t_arbol arbol;
    FILE* pf;
    int op;
    crearLista(&lista);
    crearArbol(&arbol);
    op=selecSimp();
    pf=fopen("arbol.bin","rb");
    cargarArbolDeArchivo(&arbol,&pf);
    printf("Mostrando el arbol:\n");
    preOrdenR(&arbol);
    while(op!=4)
    {
        switch(op)
        {
            case 1: /*Cargar arbol en lista*/
            arbolAListaDoble(&arbol,&lista,0);
            printf("Presione una tecla para continuar...");
            getch();
            system("cls");
            break;
            case 2: /*Mostrar Lista*/
            mostrarListaDoble(&lista);
            printf("Presione una tecla para continuar...");
            getch();
            system("cls");
            break;
            case 3: /*Vaciar Lista*/
            vaciarLista(&lista);
            printf("Presione una tecla para continuar...");
            getch();
            system("cls");
            break;
        }
        op=selecSimp();
        printf("Mostrando el arbol:\n");
        preOrdenR(&arbol);
    }
    vaciarLista(&lista);
    eliminarArbol(&arbol);
    fclose(pf);
    return 0;
}
int selecSimp()
{
    int o;
    do
    {
        printf("Menu:\n1- Cargar Arbol en Lista\n2- Mostrar Lista\n3- Vaciar Lista\n"
               "4- Salir\n"
               "Ingrese la opcion deseada: ");
        scanf("%d",&o);
        system("cls");
    }while(o<1||o>4);
    return o;
}
