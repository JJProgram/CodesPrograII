#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char codRubro;
}t_info;
typedef struct s_nodo
{
    struct s_nodo* ant;
    t_info info;
    struct s_nodo* sig;
}t_nodo;
typedef t_nodo* t_lista;

int comparar(const t_info* ,const t_info* );
void crearListaDoble(t_lista* );
int insertarEnListaDobleOrd(t_lista* ,const t_info* );
void vaciarListaDoble(t_lista* );
void mostrarListaDoble(t_lista* );
int main()
{
    t_lista lista;
    t_info varinfo;
    int corte;
    crearListaDoble(&lista);
    printf("Desea ingresar un valor? 1- SI 0 - NO: ");
    scanf("%d",&corte);
    while(corte!=0)
    {
        fflush(stdin);
        printf("Caracter a guardar: ");
        scanf("%c",&varinfo.codRubro);
        insertarEnListaDobleOrd(&lista,&varinfo);
        printf("Desea ingresar un valor? 1- SI 0 - NO: ");
        scanf("%d",&corte);
    }
    mostrarListaDoble(&lista);
    printf("Cual es el valor a extraer?: ");
    fflush(stdin);
    scanf("%c",&varinfo.codRubro);
    if(buscaryEliminarDeListaDoble(&lista,&varinfo))
        printf("Se elimino apropiadamente %c\n",varinfo.codRubro);
    else
        printf("No se pudo eliminar %c\n",varinfo.codRubro);
    mostrarListaDoble(&lista);
    vaciarListaDoble(&lista);
    if(lista==NULL)
        printf("Lista vaciada correctamente\n");
    else
        printf("Fallo el vaciado de la lista\n");
    return 0;
}
int comparar(const t_info* d1,const t_info* d2)
{
    return (d1->codRubro - d2->codRubro);
}
void crearListaDoble(t_lista* pl)
{
    *pl=NULL;
}
int insertarEnListaDobleOrd(t_lista* pl,const t_info* d)
{
    t_nodo* nue,*act=*pl,*ant;
    int cmp;
    if(act)
    {
        while(act->sig&&(cmp=comparar(d,&act->info))>0)
            act=act->sig;
        while(act->ant&&(cmp=comparar(d,&act->info))<0)
            act=act->ant;
        if((cmp=comparar(d,&act->info))==0)
        {
            //DUPLICADO
            return -1;
        }
    }
    if(act)
    {
        if(cmp>0)
        {
            ant=act;
            act=act->sig;
        }
        else
            ant=act->ant;
    }
    else
        ant=NULL;
    nue=(t_nodo*)malloc(sizeof(t_nodo));
    if(!nue)
        return 0; // sin memoria
    nue->info=*d;
    nue->ant=ant;
    nue->sig=act;
    if(ant)
        ant->sig=nue;
    if(act)
        act->ant=nue;
    *pl=nue;
    return 1; //todo bien
}
void vaciarListaDoble(t_lista* pl)
{
    t_nodo* aux;
    while(*pl&&(*pl)->ant)
        *pl=(*pl)->ant;
    while(*pl)
    {
        printf("Borrando Char: %c\n",(*pl)->info.codRubro);
        aux=*pl;
        *pl=aux->sig;
        free(aux);
    }
}
void mostrarListaDoble(t_lista* pl)
{
    int cont=0;
    while(*pl&&(*pl)->ant)
        pl=&(*pl)->ant;
    while(*pl)
    {
        printf("Nodo %d || Char: %c\n",cont+1,(*pl)->info.codRubro);
        pl=&(*pl)->sig;
        cont++;
    }
}
int buscaryEliminarDeListaDoble(t_lista* pl,t_info* d)
{
    t_nodo*act=*pl,*ant,*aux;
    if(act)
    {
        while(act->sig&&(comparar(d,&act->info))>0)
            act=act->sig;
        while(act->ant&&(comparar(d,&act->info))<0)
            act=act->ant;
        if((comparar(d,&act->info))==0)
        {
            aux=act;
            *d=aux->info;
            ant=act->ant;
            act=act->sig;
            if(ant)
                ant->sig=act;
            if(act)
                act->ant=ant;
            if((act&&!ant)||(act&&ant)) //act&&ant podria ponerlo dentro, pero para descartar mas rapido lo uso aca
                *pl=act;
            else
            {
                if((!act&&ant))
                    *pl=ant;
                else // !act &&!ant)
                    *pl=NULL;
            }
            free(aux);
            return 1;
        }
    }
    return 0;
}
