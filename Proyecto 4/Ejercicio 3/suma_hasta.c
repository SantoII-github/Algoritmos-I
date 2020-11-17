#include <stdio.h>
#include <assert.h>

int suma_hasta(int N)
{
    assert(N>=0);
    int i, sum;
    i = N;
    sum = 0; 
    while (i>0)
    {
        sum = sum + i;
        i = i - 1;
    } 
    return sum;
}

int pedirEntero(void)
{
    int temp;
    printf("Ingrese un número entero.\n");
    scanf("%d", &temp);
    return temp; 
}

int main(void)
{
    int N, sum;
    N = pedirEntero();
    if (N<0)
    {
        printf("Este programa no funciona con números negativos. Por favor ingrese un entero positivo.\n");

    } else if (N >=0)
    {
    sum = suma_hasta(N);
    printf("La suma de los primeros N enteros positivos es: %d", sum);
    }
    
    return 0; 
}