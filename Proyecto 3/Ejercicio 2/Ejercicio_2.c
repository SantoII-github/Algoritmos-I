#include <stdio.h>

int main(void) 
{
    int x, y, z, b, w; 
    printf("Ingrese el valor de x.\n");
    scanf("%d", &x);
    printf("Ingrese el valor de y.\n");
    scanf("%d", &y);
    printf("Ingrese el valor de z.\n");
    scanf("%d", &z);
    printf("Ingrese el valor de b.\n");
    scanf("%d", &b);
    printf("Ingrese el valor de w.\n");
    scanf("%d", &w);

    printf("Usted ingresó los siguientes valores para las variables:\n x = %d\n y = %d\n z = %d\n b = %d\n w = %d\n", x, y, z, b, w);
    printf("Entonces, las siguientes expresiones tienen este resultado:\n");
    printf("x %% 4 == 0 = %d\n", x % 4 == 0);
    printf("x + y == 0 && y - x == (-1) * z = %d\n", x+y==0 && y-x==(-1)*z);
    printf("not b && w = %d", ! b && w);

    return 0; 
}

/*
Un posible estado para que se cumpla lo que pide el enunciado es: (x→0,y→0,z→0,b→0,w→0)
*/