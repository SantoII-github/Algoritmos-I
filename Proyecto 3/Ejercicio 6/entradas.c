#include <stdio.h>


int pedirEntero(void)
{
    int temp;
    printf("Ingrese un número entero\n");
    scanf("%d", &temp);
    return temp; 
}

void imprimirEntero(int x)
{
    printf("El entero ingresado es %d\n", x);
}

int main(void)
{
    int a;
    a = pedirEntero();
    imprimirEntero(a);

    return 0;
}