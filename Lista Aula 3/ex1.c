#include <stdio.h>
#include <stdlib.h>

int main()
{
    double valgas, valeta, kmgas, kmeta, comparavalor, compararendimento;

    printf("Digite o valor do etanol: ");
    scanf("%lf", &valeta);

    printf("Digite o valor da gasolina: ");
    scanf("%lf", &valgas);

    printf("Digite o rendimento do etanol em km por litro: ");
    scanf("%lf", &kmeta);

    printf("Digite o rendimento da gasolina em km por litro: ");
    scanf("%lf", &kmgas);

    compararendimento = kmeta/kmgas;

    comparavalor = valeta/valgas;

    if(compararendimento>comparavalor)
        printf("melhor abastecer com etanol\n");
    else
        printf("melhor abastecer com gasolina\n");

    return 0;
}
