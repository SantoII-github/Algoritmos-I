#include <stdio.h>
#include <assert.h>

int main(void)
{
    int x;
    printf("Ingrese el valor de x.\n");
    scanf("%d", &x);
    assert(x == 1);

    x = 5;
    
    printf("Estado final: x = %d", x);

    return 0; 
}

/*
Programa        | Usuario ingresa un σ0  | Produce una salida σ
1.a Ejecución 1 | x->1                   | x->5
1.a Ejecución 2 | x->4                   | x->5
1.a Ejecución 3 | x->10                  | x->5
*/