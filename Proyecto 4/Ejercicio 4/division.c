#include <stdio.h>
#include <assert.h>

int pedirEntero(void)
{
    int temp;
    printf("Ingrese un número entero positivo.\n");
    scanf("%d", &temp);
    return temp; 
}

struct div_t 
{
    int cociente;
    int resto;
};

struct div_t division(int x, int y)
{
    assert(x >= 0 && y > 0);
    struct div_t div;
    div.cociente = x / y;
    div.resto = x % y;

    return div; 
}

int main(void)
{
    int x, y;
    struct div_t div;
    x = pedirEntero();
    y = pedirEntero();
    div = division(x, y);
    printf("La división entera de x por y tiene como resultado\n Cociente: %d\n Resto: %d\n", div.cociente, div.resto);

    return 0; 
}