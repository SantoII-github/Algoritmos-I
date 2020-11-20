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
    
    assert(x == X && y == Y && X > Y); //Precondición
    
    x = Y + X;
    y = X - Y;
    
    assert(x == X + Y &&  y == x - 2 * Y); //Postcondición
    
    printf("Los valores finales son: x = %d, y = %d, X = %d, Y = %d", x, y, X, Y);

    return 0;
}