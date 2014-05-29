#include <stdio.h>
#include <stdlib.h>
#define FIL 5
#define COL 3

void mostrarMatriz(int *m,int ,int );
int* prodmatricial (int [][COL],int ,int ,int [][FIL],int ,int );

int main()
{
    int m1 [FIL][COL]={{1,5,6},{2,2,3},{7,7,5},{2,3,0},{0,0,1}};
    int m2 [COL][FIL]={{1,5,6,7,1},{6,7,1,0,2},{0,0,0,1,0}};
    int *mat3,res;
    mat3=prodmatricial (m1,FIL,COL,m2,COL,FIL);
    if(!mat3)
       {
           printf("No se pudo realizar el producto matricial\n");
           printf("Presione una tecla para salir del programa...");
           getch();
           exit(1);
       }
    mostrarMatriz(mat3,FIL,FIL);
    free(mat3);
}
void mostrarMatriz(int* m,int maxf,int maxc)
{
    int i,j;
    for(i=0;i<maxf;i++)
    {
        for(j=0;j<maxc;j++)
            printf("%d ",*(m+i*maxc+j));
        printf("\n");
    }
}
int* crearMatriz (int maxf,int maxc)
{
    int* m;
    m=(int*)malloc(sizeof(int)*maxf*maxc);
    if(!m)
        return NULL;
    return m;
}
int* prodmatricial (int m1[][COL],int maxf1,int maxc1,int m2[][FIL],int maxf2,int maxc2)
{
    int *m3,i,j,k;
    if(maxc1!=maxf2&&maxc1!=0&&maxf2!=0)
        return NULL;
    m3=crearMatriz(maxf1,maxc2);
    if(!m3)
        return NULL;
    for(i=0;i<maxf1;i++)
        for(j=0;j<maxc2;j++)
            *(m3+i*maxc2+j)=0;
    for(i=0;i<maxf1;i++)
    {
        for(j=0;j<maxc2;j++)
        {
            for(k=0;k<maxc1;k++)
                *(m3+i*maxc2+j)+=(m1[i][k]*m2[k][j]);
        }
    }
    return m3;
}
