#include <stdio.h>
#include <stdlib.h>
int factorial(int );
int combinatoria (int , int );
float potenciar (float ,int );
float exponencial (int , float );
float raizcuadrada(float ,float );
int main()
{int numn,numm,x;
 float numd,TOL,a;
 /*Factorial
 printf("Inserte el numero deseado (natural): ");
 scanf("%d",&numn);
 printf("%d! = %d\n",numn,factorial(numn));
 getch();

 /*Combinatoria
 do
 {printf("Inserte el numero n (entero positivo o 0): ");
 scanf("%d",&numn);
 printf("Insert el numero m (m>=n): ");
 scanf("%d",&numm);
 }while(numm<numn||numn<0);
 printf("Combinatoria de m con n = %d",combinatoria(numm,numn));
 */
 /*e^x*/

 printf("Inserte el valor al cual elevar el numero e: ");
 scanf("%d",&x);
 printf("Inserte el valor de la tolerancia para el calculo: ");
 scanf("%f",&TOL);
 numd=exponencial(x,TOL);
 printf("e elevado a %d = %f",x,numd);

 /*Raiz cuadrada
 printf("Inserte el valor al cual calcular su raiz cuadrada: ");
 scanf("%f",&a);
 printf("Inserte el valor de la tolerancia para el calculo: ");
 scanf("%f",&TOL);
 numd=raizcuadrada(a,TOL);
 printf("Raiz cuadrada de %f = %f",a,numd);
 */
 /*Fibonacci
 printf("Inserte un entero para buscar en la serie Fibonacci: ");
 scanf("%d",&numn);
 x=fibonacci(numn);
 printf("%s %d en la serie",x?"Se encontro a":"No se encontro a",numn);
 */
}

int factorial(int n)
{int acum=1; //Lo inicializo con 1 que es el neutro del producto
  if(n<0)
  n=-n;
 if(n==0)
   return 1;
 else
   {while(n!=0) /*Podria haber usado recursividad y llamar a factorial(n-1);*/
    {acum*=n;
     n--;
    }
    return acum;
   }
}

int combinatoria (int m, int n)
{return factorial(m)/(factorial(m)*factorial(m-n));
}
float potenciar (float x,int n)
{float r=1;
 int f=0;
 if (n<0)
   {n=-n;
    f=1;
   }
 while(n!=0)
    {r*=x;
     n--;
    }
 return f==0?r:1/r;
 }
float exponencial (int x, float TOL)
{float res=TOL, resf=1;
 int n=1,fn=0;
 if (x<0)
 {x=-x;
  fn=1;
 }
 while (res>=TOL)
    {
     res=(potenciar((float)x,n)/factorial(n));
     resf+=res;
     n++;
    }
 return fn==0?resf:1/resf;
}

float raizcuadrada(float a,float TOL)
{float res=0,resf=1;
 if(a==0)
    return 0;
 while((resf-res)>=TOL||(res-resf)>=TOL)
 {res=resf;
  resf=((0.5)*(res+(a/res)));
 }
 return resf;
}

int fibonacci (int val)
{int a=1,b=1;
 while(val!=a&&val!=b&&a<=val&&b<=val)
    {a=a+b;
     b=a+b;
    }
 return (val==a||val==b?1:0);
}
