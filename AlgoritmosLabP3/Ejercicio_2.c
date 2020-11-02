#include <stdio.h>

int main(void)
{
    int x, y, dni1, dni2;
    x = 7;
    y = 4;
    dni1 = 8;
    dni2 = 7;

    printf("El estado Sigma0 es: [x->%d, y->%d, dni1->%d, dni2->%d]\n", x, y, dni1, dni2);

    if (dni1 % 2 != 0 && dni2 % 2 == 0)
    {
        x = x + dni1;
        y = y + x;
    } else if (dni1 % 2 == 0 || dni2 % 2 != 0)
    {
        x = y + x;
    }

    printf("El estado Sigma1 es: [x->%d, y->%d, dni1->%d, dni2->%d]\n", x, y, dni1, dni2);

    return 0;
}