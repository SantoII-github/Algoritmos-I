#include <stdio.h>

int pedirEntero(void)
{
    int temp;
    printf("Ingrese un número entero\n");
    scanf("%d", &temp);
    return temp; 
}


int main(void) 
{
    int x, y, z, b, w; 
    x = pedirEntero();
    y = pedirEntero();
    z = pedirEntero();
    b = pedirEntero();
    w = pedirEntero();

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