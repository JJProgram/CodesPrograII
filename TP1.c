#include <stdio.h>
#include <stdlib.h>
#define abs(x) (x)<0?-(x):(x)
int factorial(int );
int combinatoria (int , int );
float potenciar (float ,int );
float exponencial (int , float );
float raizcuadrada(float ,float );
float seno(float , float );
void clasifnatural (int );
int main()
{int numn,numm,x;
 float numd,TOL,a;
 /*Ej 1:Factorial
 printf("Inserte el numero deseado (natural): ");
 scanf("%d",&numn);
 printf("%d! = %d\n",numn,factorial(numn));
 getch();

 /*Ej 2:Combinatoria
 do
 {printf("Inserte el numero n (entero positivo o 0): ");
 scanf("%d",&numn);
 printf("Insert el numero m (m>=n): ");
 scanf("%d",&numm);
 }while(numm<numn||numn<0);
 printf("Combinatoria de m con n = %d",combinatoria(numm,numn));
 */
 /*Ej 3:e^x

 printf("Inserte el valor al cual elevar el numero e: ");
 scanf("%d",&x);
 printf("Inserte el valor de la tolerancia para el calculo: ");
 scanf("%f",&TOL);
 numd=exponencial(x,TOL);
 printf("e elevado a %d = %f",x,numd);
 */
 /*Ej 4:Raiz cuadrada
 printf("Inserte el valor al cual calcular su raiz cuadrada: ");
 scanf("%f",&a);
 printf("Inserte el valor de la tolerancia para el calculo: ");
 scanf("%f",&TOL);
 numd=raizcuadrada(a,TOL);
 printf("Raiz cuadrada de %f = %f",a,numd);
 */
 /*Ej 5:Fibonacci
 printf("Inserte un entero para buscar en la serie Fibonacci: ");
 scanf("%d",&numn);
 x=fibonacci(numn);
 printf("%s %d en la serie",x?"Se encontro a":"No se encontro a",numn);
*/
 /*Ej 6:Seno(x)
 printf("Inserte el valor al cual calcular su seno: ");
 scanf("%f",&a);
 printf("Inserte el valor de la tolerancia para el calculo: ");
 scanf("%f",&TOL);
 printf("sen(%f) = %f",a,seno(a,TOL));
 */
 /*Ej 7: Clasificar natural (perfecto, deficiente o abundante*/
 printf("Inserte el numero natural a clasificar: ");
 scanf("%d",&x);
 clasifnatural(x);
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

float seno(float a, float TOL)
{float res=TOL,resf=a;
 int fn=-1,n=3;
 while (abs(res)>=TOL)
    {res=((fn*potenciar(a,n))/factorial(n));
     fn=(fn==-1?1:-1);
     n+=2;
     resf+=res;
    }
    return resf;
}

void clasifnatural (int n)
{int sum=0,i;
 if(n==1) //Esto se debe a que, si uso el n/2, 1 es deficiente porque 1>0.5
    printf("El numero %d es perfecto"); //y si quito el n/2 pierdo eficiencia
 else
    {for(i=1;i<=n/2;i++)
     sum+=(n%i==0?i:0);
     printf("El numero %d es %s",n,sum>n?"abundante":sum<n?"deficiente":"perfecto");
    }
}
