#include <stdio.h>
#include <stdlib.h>
#define TAMF 5
#define TAMC 3
#define abs(x)((x)<0?-(x):(x))
typedef struct
{
    int i;
    int j;
}t_vertice;

int* crearMatriz(int ,int );
int* mayorSubMat(int [][TAMC],int ,int );
int main()
{
    int mat[TAMF][TAMC]={{1,3,2},{2,5,7},{8,2,2},{5,4,4},{1,0,0}};
    int* mres,i,j;
    printf("La matriz trabajada es:\n");
    for(i=0;i<TAMF;i++)
    {
        for(j=0;j<TAMC;j++)
            printf("%d ",mat[i][j]);
        printf("\n");
    }
    mres=mayorSubMat(mat,2,1);
    if(!mres)
    {
        printf("Hubo un problema al intentar realizar la operacion");
        exit(1);
    }
    free(mres);
}
int* crearMatriz(int maxf,int maxc)
{
    int* maux=(int*)malloc(sizeof(int)*maxf*maxc);
    if(!maux)
        return 0;
    return maux;
}
int* mayorSubMat(int m[][TAMC],int di,int dj)
{
    int i,j,iI,iF,jI,jF,*mr;
    if(di>=TAMF||dj>=TAMC)
        return NULL;
    if(di>=abs(di-(TAMF-1)))
    {
        iI=0;
        iF=di;
    }
    else
    {
        iI=di;
        iF=TAMF-1;
    }
    if(dj>=abs(dj-(TAMC-1)))
    {
        jI=0;
        jF=dj;
    }
    else
    {
        jI=dj;
        jF=TAMC-1;
    }
    printf("Se han encontrado como subindices maximos los siguientes pares:\n"
           "P1:(%d,%d)||P2:(%d,%d)||P3:(%d,%d)||P4:(%d,%d)\n",iI,jI,iI,jF,iF,jI,iF,jF);
    mr=crearMatriz(iF,jF);
    printf("iI es %d | iF es %d | jI es %d | jF es %d\n",iI,iF,jI,jF);
    for(i=iI;i<=iF;i++)
        for(j=jI;j<=jF;j++)
        {
          *(mr+i*(jF+1)+j)=m[i][j];
          printf("i:%d j:%d || Orig: %d | Fin: %p\n",i,j,m[i][j],*(mr+i*(jF+1)+j));
        }

    printf("\n");
    for(i=iI;i<=iF;i++)
    {
        for(j=jI;j<=jF;j++)
            printf("%d ",*(mr+i*(jF+1)+j));
        printf("\n");
    }

    return mr;

}
