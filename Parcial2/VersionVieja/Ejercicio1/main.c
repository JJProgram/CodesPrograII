#include "FcEjercicio.h"
int main()
{
    t_lista lista;
    t_arbol arbol;
    t_infoA aux;
    FILE* pfs,*pfa;
    int altura,cont=0;
    float a;
    abrirArchivo(&pfs,"stock.bin","rb",1);
    crearListaDoble(&lista);
    /*Linea test*/
    crearArbol(&arbol);
    //abrirArchivo(&pfa,"arbol.bin","rb",1);
    //rewind(pfa);
    //printf("Arbol listo con %d nodos",archivoAArbol(&pfs,&arbol));
    while(cont!=5)
    {
        fflush(stdin);
        printf("CodArt: ");
        scanf("%d",&aux.codArticulo);
        fflush(stdin);
        printf("CodRubro: ");
        scanf("%c",&aux.codRubro);
        fflush(stdin);
        printf("Cantidad: ");
        scanf("%f",&a);
        aux.cantidad=a;
        insertarenArbolIt(&arbol,&aux);
        cont++;
    }
    printf("Mostrando Arbol\n");
    mostrarArbol(&arbol);
    printf("Muestra finalizada\n");
    /*Fin test*/
    printf("Ingrese la altura de busqueda: ");
    scanf("%d",&altura);
    if(altura<0)
        altura*=-1;
    if(altura!=0)
        printf("Se procesaron %d nodos del arbol",procesarNodosXAltura(&pfs,&arbol,&lista,&altura,1));
    else
        printf("No hay altura 0");
    fclose(pfs);
    fclose(pfa);
    eliminarArbol(&arbol);
    return 0;
}

