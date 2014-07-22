#include "FcEjercicio.h"

int main()
{
    t_lista lista;
    t_arbol arbol;
    FILE* pfs;
    int altura;
    crearLista(&lista);
    crearArbol(&arbol);
    abrirArchivo(&pfs,"stock.bin","rb+",1);
    mostrarContenidoBinario(&pfs);
    inicializarArbol(&arbol);
    printf("Arbol en PreOrden:\n");
    mostrarPreOrden(&arbol);
    printf("Fin Arbol.\n");
    printf("Cual es la altura a procesar? ");
    scanf("%d",&altura);
    if(altura<0)
        altura*=-1;
    if(!altura)
        printf("La altura no puede ser 0\n");
    else
        printf("Se procesaron %d nodos\n",procesarAlturaArbol(&pfs,&arbol,&lista,altura));
    mostrarLista(&lista);
    mostrarContenidoBinario(&pfs);
    vaciarLista(&lista);
    eliminarArbol(&arbol);
    fclose(pfs);
    printf("Archivo, Arbol y Lista liberados de memoria correctamente\n");
}
