#include <stdio.h>

typedef struct _persona
{
    char *nombre;
    int edad;
    float altura;
    float peso;
} persona_t;

float peso_promedio(persona_t arr[], unsigned int longitud)
{
    unsigned int index = 0;
    int sum = 0;
    persona_t temp;
    while (index < longitud)
    {
        temp = arr[index];
        sum = sum + temp.peso;
        ++index;
    }
    return sum / longitud;
}

persona_t persona_de_mayor_edad(persona_t arr[], unsigned int longitud)
{
    unsigned int index = 0;
    persona_t temp;
    persona_t personaMayorEdad = arr[0];
    
    while (index < longitud)
    {
        temp = arr[index];
        if (temp.edad > personaMayorEdad.edad)
        {
            personaMayorEdad = arr[index];
        }
        ++index;
    }
    return personaMayorEdad;
}

persona_t persona_de_menor_altura(persona_t arr[], unsigned int longitud)
{
    unsigned int index = 0;
    persona_t temp;
    persona_t personaMenorAltura = arr[0];

    while (index < longitud)
    {
        temp = arr[index];
        if (temp.altura < personaMenorAltura.altura)
        {
            personaMenorAltura = arr[index];
        }
        ++index;
    }
    return personaMenorAltura;
}

int main(void) 
{
persona_t p1 = {"Paola", 21, 1.85, 75};
persona_t p2 = {"Luis", 54, 1.75, 69};
persona_t p3 = {"Julio", 40, 1.70, 80};
unsigned int longitud = 3;
persona_t arr[] = {p1, p2, p3};
printf("El peso promedio es %f\n", peso_promedio(arr, longitud));
persona_t p = persona_de_mayor_edad(arr, longitud);
printf("El nombre de la persona con mayor edad es %s\n", p.nombre);
p = persona_de_menor_altura(arr, longitud);
printf("El nombre de la persona con menor altura es %s\n", p.nombre);

return 0;
}