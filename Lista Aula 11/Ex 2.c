#include <stdio.h>
#include <stdlib.h>
#define LARGURA_FAIXA 6 /* Largura da faixa de tecido, em cm. */


void pontoRolo1(){
    printf("V");
}
void pontoRolo2(){
    printf("A");
}
void moveAgulha(){
    printf(" ");
}
void rolaTecido(){
    printf("\n");
}
void main ()
{
    int i, vermelho=0;//a segunda variavel determina o numero de pontos vermelhos antes de pontos azuis no tecido.
    /* Funciona até desligar ou o tecido acabar. */
    while (1)
    {
        for (i = 0; i < LARGURA_FAIXA; i++)
        {
            if (i >= vermelho)
                pontoRolo2 ();
            else
                pontoRolo1 ();
        }
        vermelho++; //a cada linha tecida o numero de pontos vermelhos aumenta até chegar em 6, sendo reiniciado antes do encerramento do loop.
        rolaTecido ();
        if(vermelho>LARGURA_FAIXA)
            vermelho=0;
    }
}
