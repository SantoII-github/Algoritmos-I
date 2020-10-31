#include <stdio.h>

int main(void)
{
    int i; 
    printf("Ingrese el valor de i.\n");
    scanf("%d", &i);

    while (i != 0)
    {
        i = 0;
        printf("El valor actual de i = %d\n", i);
    }

    return 0;
}