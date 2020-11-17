#include <stdio.h>
#define TAM 5

int sumatoria(int a[], int tam)
{
    int i, sum;
    i = 0;
    sum = 0; 
    while (i < tam)
    {
        sum = sum + a[i];
        i = i + 1;
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

void pedirArreglo(int a[], int n_max)
{
    int i, temp;
    i = 0;
    while (i < n_max)
    {
        temp = pedirEntero();
        a[i] = temp;
        i = i + 1;
    }
}

int main(void)
{   
    int array[TAM], sumArray;
    pedirArreglo(array, TAM);
    sumArray = sumatoria(array, TAM);
    printf("La suma de los elementos del arreglo es: %d\n", sumArray);

    return 0; 
}