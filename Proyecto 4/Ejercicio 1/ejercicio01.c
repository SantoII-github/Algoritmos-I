#include <stdio.h>
#include <assert.h>

int pedirEntero(void)
{
    int temp;
    printf("Ingrese un número entero positivo.\n");
    scanf("%d", &temp);
    return temp; 
}

void imprimeHola(void)
{
    printf("hola\n");
}

void holaHasta(int n)
{
    assert(n > 0);
    while (n > 0)
    {
        imprimeHola();
        n = n - 1;
    }
}

int main(void)
{
    int n;
    n = pedirEntero();
    holaHasta(n);

    return 0;
}