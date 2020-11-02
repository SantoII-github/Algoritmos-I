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
    int x, y, z;
    x = pedirEntero();
    y = pedirEntero();
    printf("Ingrese un booleano (0 para False, 1 para True)\n");
    scanf("%d", &z);
    printf("%d", z);
    
    printf("Con los valores ingresados los resultados de las siguientes expresiones son:\n");
    printf("x = D₁ + D₂ ∨ y = D₁ + D₂ ∨ z = %d\n", x == 7 + 8 || y == 7 + 8 || z);
    printf("(7 + 8 + x) mod 3 = %d\n", (7 + 8 + x) % 3);
    printf("x * 7 + y * 8 = %d\n", x * 7 + y * 8);
    printf("x != 0 ∧ 0 ≤ (D₁ - D₂) / x ∧ ¬z = %d\n", x != 0 && 0 <= (7 - 8)/x && !z);


    return 0;
}

/*
| Expresión                                  | ⟦x→3, y→6, z→True⟧ | ⟦x→0, y→3, z→False⟧ |
|:----------------------------------------------|:----------------------------------:|:------------------------------------|
| x = D₁ + D₂ ∨ y = D₁ + D₂ ∨ z  |        1           |        0            |
| (D₁ + D₂ + x) mod 3                  |       0           |        0             |
| x * D₁ + y * D2                           |       69          |         24            |
| x ≠ 0 ∧ 0 ≤ (D₁ - D₂) / x ∧ ¬z   |       0           |         0            |
*/