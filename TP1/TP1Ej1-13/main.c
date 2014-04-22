#include <stdio.h>
#include <stdlib.h>
#include "FcMatematicas.h"

int main()
{
    int op,numn,numm,x,resto,coci;
    float numd,TOL,a;
    op=selecsimp();
    while(op!=0)
    {
        switch(op)
        {
        case 1: /*Ej 1: Factorial*/
            do
            {printf("Ej 1: Factorial.\n");
            printf("Inserte el numero natural al cual calcular su factorial: ");
            scanf("%d",&numn);
            system("cls");
            }while(numn<0);
            printf("%d! = %d\n",numn,factorial(numn));
            printf("Presione una tecla para continuar...");
            getch();
            system("cls");
            break;
        case 2: /*Ej 2: Numero Combinatorio*/
            do
            {
                printf("Ej 2: Numero Combinatorio.\n");
                printf("Inserte el numero n (entero positivo o 0): ");
                scanf("%d",&numn);
                printf("Insert el numero m (m>=n): ");
                scanf("%d",&numm);
                system("cls");
            }
            while(numm<numn||numn<0);
            printf("Combinatoria de m con n = %d\n",combinatoria(numm,numn));
            printf("Presione una tecla para continuar...");
            getch();
            system("cls");
            break;
        case 3: /*Ej 3: e^x (Exponencial)*/
            printf("Ej 3: Exponencial.\n");
            printf("Inserte el valor al cual elevar el numero e: ");
            scanf("%d",&x);
            printf("Inserte el valor de la tolerancia para el calculo: ");
            scanf("%f",&TOL);
            numd=exponencial(x,TOL);
            printf("e elevado a %d = %f\n",x,numd);
            printf("Presione una tecla para continuar...");
            getch();
            system("cls");
            break;
        case 4: /*Ej 4: Raiz Cuadrada*/
            printf("Ej 4: Raiz Cuadrada.\n");
            printf("Inserte el valor al cual calcular su raiz cuadrada: ");
            scanf("%f",&a);
            printf("Inserte el valor de la tolerancia para el calculo: ");
            scanf("%f",&TOL);
            numd=raizcuadrada(a,TOL);
            printf("Raiz cuadrada de %f = %f",a,numd);
            printf("Presione una tecla para continuar...");
            getch();
            system("cls");
            break;
        case 5: /*Ej 5: Fibonacci*/
            printf("Ej 5: Fibonacci.\n");
            printf("Inserte un entero para buscar en la serie Fibonacci: ");
            scanf("%d",&numn);
            x=fibonacci(numn);
            printf("%s %d en la serie\n",x?"Se encontro a":"No se encontro a",numn);
            printf("Presione una tecla para continuar...");
            getch();
            system("cls");
            break;
        case 6: /*Ej 6: Sen(x)*/
            printf("Ej 6: Sen(x).\n");
            printf("Inserte el valor al cual calcular su seno: ");
            scanf("%f",&a);
            printf("Inserte el valor de la tolerancia para el calculo: ");
            scanf("%f",&TOL);
            printf("sen(%f) = %f\n",a,seno(a,TOL));
            printf("Presione una tecla para continuar...");
            getch();
            system("cls");
            break;
        case 7: /*Ej 7: Clasificar Naturales (Deficiente, Abundante o Perfecto)*/
            printf("Ej 7: Clasif Naturales.\n");
            printf("Inserte el numero natural a clasificar: ");
            scanf("%d",&x);
            clasifnatural(x);
            printf("Presione una tecla para continuar...");
            getch();
            system("cls");
            break;
        case 8: /*Ej 8: Prod. sumas sucesivas.*/
            do
            {
                printf("Ej 8: Prod. sumas sucesivas.\n");
                printf("Inserte el primer numero natural: ");
                scanf("%d",&x);
                printf("Inserte el segundo numero natural: ");
                scanf("%d",&numn);
                system("cls");
            }
            while(numn<0||x<0);
            printf("%d x %d = %d\n\n",x,numn,(x>numn?prodsumsuces(x,numn):prodsumsuces(numn,x)));printf("Presione una tecla para continuar...");
            getch();
            system("cls");
            break;
        case 9: /*Ej 9: Cociente entero.*/
            do
            {
                printf("Ej 9: Cociente entero.\n");
                printf("Inserte el primer numero natural: ");
                scanf("%d",&x);
                printf("Inserte el segundo numero natural: ");
                scanf("%d",&numn);
                system("cls");
            }
            while(numn<0||x<0);
            cocentero(x,numn,&coci,&resto);
            printf("%d/%d = %d | resto=%d \n",x,numn,coci,resto);
            printf("Presione una tecla para continuar...");
            getch();
            system("cls");
            break;
        case 10: /* Ej 10: Suma prim. N numeros */
            do
            {
                printf("Ej 10: Suma primeros N numeros:\n");
                printf("Inserte el numero de naturales a sumar(N>0): ");
                scanf("%d",&numn);
                system("cls");
            }
            while(numn<=0);
            printf("Con %d numeros se obtiene: %d\n",numn,sumprimn(numn));
            printf("Presione una tecla para continuar...");
            getch();
            system("cls");
            break;
        case 11: /* Ej 11: Suma prim. N numeros pares*/
            do
            {
                printf("Ej 11: Suma primeros N numeros pares:\n");
                printf("Inserte el numero de naturales a sumar(N>0): ");
                scanf("%d",&numn);
                system("cls");
            }
            while(numn<=0);
            printf("Con %d numeros se obtiene (tomando solo pares): %d\n",numn,sumprimnpar(numn));
            printf("Presione una tecla para continuar...");
            getch();
            system("cls");
            break;
        case 12: /* Ej 12: Suma prim N menor N*/
            do
            {
                printf("Ej 12: Suma primeros N num menores que N:\n");
                printf("Inserte el numero de naturales a sumar(N>0): ");
                scanf("%d",&numn);
                system("cls");
            }
            while(numn<=0);
            printf("Con %d numeros se obtiene: %d\n",numn,sumprimnmenorn(numn));
            printf("Presione una tecla para continuar...");
            getch();
            system("cls");
            break;
        case 13: /* Ej 13: Natural Primo*/
            do
            {
                printf("Ej 13: Natural Primo:\n");
                printf("Inserte el numero natural a evaluar: ");
                scanf("%d",&numn);
                system("cls");
            }
            while(numn<=0);
            printf("%d %s\n",numn,(esprimo(numn)?"es primo":"no es primo"));
            printf("Presione una tecla para continuar...");
            getch();
            system("cls");
            break;
        }
        op=selecsimp();
    }
}
