#include <stdlib.h>
#include <stdio.h>
void arrumaImagem (Imagem1C* img, int ** rotulos);//funcao para remover pontos indesejados e preencher lacunas nos objetos
void forwardScan(Imagem1C* img, int ** rotulos, int* r );
void backwardScan ( Imagem1C* img, int ** rotulos, int* r );
void binariza(Imagem1C* img, int limiar) // funcao para binarizar a imagem para rotulacao dos componentes mais tarde
{
    int i, j;
    for (i = 0; i < img->altura; i++)
        for (j = 0; j < img->largura; j++)
        {
            if (img->dados[i][j] >= limiar)
                img->dados[i][j] = 255;
            else
                img->dados[i][j] = 0;
        }
    salvaImagem1C(img, "out.bmp");
}


void rotulaObjetos (Imagem1C* img, int *r ){//funcao para rotular os componentes da imagem


    int **rotulos, i;
    rotulos = (int **)malloc(img->altura * sizeof(int*));
    for(i=0; i<img->altura;i++)
        rotulos[i] = (int*)malloc(img->largura * sizeof(int));

    arrumaImagem (img, rotulos);

    forwardScan(img, rotulos, r);
    backwardScan(img, rotulos, r);
    salvaImagem1C(img, "outxx.bmp");
}

// Função auxiliar para rotular objetos, iniciando pela esquerda-cima
void forwardScan(Imagem1C* img, int ** rotulos, int* r ) {

    int i, j, min;

    for(i = 1; i <= img->altura - 1; i++) {
        for(j = 1; j <= img->largura - 1; j++) {
            /**
                CASO 1: m[i][j] == 0 --> nada acontece

                CASO 2: m[i][j] != 0 && vizinhança == 0 --> m[i][j] = r && r++;

                CASO 3: m[i][j] != 0 && algum vizinho != 0 --> m[i][j] = min(V[k][l])
            **/

            if( img->dados[i][j] != 0  ) {
                if( img->dados[i-1][j-1] == 0 && img->dados[i-1][j] == 0 && img->dados[i-1][j+1] == 0 && img->dados[i][j-1] == 0 ) {
                    img->dados[i][j] = *r;
                    (*r)++;
                }
                else {
                    min = *r;
                    if( img->dados[i-1][j-1] < min && img->dados[i-1][j-1]!=0 )
                        min = img->dados[i-1][j-1];
                    if( img->dados[i-1][j] < min && img->dados[i-1][j]!=0 )
                        min = img->dados[i-1][j];
                    if( img->dados[i-1][j+1] < min && img->dados[i-1][j+1] != 0)
                        min = img->dados[i-1][j+1];
                    if( img->dados[i][j-1] < min && img->dados[i][j-1] !=0 )
                        min = img->dados[i][j-1];
                    img->dados[i][j] = min;
                }
            }
        }
    }
}

// Função auxiliar para rotular objetos, iniciando pela direita-baixo
void backwardScan ( Imagem1C* img,int ** rotulos, int* r ){
    int i, j, min;

    for(i = img->altura - 1; i > 1; i--) {
        for(j = img->largura - 1; j > 1 ; j--) {
            if( img->dados[i][j] != 0 ) {
                if( img->dados[i+1][j+1] == 0 && img->dados[i+1][j] == 0 && img->dados[i+1][j-1] == 0 && img->dados[i][j+1] == 0  ) {
                    img->dados[i][j] = *r;
                    (*r)++;
                }
                else {
                    min = *r;
                    if( img->dados[i+1][j+1] < min && img->dados[i+1][j+1] !=0 )
                        min = img->dados[i+1][j+1];
                    if( img->dados[i+1][j] < min && img->dados[i+1][j] != 0)
                        min = img->dados[i+1][j];
                    if( img->dados[i+1][j-1] < min && img->dados[i+1][j-1] !=0 )
                        min = img->dados[i+1][j-1];
                    if( img->dados[i][j+1] < min && img->dados[i][j+1]!=0 )
                        min = img->dados[i][j+1];
                    img->dados[i][j] = min;
                }
            }
        }
    }
}

