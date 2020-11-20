#include <stdio.h>
#define TAM 5

struct sum_t 
{
    int total_multiplo;
    int total_no_multiplo;
};

struct sum_t suma_multiplo(int mul, int array[], int tam) 
{
    struct sum_t total;
    total.total_multiplo = 0;
    total.total_no_multiplo = 0;
    int index = 0;

    while (index < tam)
    {
        if (array[index] % mul == 0)                                    //Si el resto de la división entera es 0, array[index] es múltiplo de mul.
        {
            total.total_multiplo = total.total_multiplo + array[index];
        } else if (array[index] % mul != 0)                             //Si el resto de la división entera es distinto de 0, array[index] no es múltiplo de mul.
        {
            total.total_no_multiplo = total.total_no_multiplo + array[index];
        }
        ++index;
    }
    return total;
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
    int mul, array[TAM];
    struct sum_t total_sum;
    pedirArreglo(array, TAM);
    mul = pedirEntero();

    total_sum = suma_multiplo(mul, array, TAM);
    printf("El resultado es:\n");
    printf("Suma de los múltiplos de %d = %d\n", mul, total_sum.total_multiplo);
    printf("Suma de los no múltiplos de %d = %d\n", mul, total_sum.total_no_multiplo);

    return 0;
}