#include <stdio.h>
#include <stdbool.h>
#define TAM 3

struct asoc_t 
{
    int clave;
    int valor;
};

bool hay_asoc(int key, struct asoc_t a[], int tam) 
{
    int index = 0;
    bool res = false;
    struct asoc_t temp;

    while (index < tam && !res)
    {
        temp = a[index];
        if (temp.clave == key)
        {
            res = true;
        }
        ++index;
    }

    return res;
}

void pedirArreglo(struct asoc_t a[], int n_max) 
{
    int index = 0;
    struct asoc_t temp;
    while (index < n_max)
    {
        printf("Ingrese la clave de una asociación.\n");
        scanf("%d", &temp.clave);
        printf("Ingrese el valor de la asociación,\n");
        scanf("%d", &temp.valor);

        a[index] = temp;
        ++index;
    }
}

int main(void)
{
    struct asoc_t arreglo_asociados[TAM];
    int key;
    
    pedirArreglo(arreglo_asociados, TAM);
    printf("Ingrese la clave a buscar en el arreglo.\n");
    scanf("%d", &key);
    printf("Hay una asociación con la clave ingresada = %d\n", hay_asoc(key, arreglo_asociados, TAM));

    return 0;
}