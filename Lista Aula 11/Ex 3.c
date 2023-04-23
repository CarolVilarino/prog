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
    int i, pontos=1, cor=0;
    /* Funciona até desligar ou o tecido acabar. */
    while (1)
    {
        for (i = 0; i < LARGURA_FAIXA; i++)
        {
            if (i >= pontos)
                moveAgulha ();
            else if(cor)
                pontoRolo1 ();
            else
                pontoRolo2();
        }
        pontos++;
        rolaTecido ();
        if(pontos>6){
            pontos=1;
            cor=!cor;
        }
    }
}
