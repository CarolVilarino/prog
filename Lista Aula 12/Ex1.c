#include <stdio.h>
#include <stdlib.h>

void segundosParaHMS (int total_segundos, int *h, int *m, int *s){
    *h=total_segundos/3600;
    *m=(total_segundos%3600)/60;
    *s=(total_segundos%3600)%60;
}

int main()
{
    int segundos, minutos, horas;

    scanf("%d", &segundos);

    segundosParaHMS(segundos, &horas, &minutos, &segundos);

    printf("%d:%d:%d\n", horas, minutos, segundos);

    return 0;
}
