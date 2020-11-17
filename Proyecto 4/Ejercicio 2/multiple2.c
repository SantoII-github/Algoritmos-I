/*
Var x, y, z, X, Y, Z : Int;
{Pre: x = X, y = Y, z = Z}
x ≔ Y;
y ≔ Y + X + Z;
z ≔ Y + X;
{Post: x = Y, y = Y + X + Z, z = Y + X}
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
    int x, y, z, X, Y, Z;
    x = pedirEntero();
    y = pedirEntero();
    z = pedirEntero();
    X = x;
    Y = y;
    Z = z;
    assert(x == X && y == Y && z == Z);
    x = Y;
    y = Y + X + Z;
    z = Y + X;
    assert(x == Y && y == Y + X + Z && z == Y + X);
    printf("El estado final es: [x→%d, y→%d, z→%d, X→%d, Y→%d, Z→%d]", x, y, z, X, Y, Z);

    return 0;
}