void contaIngredientes (Imagem1C* img, int* n_circulos, int* n_retangulos)
{
//primeiro, identifcar o que sao objetos, ignorando ruidos ou 'buraquinhos' no objeto
//depois, identifcar quais deles sao retangulos, possuindo bordas e quais circulos, nao possuindo bordas, e assim somar n-retangulos e n-circulos
    int r=1, i, j, contret, contcirc = 0;

    *n_circulos = 0;
    *n_retangulos = 0;

    binariza(img, 123);
    rotulaObjetos(img, &r);
    contret = testaForma(img,i,j);
    for(i = 1; i <= img->altura - 1; i++) {
        for(j = 2; j <= img->largura - 1; j++) {
          if(){
            contcirc ++;
            contret --;
            
              }
            }}
}

void arrumaImagem (Imagem1C* img, int ** rotulos)
{
    int i, j;
    for(i = 2; i <= img->altura - 2; i++) {
        for(j = 2; j <= img->largura - 2; j++) {
                if((img->dados[i-1][j-1] != 0 && img->dados[i-1][j] != 0 && img->dados[i-1][j+1] != 0 && img->dados[i][j+1] != 0) 
                  || (img->dados[i-1][j] != 0 && img->dados[i-1][j+1] != 0 && img->dados[i][j+1] != 0 && img->dados[i+1][j+1] != 0) 
                  || (img->dados[i-1][j+1] != 0 && img->dados[i][j+1] != 0 && img->dados[i+1][j+1] != 0 && img->dados[i+1][j] != 0) 
                  || (img->dados[i][j+1] != 0 && img->dados[i+1][j+1] != 0 && img->dados[i+1][j] != 0 && img->dados[i+1][j-1] != 0) 
                  || (img->dados[i+1][j+1] != 0 && img->dados[i+1][j] != 0 && img->dados[i+1][j-1] != 0 && img->dados[i][j-1] != 0) 
                  || (img->dados[i+1][j] != 0 && img->dados[i+1][j-1] != 0 && img->dados[i][j-1] != 0 && img->dados[i-1][j-1] != 0) 
                  || (img->dados[i+1][j-1] != 0 && img->dados[i][j-1] != 0 && img->dados[i-1][j-1] != 0 && img->dados[i-1][j] != 0) 
                  || (img->dados[i][j-1] != 0 && img->dados[i-1][j-1] != 0 && img->dados[i-1][j] != 0 && img->dados[i-1][j+1] != 0))
                    rotulos[i][j] = 255;
                else
                    rotulos[i][j] = 0;

        }
    }
    for(i = 1; i<=img->altura-1;i++) {
        for(j = 1; j <= img->largura-1; j++) {
            img->dados[i][j] = rotulos[i][j];
        }
    }

    salvaImagem1C(img, "outx.bmp");
}

  int testaForma(Imagem1C* img, int i, int j)
{
    int larguraInicio = j, larguraFinal, tamanhoInicio = i, tamanhoFinal, controleTamanho = 0, larguraTot = 0, tamanhoTot = 0;
    int contobj = 0;
    while(controleTamanho < 4)
    {
        switch(img->dados[i][j])
        {
        case 255:
            larguraTot++;
            controleTamanho = 0;
            larguraFinal = j;
            contobj++;
            break;
        case 0:
            controleTamanho++;
            break;
        }
        j++;
    }
    controleTamanho = 0;
    while(controleTamanho < 4)
    {
        switch(img->dados[i][larguraInicio+(larguraFinal/2)])
        {
        case 255:
            tamanhoTot++;
            controleTamanho = 0;
            tamanhoFinal = i;
            contobj++;
            break;
        case 0:
            controleTamanho++;
            break;
        }
        i++;
    }
    controleTamanho = 0;
    int k = tamanhoInicio+(tamanhoFinal/2), m = larguraInicio+(larguraFinal/2);
    while(controleTamanho < 4)
    {
        switch(img->dados[k][m])
        {
        case 255:
            controleTamanho = 0;
            larguraInicio = k;
            break;
            contobj++;
        case 0:
            controleTamanho++;
            break;
        }
        m--;
    }
    larguraTot = m * 2;

    for 




  return (contobj);
}



