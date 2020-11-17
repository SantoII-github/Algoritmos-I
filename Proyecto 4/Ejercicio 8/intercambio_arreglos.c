#include <stdio.h>
#include <assert.h>
#define TAM 5

void intercambiar(int a[], int tam, int i, int j)
{
    int iaux, jaux;
    iaux = a[i];
    jaux = a[j];
    a[j] = iaux;
    a[i] = jaux;
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
    int array[TAM], ipos, jpos;
    pedirArreglo(array, TAM);
    printf("Ingrese el primer índice a intercambiar\n");
    scanf("%d", &ipos);
    printf("Ingrese el segundo índice a intercambiar\n");
    scanf("%d", &jpos);
    assert(0 <= ipos && ipos < TAM && 0 <= jpos && jpos < TAM);
    
    intercambiar(array, TAM, ipos, jpos);
    printf("El arreglo con los elementos de los índices %d y %d intercambiados es:\n", ipos, jpos);
    imprimeArreglo(array, TAM);

    return 0; 
}