#include "trabalho3.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct coordenada{
    int x;
    int y;
}Coordenada;

int** alocarRotulos(Imagem1C* img){
    int **vet;
    int i;
    vet=(int**) malloc(sizeof(int*)* img->altura);
    for(i=0;i<img->largura;i++)
        vet[i]=(int*) malloc(sizeof(int)* img->largura);

    return(vet);
}

void liberarMatriz(Imagem1C* img, int** rotulos){
    int i;
    for(i=0; i<img->altura;i++)
        free(rotulos[i]);
    free(rotulos);
}
void filtroMedia(Imagem1C* img)
{
    int i,j,falt,flar,media;

    for(i=2;i<img->altura-2;i++){
        for(j=2;j<img->largura-2;j++){
            media=0;
            for(falt=-2;falt<=2;falt++){
                for(flar=-2;flar<=2;flar++){
                    media+=img->dados[i+falt][j+flar]*1;
                }
            }
        img->dados[i][j]=media/25;
        }
    }
    salvaImagem1C(img, "out1f.bmp");
}


void binarizaImagem(Imagem1C* img, int limiar)
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
    salvaImagem1C(img, "out2bin.bmp");
}

void limpaBorda(Imagem1C* img)
{
    int i,j;
    for(i=0;i<img->altura;i++){
        for(j=1;j<img->largura;j++){
                img->dados[i][j]=0;
            if(i == 2)
                i=img->altura-2;

        }
    }
    for(j=0;j<img->largura;j++){
        for(i=1;i<img->altura;i++){
                img->dados[i][j]=0;
            if(j == 2)
                j=img->largura-2;

        }
    }
    salvaImagem1C(img, "out3b.bmp");
}

int vizinhoMinimo(char a, char b, char c, char d, int min){
    char vizinhos[4]={a,b,c,d};
    int i, retorno=min;

    for(i=0;i<4;i++){
        if(vizinhos[i]<retorno && vizinhos[i]!=0)
            retorno=vizinhos[i];
    }

    return(retorno);

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
                    rotulos[i][j] = *r;
                    (*r)++;
                }
                else {
                    min = *r;
                rotulos[i][j] = vizinhoMinimo(img->dados[i-1][j-1], img->dados[i-1][j], img->dados[i-1][j+1], img->dados[i][j-1], min);
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
                    rotulos[i][j] = *r;
                    (*r)++;
                }
                else {
                    min = (*r);
                    rotulos[i][j] = vizinhoMinimo(img->dados[i+1][j+1], img->dados[i+1][j], img->dados[i+1][j-1], img->dados[i][j+1], min);
                }
            }
        }
    }
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

void rotulaObjetos (Imagem1C* img, int *r, int **rotulos ){
    int j=0;
    forwardScan(img, rotulos, r);
    while(j<15){

        backwardScan(img, rotulos, r);
        forwardScan(img, rotulos, r);
        j++;
    }

    salvaImagem1C(img, "out4rot.bmp");

}
int limite_xy(Coordenada xy, int** rotulos, int r){
    int i, j;

    for(i=xy.x;rotulos[i][j]==r;i++)
            for(j=xy.y;rotulos[i][j]==r;j++)


    if(j>=10&&i>=5)
        return (1);
    else
        return(0);

}

int defineForma(Coordenada *largura_esquerda, Coordenada *largura_direita, Coordenada *topo_altura, Coordenada *base_altura, Imagem1C* img, int** rotulos, int r, int i, int j){

    int correX=0, correY=0;
    Coordenada centro;


                largura_esquerda->x=0;
                largura_direita->x=img->largura;
                topo_altura->y=img->altura;
                base_altura->y=0;

    for(i=i;i<img->altura;i++){
        for(j=j;j<img->largura;j++){


            if(largura_esquerda->x>j && rotulos[i][j]==r){
                largura_esquerda->x=j;
                largura_esquerda->y=i;
            }
            else if(largura_direita->x<j && rotulos[i][j]==r){
                largura_direita->x=j;
                largura_direita->y=i;
            }
            else if(topo_altura->y>i && rotulos[i][j]==r){
                topo_altura->x=j;
                topo_altura->y=i;
            }
            else if(base_altura->y<i && rotulos[i][j]==r){
                base_altura->x=j;
                base_altura->y=i;
            }
        }
    }
    centro.x= (int) largura_esquerda->x+(largura_direita->x-largura_esquerda->x)/2;
        centro.y= (int) topo_altura->y+(base_altura->y-topo_altura->y)/2;

       while(rotulos[centro.y+correY][centro.x+correX]==r){
            correY++;
            correX++;
       }
       if(centro.x+correX<largura_direita->x && centro.y+correY<base_altura->y){
            return(1);
       }
       else
            return(0);


}

void buscaForma(Imagem1C* img, int* n_circulos, int* n_retangulos, int** rotulos, int r){
    int i, j, forma, limite;
    Coordenada *largura_esquerda, *largura_direita, *topo_altura, *base_altura, detector_limite;
    while(r>1){
        for(i=0;i<img->altura;i++){
            for(j=0;rotulos[i][j]!=r||j<img->largura;j++){
                    detector_limite.x=i;
                    detector_limite.y=j;
            }
            if(rotulos[i][j]==r){
                limite=limite_xy(detector_limite,rotulos,r);
                if(limite)
                forma=defineForma(largura_esquerda, largura_direita, topo_altura, base_altura, img, rotulos, r, i, j);
                if(forma)
                    (*n_circulos)++;
                else if(!forma)
                    (*n_retangulos)++;
                r--;
            }
        }
    }

}



void contaIngredientes (Imagem1C* img, int* n_circulos, int* n_retangulos)
{
    int r=1;
    int **rotulos;

    rotulos=alocarRotulos(img);


    filtroMedia(img);
    binarizaImagem(img, 115);
    limpaBorda(img);
    arrumaImagem (img, rotulos);
    rotulaObjetos(img, &r, rotulos);
    buscaForma(img, n_circulos,n_retangulos, rotulos, r);

}



