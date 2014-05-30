#include "FcUsadas.h"
int abrirArchivo (FILE** ppf,char* ruta,char* modo,int msj)
{
    *ppf=fopen(ruta,modo);
    if(!*ppf)
    {
        if(CON_MSJ==msj)
            printf("ERROR: No se pudo abrir %s en modo %s\n",ruta,modo);
        return 0;
    }
    printf("Apertura de %s en modo %s, exitosa\n",ruta,modo);
    return 1;
}
void archivarSuma(int suma,FILE* pfs)
{
    int magnitud=10;
    t_info aux;
    t_pila pilaaux;
    // uso una pila porque sino el resultado queda al reves, y seria mas complicado manejar "magnitud"
    while(suma!=0)
    {
        aux.num=suma%magnitud;
        apilar(&pilaaux,&aux);
        suma/=magnitud;
    }
    while(!pilaVacia(&pilaaux))
    {
        if(desapilar(&pilaaux,&aux))
        {
            fputc(aux.num+48,pfs);
        }
        if(!pilaVacia(&pilaaux))
            fputc('/',pfs);//solo se pone / si no acaba la pila, 2/3/5#
    }
    fputc('#',pfs);
    fputc('\n',pfs);
}
int sumarPilas(t_pila* pila1,t_pila* pila2,FILE*pfs)
{
    t_info dato1,dato2;
    int suma=0,magnitud=1,flag1pila=1;
    t_pila pilaauxiliar;
    while(!pilaVacia(pila1)&&!pilaVacia(pila2))
    {
        flag1pila=0;
        desapilar(pila1,&dato1);
        desapilar(pila2,&dato2);
        suma+=((dato1.num+dato2.num)*magnitud);
        magnitud*=10;
    }
    if(flag1pila==1) //cuando solo habia 1 pila originalmente
    {
        while(!pilaVacia(pila1))
        {
            desapilar(pila1,&dato1);
            suma+=(dato1.num);
        }
    }
    else //habia 2 pilas pero en el proceso previo solo 1 quedo vacia
    {
        if(pilaVacia(pila1)&&!pilaVacia(&pila2)) //estaba vacia la 1, hay que seguir con la 2
        {
            while(!pilaVacia(pila2))
            {
                desapilar(pila2,&dato2);
                suma+=(dato2.num*magnitud);
                magnitud*=10;
            }
        }
        else
        {//vuelvo a preguntar porque si se vaciaron las 2, va a llegar a esta instancia si o si
            if(!pilaVacia(pila1)&&pilaVacia(pila2)) //estaba vacia la 2, hay que seguir con la 1
            {
                while(!pilaVacia(pila1))
                {
                    desapilar(pila1,&dato1);
                    suma+=(dato1.num*magnitud);
                    magnitud*=10;
                }
            }
        }
    }
    //printf("La suma es %d\n",suma); linea de testeo
    archivarSuma(suma,pfs);
    vaciarPila(&pilaauxiliar);
}

int cargarySumarPilas (void)
{
    FILE* pf,*pfs;
    t_pila pila1,pila2;
    t_info dato;
    char nchar;
    int npilas=0,res=0;
    if(!abrirArchivo(&pf,"Numeros.txt","rt",1))
        return 0;
    if(!abrirArchivo(&pfs,"Suma.txt","wt",1))
        return 0;
    crearPila(&pila1);
    crearPila(&pila2);
    nchar=fgetc(pf);
    while(!feof(pf))
    {
        while(npilas!=2&&!feof(pf)) //solo quiero procesar de a 2 pilas maximo
        {
            if(esNumero(nchar))
            {

                dato.num=nchar-48; //'0'=48 en ASCII, 1=49... etc.
                if(npilas==0)
                    apilar(&pila1,&dato);
                else
                    apilar(&pila2,&dato);
            }
            else
            {
                if(esFinPila(nchar))
                    npilas++;
            }
            nchar = fgetc(pf);
        }
        /*verTope(&pila1,&dato);
        printf("%d",dato.num);
        verTope(&pila2,&dato);
        printf(" y %d\n",dato.num);*/
        sumarPilas(&pila1,&pila2,pfs);
        npilas=0;
        nchar=fgetc(pf);
    }
    fclose(pf);
    fclose(pfs);
    vaciarPila(&pila1);
    vaciarPila(&pila2);
    return 1;
}
