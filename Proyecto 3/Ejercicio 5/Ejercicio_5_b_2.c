#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int x, i, temp, iteracion; 
    bool res;
    printf("Ingrese el valor de x.\n");
    scanf("%d", &x);
    printf("Ingrese el valor de i.\n");
    scanf("%d", &i);
    printf("Ingrese el valor de res.\n");
    scanf("%d", &temp);
    res = temp;

    iteracion = -1;
    i = 2;
    res = true;
    while (i < x && res) //mientras i sea menor a x y res = true = 1
    {
        res = res && (x % i) != 0; // res y i no divide a x
        i = i + 1;
        iteracion = iteracion + 1;
        printf("El estado Sigma%d,1 es: x->%d, i->%d, res->%d\n", iteracion, x, i, res);
    }

    return 0;
}
/*
Estado Inicial           | Sigma0,1               | Sigma1,1                | Sigma2,1          
x->5, i->0, res->False   | x->5, i->0, res->True  | x->5, i->0, res->True   | x->5, i->0, res->True
x->8, i->4, res->True    | x->8, i->3, res->False |                         | 

3) Las variables i y res que ingresamos al programa no son relevantes, porque se definen como i = 2 y res = true antes de ejecutar otras instrucciones.
El programa toma un número natural mayor a 2 y opera hasta encontrarse con su divisor mínimo. Si tiene divisor, el valor de i en el estado final es el divisor mínimo -1.
Si es un número primo el valor de i en el estado final es el divisor mínimo. Si ingresamos un número entero x menor igual a 2 el programa solo cambia las variables i = 2 y res = true
*/