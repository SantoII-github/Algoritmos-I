#include <stdio.h>
#include <assert.h>

int main(void)
{
    int i; 
    printf("Ingrese el valor de i.\n");
    scanf("%d", &i);

    assert(i >= 0);

    while (i != 0)
    {
        i = i - 1;
        printf("Valor actual de i = %d\n", i);
    }

    return 0;
}