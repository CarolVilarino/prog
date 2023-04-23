//============================================================================
// CSF13 - 2022-2 - TRABALHO 1
//----------------------------------------------------------------------------
// Gabriel Antunes Ferraz - 1795970

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "trabalho1.h"
#define ACERTO_COMUM 1
#define ALVO_COBERTO 2
#define DISPARO_COBERTO 3

//Função 1.

unsigned int testaDisparo (int disparo, float x, float y, float raio){

    unsigned int alvo, i_alvo, acertos_disparo=0; //numero de alvos seguido do contador de alvos comparados, um contador de acertos zerado para poder retornar ao fim da função a quantidade de alvos acertados por disparo
    float x_alvo, y_alvo, raio_alvo; //coordenada e raio de cada alvo
    float distancia_x, distancia_y, distancia_pontos, soma_raios; //variaveis utilizadas para comparar posições do disparo e alvo

    alvo = pegaNAlvos();

    for(i_alvo=0;i_alvo<alvo;i_alvo++){ //a cada repetição, um alvo diferente é testado

        x_alvo=pegaXAlvo(i_alvo); //chamando funções para atribuir valores aos dados do alvo atual
        y_alvo=pegaYAlvo(i_alvo);
        raio_alvo=pegaRaioAlvo(i_alvo);

        soma_raios=raio+raio_alvo; //começando pelo mais facil, apenas somar o valor dos dois raios para saber a distância mínima de contato

        if(x>x_alvo)    //if simples para evitar comprimentos negativos
            distancia_x=x-x_alvo;
        else
            distancia_x=x_alvo-x;
        if(y>y_alvo)
            distancia_y=y-y_alvo;
        else
            distancia_y=y_alvo-y; //tendo a diferença entre as duas coordenadas, é possível achar o comprimento da distância dos centros

        distancia_x=distancia_x*distancia_x;//elevando ois dois valores ao quadrado, para tirar a hipotenusa dos dois catetos
        distancia_y=distancia_y*distancia_y;

        distancia_pontos=distancia_y+distancia_x; //na teoria essa distancia ainda esta ao quadrado e precisa ser feito a raiz dela

        distancia_pontos=sqrtf(distancia_pontos); //funçao destinada ao tipo float, sem precisar converter variavel depois


        if(distancia_pontos<=soma_raios){ //registrando o tipo de disparo caso tenha acertado o alvo indicado
            if((distancia_pontos+raio_alvo)<raio){ //o alvo sera coberto caso a soma entre seu raio e a distancia entre os centros nao ultrapasse o raio do disparo
                registraAcerto(ALVO_COBERTO, disparo, i_alvo);
                acertos_disparo++;
            }
            else if((distancia_pontos+raio)<raio_alvo){ //o disparo sera coberto caso a soma entre seu raio e a distancia entre os centros nao ultrapasse o raio do alvo
                registraAcerto(DISPARO_COBERTO, disparo, i_alvo);
                acertos_disparo++;
            }
            else{
                registraAcerto(ACERTO_COMUM, disparo, i_alvo);
                acertos_disparo++;
            }
        }
    }

    return(acertos_disparo); //função retorna a quantidade de alvos acertados por disparo

}
/*-------------------------------------------------------------------------------*/
//Função 2.
unsigned int testaDisparos (){

    unsigned int disparo, i_disparo, total_acertos=0;// bem semelhante a função testaDisparo, declarei o total de disparos, o disparo atual e o total de acertos
    float x_disparo, y_disparo, r_disparo;// coordenadas  e raio do disparo

    disparo=pegaNDisparos();

    for(i_disparo=0;i_disparo<disparo;i_disparo++){//chamando funções num loop para pegar os valores de disparo
        x_disparo=pegaXDisparo(i_disparo);
        y_disparo=pegaYDisparo(i_disparo);
        r_disparo=pegaRaioDisparo(i_disparo);

        total_acertos=total_acertos+testaDisparo(i_disparo,x_disparo,y_disparo,r_disparo);// somando os valores retornados a uma variavel para saber quantos alvos foram atingidos no total por todos os tiros
    }

    return(total_acertos);// função retorna o total de acertos

}

/*-------------------------------------------------------------------------------*/
//Função 3.

unsigned short pegaCampo (unsigned short seq, int pos, int nbits){

    unsigned short sequencia_alterada;
    sequencia_alterada=seq<<pos;
    sequencia_alterada=sequencia_alterada>>(16-nbits);
    return(sequencia_alterada);
}
