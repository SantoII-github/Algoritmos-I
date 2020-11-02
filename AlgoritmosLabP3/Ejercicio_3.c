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
    i = 1;
    y = 0;
    x = pedirEntero();
    res = 0;

    while (i != x+1)
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

/*
|        |     x        |       y      |      i       |    res      |
|:-----:|:------------:|:------------:|:-----------:|:------------:|
| σ₀   | 5 | 0 | 0 | 0  |
| σ¹₁  | 5 | 0 | 2 | 0  |
| σ²₁  | 5 | 1 | 3 | 0  |
| σ³₁  | 5 | 1 | 4 | 0  |
| σ⁴₁  | 5 | 2 | 5 | 0  |
| σ⁵₁  | 5 | 2 | 6 | 0  |
*/