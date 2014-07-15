#include "FcEjercicio.h"

int main()
{
    t_reg info;
    int seguir=0;
    t_arbol arbol;
    t_cola cola;
    FILE* pf;
    abrirArchivo(&pf,"arbol.bin","rb",1);
    crearArbol(&arbol);
    archivoAArbol(&pf,&arbol);
    fclose(pf);
    printf("Mostrando Arbol:\n");
    mostrarArbolInOrden(&arbol);
    printf("Fin del Arbol\n");
    printf("%d hojas pares acoladas\n",hojasParesAColaCircular(&arbol,&cola));
    eliminarArbol(&arbol);
    vaciarCola(&cola);
    return 0;
}
/*
SCRAP DE LA CREACION DE ARBOL.BIN
abrirArchivo(&pf,"arbol.bin","wb",1);

while(seguir<7)
    {
        printf("clave: ");
        fflush(stdin);
        scanf("%d",&info.clave);
        fflush(stdin);
        printf("letra: ");
        scanf("%c",&info.info.letra);
        insertarEnArbolIt(&arbol,&info);
        seguir++;
    }
*/
