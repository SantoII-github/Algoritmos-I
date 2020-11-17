#include <stdio.h>
#include <assert.h>


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

void imprimeArreglo(int a[], int n_max)
{
    int i;
    i = 0;
    while (i < n_max)
    {
        printf("a[%d]: %d\n", i, a[i]);
        i = i + 1;
    }
}

int main(void)
{
    int tam;
    printf("Ingrese un tamaño máximo para el arreglo.\n");
    scanf("%d", &tam);
    assert("tam > 0");
    int a[tam];
    pedirArreglo(a, tam);
    imprimeArreglo(a, tam);

    return 0; 
}