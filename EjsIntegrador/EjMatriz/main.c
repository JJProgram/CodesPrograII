#include <stdio.h>
#include <stdlib.h>
#define FIL 10
#define COL 20

int main()
{
    /*Este main esta hecho para probar, si se quiere hacer una funcion de insercion
    hay que tener en cuenta que tiene que tener 2 punteros a int para el numero de filas
    y columnas, y que el valor que conserven siga lo enunciado en la logica de traspuesta*/
    int mat[FIL][COL]={{1,2,3},{4,5,6},{7,8,9}};
    printf("Matriz Original:\n");
    mostrarMat(mat,3,3);
    traspuestaInSituCuadrada(mat,3,3);
    printf("Matriz Resultante:\n");
    mostrarMat(mat,3,3);
}
int traspuestaInSituCuadrada (int m[][COL],int nfilmat,int ncolmat)
{
    /*nfilmat: nº de filas ocupados en la matriz
      ncolmat: nº de columnas ocupados en la matriz
      Si tengo 1 fila, subindice 0, 2 filas, 0 y 1, etc. Lo mismo para columnas*/
    int aux,i,j;
    if(nfilmat!=ncolmat)
        return 0; //no es cuadrada.
    for(i=0;i<(nfilmat-1);i++)
        for(j=i+1;j<ncolmat;j++)
        {
            aux=m[i][j];
            m[i][j]=m[j][i];
            m[j][i]=aux;
        }
    return 1;
}
void mostrarMat(int m[][COL],int nfilmat,int ncolmat)
{
    int i,j;
    for(i=0;i<nfilmat;i++)
    {
        for(j=0;j<ncolmat;j++)
            printf("%d ",m[i][j]);
        printf("\n");
    }
}
