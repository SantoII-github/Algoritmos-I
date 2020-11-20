#include <stdio.h>
#include <assert.h>
#define MAX_COLOR_ID 16777215

struct color_t 
{
    int rojo;
    int verde;
    int azul;
};

struct color_t calcular_color(int color_id)
{
    assert(color_id >= 0 && color_id <= 16777215);
    struct color_t rgb;

    rgb.rojo = (color_id % 65536) % 256;
    rgb.verde = (color_id % 65536) / 256;
    rgb.azul = color_id / 65536;

    return rgb;
}

void imprimirColor(struct color_t color_id)
{
    printf("Los componentes del color son:\n");
    printf("Rojo = %d\n", color_id.rojo);
    printf("Verde = %d\n", color_id.verde);
    printf("Azul = %d\n", color_id.azul);
}

int main(void)
{
    int color_id;
    struct color_t color_rgb;

    printf("Ingrese un identificador de color\n");
    scanf("%d", &color_id);
    
    if (color_id >= 0 && color_id <= 16777215)
    {
        color_rgb = calcular_color(color_id);
        imprimirColor(color_rgb);
    } else
    {
        printf("El identificador de color ingresado es un número negativo o mayor a 16777215. Por favor ingrese un identificador válido.\n");
    }
    
    return 0;
}