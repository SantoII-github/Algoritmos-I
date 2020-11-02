#include <stdio.h>

int pedirEntero(void)
{
    int temp;
    printf("Ingrese un número entero\n");
    scanf("%d", &temp);
    return temp; 
}

void imprimeEntero(int x)
{
    printf("El valor final de res es: %d\n", x);
}

int main(void)
{
    int x, y, i, res;
    x = pedirEntero();
    i = 1;
    y = 0;
    res = 0;

    if (i != x+1)
    {
        i = i + 1;
        y = y +1;

        if (i % 2 == 0)
        {
            y = y - 1;
        } else if (i % 2 != 0)
        {
            ;
        }

    printf("El estado actual es: [x->%d, y->%d, i->%d, res->%d]\n", x, y, i, res);
    }
        if (i != x+1)
    {
        i = i + 1;
        y = y +1;

        if (i % 2 == 0)
        {
            y = y - 1;
        } else if (i % 2 != 0)
        {
            ;
        }

    printf("El estado actual es: [x->%d, y->%d, i->%d, res->%d]\n", x, y, i, res);
    }
        if (i != x+1)
    {
        i = i + 1;
        y = y +1;

        if (i % 2 == 0)
        {
            y = y - 1;
        } else if (i % 2 != 0)
        {
            ;
        }

    printf("El estado actual es: [x->%d, y->%d, i->%d, res->%d]\n", x, y, i, res);
    }
        if (i != x+1)
    {
        i = i + 1;
        y = y +1;

        if (i % 2 == 0)
        {
            y = y - 1;
        } else if (i % 2 != 0)
        {
            ;
        }

    printf("El estado actual es: [x->%d, y->%d, i->%d, res->%d]\n", x, y, i, res);
    }
        if (i != x+1)
    {
        i = i + 1;
        y = y +1;

        if (i % 2 == 0)
        {
            y = y - 1;
        } else if (i % 2 != 0)
        {
            ;
        }

    printf("El estado actual es: [x->%d, y->%d, i->%d, res->%d]\n", x, y, i, res);
    }

    res = y * 2 + x % 2;
    imprimeEntero(res);

    return 0;
}