#include "trabalho3.h"
#include <stdlib.h>
#include <stdio.h>
void binariza(Imagem1C* img, int limiar)
{
  // binariza a img, para assim ela ficar em preto (0) - o fundo e branco (255)
    int i, j;
    for (i = 0; i < img->altura; i++)
        for (j = 0; j < img->largura; j++)
        {
            if (img->dados[i][j] >= limiar)
                img->dados[i][j] = 255;
            else
                img->dados[i][j] = 0;
        }
    salvaImagem1C(img, "out.bmp");
}

int retornaMedia(int a, int b, int c, int d, int e, int limiar)
{
  // faz o filtro da media
    int seguraMedia;

    seguraMedia = (a+b+c+d+(e*limiar))/(4+limiar);
    return seguraMedia;

}

void mescla(Imagem1C* img, int limiar)
{
    int i, j;

    for (i=1; i<img->altura-1; i++) //percorre a imagem de cima pra baixo
    {
        for (j=1; j<img->largura-1; j++) //percorre a imagem da esquerda pra direita
        {
            img->dados[i][j] = retornaMedia(img->dados[i-1][j],img->dados[i][j-1],img->dados[i+1][j],img->dados[i][j+1],img->dados[i][j], limiar);
        }
    }
    salvaImagem1C(img, "outxx.bmp");
}


int testaForma(Imagem1C* img, int i, int j){
    int larguraInicio = j, larguraFinal, tamanhoInicio = i, tamanhoFinal, controleTamanho = 0, larguraTot = 0, tamanhoTot = 0, area, filling = 0;


    while(controleTamanho < 4)
    {

        switch(img->dados[i][j])
        {
        case 255:
            larguraTot++;
            controleTamanho = 0;
            larguraFinal = j;
            break;
        case 0:
            controleTamanho++;
            break;
        }
        j++;

    }

    controleTamanho = 0;
    while(controleTamanho < 4)
    {

        switch(img->dados[i][larguraInicio+(larguraTot/2)])
        {
        case 255:
            tamanhoTot++;
            controleTamanho = 0;
            tamanhoFinal = i;
            break;
        case 0:
            controleTamanho++;
            break;
        }
        i++;

    }

    controleTamanho = 0;
    int k = tamanhoInicio+(tamanhoTot/2), m = larguraInicio+(larguraTot/2);
    larguraTot = 0;

    while(controleTamanho < 4)
    {
        switch(img->dados[k][m])
        {
        case 255:
            larguraTot++;
            controleTamanho = 0;
            larguraInicio = m;
            break;
        case 0:
            controleTamanho++;
            break; 
        }
        m--;
       }

    larguraTot = larguraTot * 2;

    area = 0;

    for(i = tamanhoInicio-1; i<= tamanhoFinal+1; i++){
        for(j=larguraInicio-1; j<= larguraFinal+1; j++){
            switch(img->dados[i][j]){
        case 255:
            area++;
            filling++;
            img->dados[i][j] = 0;
            break;
        case 0:
            area++;
            break;
        }
        }
    }
    if(larguraTot < 7 || tamanhoTot < 7)
        return 2;


    if((filling*100)/area > 73){

        return 1;
    }
    else{

        return 0;}

}


void contaIngredientes (Imagem1C* img, int* n_circulos, int* n_retangulos)
{
// primeiro, identifcar o que sao objetos, ignorando ruidos ou 'buraquinhos' no objeto
// depois, identifcar quais deles sao retangulos, possuindo bordas e quais circulos, nao possuindo bordas, e assim somar n-retangulos e n-circulos
    int i, j, resutado;
    *n_circulos = 0;
    *n_retangulos = 0;
    mescla(img, 2);
    binariza(img, 100);
    mescla(img, 2);
    mescla(img, 2);
    binariza(img, 190);

    for (i=4; i<img->altura-26; i++) //percorre a imagem de cima pra baixo
    {

        for (j=4; j<img->largura-26; j++) //percorre a imagem da esquerda pra direita
        {


            if(img->dados[i][j] == 255){

                resutado = testaForma(img, i, j);
                switch(resutado){
                    case 0:

                        (*n_circulos)++;
                        break;
                     case 1:

                        (*n_retangulos)++;
                        break;
                     case 2:
                        break;

                }
            }

        }
    }

}