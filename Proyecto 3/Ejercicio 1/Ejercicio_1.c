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

    printf("Usted ingresó los siguientes valores para las variables:\n x = %d\n y = %d\n z = %d\n", x, y, z);
    printf("Entonces, las siguientes expresiones tienen este resultado:\n");
    printf("x + y + 1 = %d\n", x+y+1);
    printf("z * z + y * 45 - 15 * x = %d\n", z*z+y*45-15*x);
    printf("y - 2 == (x * 3 + 1) %% 5 = %d\n", y-2==(x*3+1)%5);
    printf("y / 2 * x = %d\n", y/2*x);
    printf("y < x * z = %d\n", y<x*z);

    return 0; 
}

/*
Expresión                | (x→7, y→3, z→5) | (x→1, y→10, z→8) |
x + y + 1                | 11              | 12               |
z * z + y * 45 - 15 * x  | 55              | 499              |
y - 2 == (x * 3 + 1)     | 0 (False)       | 0 (False)        |
y / 2 * x                | 7               | 5                |
y < x * z                | 1 (True)        | 0 (False)        |

En la última expresión el tipo del resultado es un Int, a pesar de que nosotros lo interpretemos como un Booleano.
*/