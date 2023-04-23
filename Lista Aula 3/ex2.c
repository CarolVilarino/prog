#include <stdio.h>
#include <stdlib.h>

int main()
{
    int entrada, unidade, dezena, centena;

    scanf("%d", &entrada);

    centena = entrada - (entrada%100);
    dezena = entrada%100-((entrada%100)%10);
    unidade = (entrada%100)%10;

    centena = entrada/100;
    unidade = unidade*100;

    entrada = unidade+dezena+centena;

    printf("%d", entrada);

    return 0;
}
