#include <stdio.h>
#include <stdbool.h>
#define TAM 5

bool existe_positivo(int a[], int tam)
{
    int i;
    bool existePositivo; 
    i = 0;
    existePositivo = false; 
    while (i < tam)
    {
        if (a[i] < 0)
        {
            ;
        } else {
            existePositivo = true; 
        }
        i = i + 1;
    }
    return existePositivo;
}

bool todos_positivos(int a[], int tam)
{
    int i;
    bool todosPositivos;
    i = 0;
    todosPositivos = true;
    while (i < tam)
    {
        if (a[i] >= 0)
        {
            ;
        } else
        {
            todosPositivos = false;
        }
        i = i + 1;
    }
    return todosPositivos;
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
    int array[TAM], opcion;
    bool valorFuncion;
    pedirArreglo(array, TAM);
    printf("Elija que función ejecutar:\n");
    printf("1. existe_positivo\n");
    printf("2. todos_positivos\n");
    scanf("%d", &opcion);

    switch(opcion)
    {
        case 1:
            valorFuncion = existe_positivo(array, TAM);
            printf("existePositivo: %d\n", valorFuncion);
            break;
        case 2:
            valorFuncion = todos_positivos(array, TAM);
            printf("todosPositivos = %d\n", valorFuncion);
            break;
    }

    return 0;
}