#include <stdio.h>
#include <stdlib.h>

/*um programa que aloque mem�ria para um vetor de 10 posi��es do tipo float e
preencha-o com valores lidos do teclado. Depois de gerado o vetor, o programa deve mostrar o
conte�do de todas as posi��es. O espa�o deve ent�o ser desalocado.*/

int main() //mainzada padrao
{
    float *vetor; //ponteiro pro endere�o do primeiro espa�o do vetor
    int i; //iterador padr�ozinho

    vetor= (float*) malloc(sizeof(float)*10);
    //vetor alocado= (tipo da variavel*) chamada funcao malloc ((funcao para determinar bytes por tipo de variavel) * numero de casas do vetor)
    if(vetor==NULL) //caso haja insuficiencia de espa�o na memoria a fun��o retorna erro e encerra o programa
        return(1);
    for(i=0;i<10;i++){
        scanf("%f",&vetor[i]); //scanf basicao de cada casa do vetor, note que aqui ja pode ser usado a sintaxe padrao de vetor
    }
    for(i=0;i<10;i++){
        printf("%0.2f\n", vetor[i]); //printf basicao sem nenhuma firula tbm, tirando a determina��o da quantidade de casas ap�s a virgula o vetor mostra na tela
    }
    free(vetor); //libera o espa�o alocado pelo vetor ap�s usa utiliza��o
    return 0;
}
