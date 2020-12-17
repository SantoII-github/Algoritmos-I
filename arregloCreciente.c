#include <stdbool.h>
#include <stdio.h>
#define N 5


int main(void)
{
    int A[N];
    A[0] = 1;
    A[1] = 2;
    A[2] = 9;
    A[3] = 4;
    A[4] = 5;
    bool s, r;
    int n, m;

    s = true;
    n = 0;
    while (n != N)
    {
        r = true;
        m = 0;
        while(m != n)
        {
            r = r && A[m] < A[n];
            m = m + 1;
        }
        s = s && r;
        n = n + 1;
    }
    printf("Los elementos del arreglo están en orden creciente: %d\n", s);
    return 0;
}