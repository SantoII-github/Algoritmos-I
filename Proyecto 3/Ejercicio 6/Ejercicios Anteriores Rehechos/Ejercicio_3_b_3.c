#include <stdio.h>
#include <assert.h>

int pedirEntero(void)
{
    int temp;
    printf("Ingrese un número entero\n");
    scanf("%d", &temp);
    return temp; 
}

int main(void)
{
    int x, y;
    x = pedirEntero();
    y = pedirEntero();
    assert(x == 2 && y == 5);    

    y = y + y;
    x = x + y;
    
    printf("Estado final: x = %d, y = %d", x, y);

    return 0; 
}

/*
Programa        | Usuario ingresa un σ0  | Produce una salida σ
1.b Ejecución 1 | x->2, y->5             | x->12, y->10
1.b Ejecución 2 | x->3, y->2             | x->7, y->4
1.b Ejecución 3 | x->5, y->10            | x->25, y->20
*/