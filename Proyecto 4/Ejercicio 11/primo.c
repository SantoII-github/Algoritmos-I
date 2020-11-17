#include <stdio.h>
#include <stdbool.h>

bool esPrimo(int n) //Función que devuelve un booleano que indica si el entero n que recibe es un número primo o no.
{
    int i = 2;
    bool esPrimo;
    if(n == 0 || n == 1) //Casos especiales.
    {
        esPrimo = false;    
    } else
    {
        esPrimo = true;
    }
    while (i < n)
    {
        if ((n % i) == 0)
        {
            esPrimo = false;
        }
        ++i;
    }
    return esPrimo;
}


int nesimo_primo(int N)
{
    int nprimo = 1;
    int cuentaPrimos = 0;
    
    while (cuentaPrimos < N)
    {
        if(esPrimo(nprimo))
        {
            ++cuentaPrimos;
        }
        ++nprimo;
    }
    return nprimo-1;
}

int pedirEntero(void)
{
    int temp;
    printf("Ingrese un número entero.\n");
    scanf("%d", &temp);
    return temp; 
}

/* Función main del subinciso a)
int main(void)
{
    int n, nprimo;
    n = pedirEntero();
    if(n<=0)
    {
        printf("No se puede calcular el n-ésimo primo si n es un número negativo.");
    } else 
    {
        nprimo = nesimo_primo(n);
        printf("El n-énesimo primo es: %d", nprimo);
    }

   return 0;
}
*/

int main(void)
{
    int n, nprimo;
    n = pedirEntero();
    while(n<=0)
    {
        printf("No se puede calcular el n-ésimo primo si n es un número negativo o 0. Por favor ingrese un entero positivo.\n");
        n = pedirEntero();
    }
    
    nprimo = nesimo_primo(n);
    printf("El n-énesimo primo es: %d\n", nprimo);

    return 0;
}
