/*
Var x,abs : Int;
{Pre: True}
if (x≥0)
skip
[] (x<0)
x = -x
fi
{Post: x≥0}
*/

#include <stdio.h>
#include <assert.h>

int pedirEntero(void)
{
    int temp;
    printf("Ingrese un número entero positivo.\n");
    scanf("%d", &temp);
    return temp; 
}

int main(void)
{
    int x;
    x = pedirEntero();
    if (x>=0)
    {
        ;
    } else if (x<0)
    {
        x = -x;
    }
    assert(x>=0);
    printf("|x| = %d\n", x);

    return 0;
}