/*
Var x, y, xaux, yaux : Int;
{Pre: True}
xaux≔x;
yaux≔y;
x≔yaux;
y≔xaux;
{Post: x=yaux ∧ y=xaux}
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
    int x, y, xaux, yaux;
    x = pedirEntero();
    y = pedirEntero();
    xaux = x;
    yaux = y;
    x = yaux;
    y = xaux;
    assert(x==yaux && y==xaux);
    printf("Al intercambiar las variables x e y obtenemos: [x→%d, y→%d]\n", x, y);

    return 0;
}