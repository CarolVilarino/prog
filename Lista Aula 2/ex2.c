#include <stdio.h>
#include <stdlib.h>
#define USE_MATH_DEFINES
#include <math.h>



int main()
{
    double volume;
    int raio;

    scanf("%d", &raio);

    volume = (4.0/3.0)*M_PI*raio*raio*raio;

    printf("volume da esfera: %lf\n", volume);

    return 0;
}

