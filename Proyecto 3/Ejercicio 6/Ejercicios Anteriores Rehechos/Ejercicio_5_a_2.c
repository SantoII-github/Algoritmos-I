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
    int i; 
    i = pedirEntero();

    while (i != 0)
    {
        i = 0;
        printf("El valor actual de i = %d\n", i);
    }

    return 0;
}