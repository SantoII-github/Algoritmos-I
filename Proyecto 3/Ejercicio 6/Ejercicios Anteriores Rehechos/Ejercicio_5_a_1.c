#include <stdio.h>
#include <assert.h>

int pedirEntero(void)
{
    int temp;
    printf("Ingrese un número entero\n");
    scanf("%d", &temp);
    return temp; 
}

int main(void)
{
    int i; 
    i = pedirEntero();

    assert(i >= 0);

    while (i != 0)
    {
        i = i - 1;
        printf("Valor actual de i = %d\n", i);
    }

    return 0;
}