#include <stdio.h>
#include <stdlib.h>

int main(){

    int segundos, minutos, horas, dias, resto;

    scanf("%d", &segundos);

    minutos = segundos/60;
    resto = segundos%60;

    horas = minutos/60;
    minutos = minutos%60;

    dias = horas/24;
    horas = horas%24;


    printf("%d segundos sao %d dias, %d horas, %d minutos e %d segundos.\n", segundos, dias, horas, minutos, resto);

    return 0;
}
