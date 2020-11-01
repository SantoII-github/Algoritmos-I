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
    int x, y, i;
    x = pedirEntero();
    y = pedirEntero();
    i = pedirEntero();

    i = 0;
    
    while (x >= y)
    {
        x = x - y;
        i = i + 1;
        printf("El estado Sigma%d,1 es: x->%d, y->%d, i->%d\n", i-1, x, y, i);
    }

    return 0;
}

/*
Estado Inicial      | Sigma0,1          | Sigma1,1          | Sigma2,1          | Sigma3,1
x->13, y->3, i->0   | x->10, y->3, i->1 | x->7, y->3, i->2  | x->4, y->3, i->4  | x->1, y->3, i->4
x->5, y->1, i->5    | x->4, y->1, i->1  | x->3, y->1, i->2  | x->2, y->1, i->4  | x->1, y->1, i->4

3) El programa hace la división entera de x por y utilizando la resta, pero sólo funciona para números positivos. 
La cantidad de veces que y "entra" en x, es decir el cociente, se guarda en la variable i.
*/