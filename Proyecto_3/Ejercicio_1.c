#include <stdio.h>

int main(void) 
{
    int x, y, z; 
    printf("Ingrese el valor de x.\n");
    scanf("%d", &x);
    printf("Ingrese el valor de y.\n");
    scanf("%d", &y);
    printf("Ingrese el valor de z.\n");
    scanf("%d", &z);

    printf("Usted ingresó los siguientes valores para las variables:\n x=%d\n y=%d\n z=%d\n", x, y, z);
    printf("Entonces, las siguientes expresiones tienen este resultado:\n");
    printf("x + y + 1 = %d\n", x+y+1);
    printf("z * z + y * 45 - 15 * x = %d\n", z*z+y*45-15*x);
    printf("y - 2 == (x * 3 + 1) %% 5 = %d\n", y-2==(x*3+1)%5);
    printf("y / 2 * x = %d\n", y/2*x);
    printf("y < x * z = %d\n", y<x*z);

    return 0; 
}