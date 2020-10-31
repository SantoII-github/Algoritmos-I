#include <stdio.h>

int main(void)
{
    int x, y; 
    printf("Ingrese el valor de x\n");
    scanf("%d", &x);
    printf("Ingrese el valor de y\n");
    scanf("%d", &y);

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