#include <stdio.h>
#define TAM 5

struct datos_t 
{
    float maximo;
    float minimo;
    float promedio;
};

struct datos_t stats(float a[], int tam)
{
    int index, sum;
    struct datos_t stats;
    index = 0;
    sum = 0;
    
    if (a[0] > a[1]) //Calcula el máximo y el mínimo entre los primeros dos elementos para simplificar el while.
    {
        stats.maximo = a[0];
        stats.minimo = a[1];
    } else
    {
        stats.maximo = a[1];
        stats.minimo = a[0];
    }
    

    while (index < tam)
    {
        if (a[index] > stats.maximo) //Reemplaza el máximo si el elemento en el índice actual es mayor al que hay guardado.
        {
            stats.maximo = a[index];
        }
        if (a[index] < stats.minimo) //Reemplaza el mínimo si el elemento en el índice actual es menor al que hay guardado.
        {
            stats.minimo = a[index];
        }
        sum = sum + a[index]; //Calcula la suma de los elementos para usarla en el promedio.
        index = index + 1;
    }
    stats.promedio = sum / tam;
    
    return stats;
}

float pedirFloat(void)
{
    float temp;
    printf("Ingrese un número.\n");
    scanf("%f", &temp);
    return temp; 
}

void pedirArregloFloat(float a[], int n_max)
{
    int i, temp;
    i = 0;
    while (i < n_max)
    {
        temp = pedirFloat();
        a[i] = temp;
        i = i + 1;
    }
}

int main(void)
{
    float array[TAM];
    struct datos_t valores;
    pedirArregloFloat(array, TAM);
    valores = stats(array, TAM);
    printf("Las estadísticas del arreglo son las siguientes:\n");
    printf("Máximo del arreglo: %f\n", valores.maximo);
    printf("Mínimo del arreglo: %f\n", valores.minimo);
    printf("Promedio del arreglo: %f\n", valores.promedio);

    return 0;
}
