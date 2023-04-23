#include <stdio.h>
#include <stdlib.h>

int main()//ex2
{
    int entrada_nascimento_dia, entrada_nascimento_mes, entrada_nascimento_ano, entrada_hoje_dia, entrada_hoje_mes, entrada_hoje_ano, idade;

    printf("favor digitar os meses com seus respectivos numeros de ddmmaaaa\n");
    printf("em que ano voce nasceu? ");
    scanf("%d", &entrada_nascimento_ano);
    printf("em que mes de %d? ",entrada_nascimento_ano);
    scanf("%d", &entrada_nascimento_mes);
    printf("em que dia de %d? ", entrada_nascimento_mes);
    scanf("%d", &entrada_nascimento_dia);

    printf("que dia do mes e hoje? ");
    scanf("%d", &entrada_hoje_dia);
    printf("de que mes? ");
    scanf("%d", &entrada_hoje_mes);
    printf("de que ano? ");
    scanf("%d", &entrada_hoje_ano);

    idade=entrada_hoje_ano-entrada_nascimento_ano;

    if(entrada_hoje_dia<entrada_nascimento_dia){
        if(entrada_hoje_mes<=entrada_nascimento_mes){
            idade=idade-1;
        }
    }

    printf("voce tem %d anos.\n", idade);



    return 0;
}
