#include <stdio.h>
#define TAM 5

struct comp_t 
{
    int menores;
    int iguales;
    int mayores;
};

struct comp_t cuantos(int a[], int tam, int elem)
{
    int index = 0;
    struct comp_t comparaciones;
    comparaciones.menores = 0;
    comparaciones.iguales = 0;
    comparaciones.mayores = 0;
    while (index < tam)
    {
        if (a[index] < elem)
        {
            comparaciones.menores = comparaciones.menores + 1;
        } else if (a[index] == elem)
        {
            comparaciones.iguales = comparaciones.iguales + 1;
        } else if (a[index] > elem)
        {
            comparaciones.mayores = comparaciones.mayores + 1;
        }
        
        index = index + 1;
    }
    return comparaciones;
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
    int array[TAM], elem;
    struct comp_t cantidades;
    pedirArreglo(array, TAM);
    printf("Ingrese un elemento al que comparar los elementos del arreglo.\n");
    scanf("%d", &elem);
    cantidades = cuantos(array, TAM, elem);

    printf("Los elementos del arreglo se comparan de la siguiente manera con el número ingresado:\n");
    printf("Elementos menores a %d: %d\n", elem, cantidades.menores);
    printf("Elementos iguales a %d: %d\n", elem, cantidades.iguales);
    printf("Elementos mayores a %d: %d\n", elem, cantidades.mayores);
    
    return 0; 
}