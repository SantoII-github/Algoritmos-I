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
Con los valores que da el práctico:
Sigma1: x->5, y->4, z->8, m->4
Sigma2: x->5, y->4, z->8, m->4

El programa primero cambia el valor de m al mínimo entre x e y. Esto significa que el valor de m que ingresamos nunca se utiliza.
Luego, si m es mayor a z, cambia su valor a z. Es decir, el valor final de m siempre es mayor o igual a z. 
*/