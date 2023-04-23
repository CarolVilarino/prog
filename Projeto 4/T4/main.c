#include <stdio.h>
#include <stdlib.h>
#include "imagem.h" //Desenvolvida pelo prof. Bogdan.
/*============================================================================*/

char* ARQUIVOS [] = //imagens da pasta img foram geradas pelo prof. Bogdan.
{
    "img2/celula01.bmp",
    "img2/celula02.bmp",
    "img2/tulipNoise2.bmp",
    "img2/borboleta.bmp",
    "img2/lenna.bmp",
    "img2/components.bmp",
    "img2/rice01.bmp",
    "img2/rice02.bmp"

};

#define N_ARQUIVOS 8 //está testando apenas as 3 primeiras imagens da lista
#define TAM_JANELA 5

/******************************************************************
Protótipos
*******************************************************************/
void negativo(Imagem* img, Imagem* out);
void binariza(Imagem* img, Imagem* out, int limiar);
void filtroMedia(Imagem* img, Imagem* out);
void filtroSobel(Imagem* img, Imagem* out);

/******************************************************************
Função principal
*******************************************************************/
int main ()
{
    int i, op, limiar, winSize;
    Imagem *img, *out; // Imagens de entrada e saída
    char nome_saida [25]; // String usada para armazenar os nomes das saídas

    printf("\nO que deseja fazer?\n");
    printf("1 - negativo\n");
    printf("2 - binarizacao\n");
    printf("3 - filtro da media\n");
    printf("4 - componentes conexos \n");
    printf("5 - contagem de objetos\n");
    scanf("%d", &op);

    for (i = 0; i < N_ARQUIVOS; i++)
    {
        img = abreImagem (ARQUIVOS [i]);
        if (!img)
        {
            printf ("Nao conseguiu abrir %s\n", ARQUIVOS [i]);
            return (1);
        }
        printf ("Processando imagem %s...\n", ARQUIVOS [i]);

        switch(op)
        {
            case 1:
                out = criaImagem(img->largura, img->altura, 1);
                negativo(img, out);
                sprintf (nome_saida, "neg%d.bmp", i);
                salvaImagem (out, nome_saida);
                destroiImagem (out);
                break;
            case 2:
                scanf("%d",&limiar);
                out = criaImagem(img->largura, img->altura, 1);
                binariza(img, out, limiar);
                sprintf(nome_saida,"bin%d.bmp", i);
                salvaImagem (out, nome_saida);
                destroiImagem (out);
                break;
            case 3:
                out = criaImagem(img->largura, img->altura, 1);
                filtroMedia(img, out);
                sprintf(nome_saida,"fil%d.bmp", i);
                salvaImagem (out, nome_saida);
                destroiImagem (out);
                break;
            case 4:
                printf("Ainda não implementado!!");
                break;
            case 5:
                printf("Ainda não implementado!!");
                break;
            default:
                printf("Opcao invalida!");
        }
        destroiImagem (img);
    }


    return (0);
}
/******************************************************************
Funções
*******************************************************************/
void negativo(Imagem* img, Imagem* out)
{
    int i, j;


    for (i = 0; i < img->altura; i++)
        for (j = 0; j < img->largura; j++)
            out->dados[0][i][j] = 255 - img->dados[0][i][j];

}

void binariza(Imagem* img, Imagem* out, int limiar)
{
    int i, j;
    for (i=0;i<img->altura;i++)
        for(j=0;j<img->largura;j++){
            if(img->dados[0][i][j]>=limiar)
                out->dados[0][i][j]=0;
            else
                out->dados[0][i][j]=255;
        }
}

void filtroMedia(Imagem* img, Imagem* out)
{
    int i,j,falt,flar,media;
    for(i=1;i<img->altura-1;i++){
        for(j=1;j<img->largura-1;j++){
            media=0;
            for(falt=-1;falt<=1;falt++){
                for(flar=-1;flar<=1;flar++){
                    media+=img->dados[0][i+falt][j+flar]*1;
                }
            }
        out->dados[0][i][j]=media/9;
        }
    }

}

// componentes conexos???
// contagem de objetos???
