#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* um programa que aloque memória para dois vetores, com tamanhos diferentes, dados pelo
usuário. Os vetores devem ser preenchidos com valores aleatórios no intervalo [0, 10]. O programa
deve então criar um terceiro vetor, capaz de conter todos os elementos Vi*Vj, onde Vi é um elemento
do primeiro vetor e Vj é um elemento do segundo vetor. A multiplicação elemento-a-elemento dos dois
vetores deve ser calculada, e os valores obtidos devem ser apresentados. */

int* alocarVetorInt(int tam){//funcao para alocar vetores
    int *vet;//ponteiro para endereco a ser alocado

    vet=(int*) malloc(sizeof(int)* tam);

    return(vet);
}

void randomizaVetorInt(int vet[], int tam){//funcao retornando vetor com valores aleatorios passando o vetor por parametro

    int i;

    for(i=0;i<tam;i++){
        vet[i]=rand()%10+1;
    }
}


int main(){
    int *vet1, *vet2, *vet3; //3 vetores que serão alocados dinamicamente, sendo vet3 o resultado de vet1*vet2
    int index1, index2, index3, i;//numero de elementos de cada vetor e iterador para o for

    scanf("%d", &index1);//entrada do numero de elementos de vet1
    scanf("%d", &index2);//entrada do numero de elementos de vet2

    vet1=alocarVetorInt(index1);//chamada de funcao para alocar memoria pro vet1
    if(vet1==NULL)//caso a funcao nao retorne um endereco
        return 1;

    vet2=alocarVetorInt(index2);//chamada de funcao para alocar memoria pro vet2
    if(vet2==NULL)//ver comentario da linha 37
        return 1;

    srand(time(NULL));

    randomizaVetorInt(vet1,index1);//chamada de funcao para preencher vet1 com valores aleatorios

    randomizaVetorInt(vet2,index2);//chamada de funcao para preencher vet1 com valores aleatorios


    if(index2>index1)//if simples para determinar o numero de elementos de vet3
        index3=index1;
    else if(index2<=index1)
        index3=index2;

    vet3=alocarVetorInt(index3);
    if(vet3==NULL)
        return 1;

    for(i=0;i<index3;i++){
        vet3[i]=vet1[i]*vet2[i];//multiplicacao elemento a elemento
    }

    for(i=0;i<index3;i++)
    printf("%d\n", vet3[i]);//mostra na tela valores obtidos

    free(vet1);//liberacao do espaco alocado de cada vetor
    free(vet2);
    free(vet3);


    return 0;
}
