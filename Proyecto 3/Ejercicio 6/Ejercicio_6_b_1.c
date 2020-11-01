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
    int x, y, z, m;
    x = pedirEntero();
    y = pedirEntero();
    z = pedirEntero();
    m = pedirEntero();

    if (x < y) 
    {
        m = x;
    } else if (x >= y)
    {
        m = y;
    }

    printf("El estado Sigma1 es: x = %d, y = %d, z = %d, m = %d\n", x, y, z, m);
    
    if (m < z)
    {
        ;
    } else if (m >= z)
    {
        m = z;
    }

    printf("El estado Sigma2 es: x = %d, y = %d, z = %d, m = %d\n", x, y, z, m);

    return 0;
}

/*
La principal ventaja es que el código es mucho más simple de leer, ya que se repiten menos líneas y las que se repiten tienen un propósito muy claro por el nombre de la función.
Dentro del ejercicio 4, la funcion pedirEntero también sería útil en el subinciso a. Está reescrita en el archivo Ejercicio_6_b_2.c
Dentro del Práctico, todos los ejercicios pidieron que el estado Sigma0 se le solicitara al usuario, por lo que en todos se podría utilizar pedirEntero para tener un
código más limpio y corto. La función imprimirEntero también podría ser útil para devolver el estado final del programa, pero prefiero los printf que ya están en uso
porque son más cómodos para imprimir el string que va junto al número.
*/