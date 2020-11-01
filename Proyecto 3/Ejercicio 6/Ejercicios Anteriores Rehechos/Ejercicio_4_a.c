#include <stdio.h>

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

    if (x >= y) 
    {
        x = 0;
    } else if (x <= y)
    {
        x = 2;
    }
    
    printf("El estado final es x = %d, y = %d", x, y);

    return 0; 
}
//El programa 1e solo difiere en el estado inicial al 1f. Como pedimos el estado inicial al usuario, un sólo archivo es suficiente.