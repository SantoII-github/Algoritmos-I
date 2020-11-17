/*
Var x, y, min : Int;
{Pre: True}
if x ≥ y
min = y;
[] x < y 
min = x;
fi
{Post: min ≤ x ∧ min ≤ y ∧ (min = x ∨ min = y)}
*/

#include <stdio.h>
#include <assert.h>

int pedirEntero(void)
{
    int temp;
    printf("Ingrese un número entero.\n");
    scanf("%d", &temp);
    return temp; 
}

int main(void)
{
    int x, y, min;
    x = pedirEntero();
    y = pedirEntero();
    
    if (x >= y)
    {
        min = y;
    } else if (x < y)
    {
        min = x;
    }
    assert(min <= x && min <= y && (min == x || min == y));

    printf("El estado final es [x->%d, y->%d, min->%d], donde min es el mínimo entre x e y", x, y, min);

    return 0;
}