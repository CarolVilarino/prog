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
    int i;
    /* Funciona até desligar ou o tecido acabar. */
    while (1)
    {
        for (i = 0; i < LARGURA_FAIXA; i++)
        {
            if (i == 1)
                pontoRolo1 ();
            else if (i == LARGURA_FAIXA-2)
                pontoRolo2 ();
            else
                moveAgulha ();
        }
            rolaTecido ();
    }
}
