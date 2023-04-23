#include <stdio.h>
#include <stdlib.h>

int main()
{
    int hini, hfin;

    scanf("%d", &hini);
    scanf("%d", &hfin);

    if(hini<24 && hini>=0 && hfin<24 && hfin>=0){
        if(hini<hfin)
            printf("o jogo durou %d horas\n", hfin-hini);
        else if(hini>hfin)
            printf("o jogo durou %d horas\n",24-hini+hfin);
        else
            printf("o jogo durou 24 horas\n");
    }
    else
        printf("valores invalidos");

    return 0;
}
