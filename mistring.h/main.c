#include "mi_string.h"
#include <string.h>
int main()
{
    int op,cmax;
    char cad1[20]= {"Abaabbbab251s135"},cad2[8]= {"lololol"},cad3[20]= {"abaabbbab251s135"};
    op=selecsimp();
    while(op!=0)
    {
        switch(op)
        {
        case 1: /* strchr */
            printf("Strchr Original: Se busco %c en %s, y se obtuvo %c\n",'\0',cad1,*strchr(cad1,'\0'));
            printf("Mi strchr: Se busco %c en %s, y se obtuvo %c\n",'\0',cad1,*str_chr(cad1,'\0'));
            printf("Presione una tecla para continuar...");
            getch();
            system("cls");
            break;
        case 2: /* strcmp */
            printf("Strcmp Original: Se comparo %s con %s, y se obtuvo %d\n",cad1,cad2,strcmp(cad1,cad2));
            printf("Mi strcmp: Se comparo %s con %s, y se obtuvo %d\n",cad1,cad2,str_cmp(cad1,cad2));
            printf("Presione una tecla para continuar...");
            getch();
            system("cls");
            break;
        case 3: /* strcmpi */
            printf("Strcmpi Original: Se comparo %s con %s.\nResultado: %d\n",cad1,cad2,strcmpi(cad1,cad2));
            printf("Mi strcmpi: Se comparo %s con %s.\nResultado: %d\n",cad1,cad2,str_cmpi(cad1,cad2));
            printf("Presione una tecla para continuar...");
            getch();
            system("cls");
            break;
        case 4: /* strncmp */
            printf("Ingrese el numero maximo de caracteres a analizar: ");
            scanf("%d",&cmax);
            printf("Strncmp Original: Se comparo %s con %s.\nResultado: %d\n",cad1,cad3,strncmp(cad1,cad3,cmax));
            printf("Mi strncmp: Se comparo %s con %s.\nResultado: %d\n",cad1,cad3,str_ncmp(cad1,cad3,cmax));
            printf("Presione una tecla para continuar...");
            getch();
            system("cls");
            break;
        case 5: /* strstr */
            printf("Strstr Original: Se busco %s con %s, y se obtuvo %s\n",cad2,cad1,strstr(cad1,cad2));
            printf("Mi strstr: Se busco %s en %s, y se obtuvo %s\n",cad2,cad1,str_str(cad1,cad2));
            printf("Presione una tecla para continuar...");
            getch();
            system("cls");
            break;
        case 6: /* strcat */
            printf("Strcat Original: Se concateno %s con %s\nResultado: %s\n",cad2,cad1,strcat(cad1,cad2));
            printf("Mi strstr: Se concateno %s con %s\nResultado: %s\n",cad2,cad3,str_cat(cad1,cad2));
            printf("Presione una tecla para continuar...");
            getch();
            system("cls");
            break;
        case 7: /*strcpy*/
            printf("Strcpy Original: Se copio %s a %s\n",cad2,cad1);
            printf("Resultado: %s\n",str_cpy(cad1,cad2));
            printf("Mi Strcpy: Se copio %s a %s\n",cad2,cad1);
            printf("Resultado: %s\n",strcpy(cad1,cad2));
            getch();
            system("cls");
            break;
        case 8: /* strlen */
            printf("Strlen Original: Se analizo %s\nResultado: %d\n",cad1,strlen(cad1));
            printf("Mi Strlen: Se analizo %s\nResultado: %d\n",cad1,str_len(cad1));
            getch();
            system("cls");
            break;
        case 9: /* strupr */
            printf("String original: %s\n",cad1);
            printf("String actual: %s\n",str_upr(cad1));
            getch();
            system("cls");
            break;
        case 10: /* strlwr */
            printf("String original: %s\n",cad1);
            printf("String actual: %s\n",str_lwr(cad1));
            getch();
            system("cls");
            break;
        }
        op=selecsimp();
    }
}

int selecsimp ()
{
    int o;

    do
    {
        printf("Funciones personales de string.h:\n1- strchr\n2- strcmp\n3- strcmpi\n4- strncmp\n"
               "5- strstr\n6- strcat\n7- strcpy\n8- strlen\n9- strupr\n10- strlwr\n0- Salir\n");
        printf("Ingrese la opcion deseada: ");
        scanf("%d",&o);
        system("cls");
    }
    while(o<0||o>10);
    return o;
}
