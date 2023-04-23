#include <stdio.h>
#include <stdlib.h>

/*um programa que aloque memória para um vetor de 10 posições do tipo float e
preencha-o com valores lidos do teclado. Depois de gerado o vetor, o programa deve mostrar o
conteúdo de todas as posições. O espaço deve então ser desalocado.*/

int main() //mainzada padrao
{
    float *vetor; //ponteiro pro endereço do primeiro espaço do vetor
    int i; //iterador padrãozinho

    vetor= (float*) malloc(sizeof(float)*10);
    //vetor alocado= (tipo da variavel*) chamada funcao malloc ((funcao para determinar bytes por tipo de variavel) * numero de casas do vetor)
    if(vetor==NULL) //caso haja insuficiencia de espaço na memoria a função retorna erro e encerra o programa
        return(1);
    for(i=0;i<10;i++){
        scanf("%f",&vetor[i]); //scanf basicao de cada casa do vetor, note que aqui ja pode ser usado a sintaxe padrao de vetor
    }
    for(i=0;i<10;i++){
        printf("%0.2f\n", vetor[i]); //printf basicao sem nenhuma firula tbm, tirando a determinação da quantidade de casas após a virgula o vetor mostra na tela
    }
    free(vetor); //libera o espaço alocado pelo vetor após usa utilização
    return 0;
}
