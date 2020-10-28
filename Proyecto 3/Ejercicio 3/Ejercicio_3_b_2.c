#include <stdio.h>
#include <assert.h>

int main(void)
{
    int x, y;
    printf("Ingrese el valor de x.\n");
    scanf("%d", &x);
    printf("Ingrese el valor de y.\n");
    scanf("%d", &y);
    assert(x == 2 && y == 5);

    x = x + y;
    y = y + y;
    
    printf("Estado final: x = %d, y = %d", x, y);

    return 0; 
}

/*
Programa        | Usuario ingresa un σ0  | Produce una salida σ
1.b Ejecución 1 | x->1, y->2             | x->3, y->4
1.b Ejecución 2 | x->2, y->5             | x->7, y->10
1.b Ejecución 3 | x->7, y->2             | x->9, y->4
*/