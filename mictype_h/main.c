#include "mictype.h"

int main()
{char alp='c',dig='0';
 printf("Usando is_alpha: %c %s\n",alp,is_alpha(alp)?"pertenece al alfabeto":"no pertenece al alfabeto");
 printf("Usando is_digit: %c %s\n",dig,is_digit(dig)?"es un digito":"no es un digito");
 printf("Usando to_upper: %c %c\n",alp,to_upper(alp));
 printf("Usando to_lwr: %c %c\n",alp,to_lower(alp));
 getch();
}
