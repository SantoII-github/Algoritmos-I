/*
Var x, y, X, Y : Int;
{Pre: x = X, y = Y}
x ≔ x + 1;
y ≔ X + y;
{Post: x = X + 1, y = X + Y}
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
    int x, y, X, Y;
    x = pedirEntero();
    y = pedirEntero();
    X = x;
    Y = y;
    assert(x == X && y == Y);
    x = x + 1;
    y = X + y;
    assert(x == X + 1 && y == X + Y);
    printf("El estado final es: [x→%d, y→%d, X→%d, Y→%d]", x, y, X, Y);

    return 0;
}