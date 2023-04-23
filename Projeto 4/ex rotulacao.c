void rotulaObjetos (Imagem1C* img, int *r ){


    int **rotulos, i;
    rotulos = (int **)malloc(img->altura * sizeof(int*));
    for(i=0; i<img->altura;i++)
        rotulos[i] = (int*)malloc(img->largura * sizeof(int));

    forwardScan(img, rotulos, r);
    backwardScan(img, rotulos, r);    
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
                    if( img->dados[i-1][j-1] < min && img->dados[i-1][j-1]!=0 )
                        min = img->dados[i-1][j-1];
                    if( img->dados[i-1][j] < min && img->dados[i-1][j]!=0 )
                        min = img->dados[i-1][j];
                    if( img->dados[i-1][j+1] < min && img->dados[i-1][j+1] != 0)
                        min = img->dados[i-1][j+1];
                    if( img->dados[i][j-1] < min && img->dados[i][j-1] !=0 )
                        min = img->dados[i][j-1];
                    rotulos[i][j] = min;
                }
            }
        }
    }
}

// Função auxiliar para rotular objetos, iniciando pela direita-baixo
void backwardScan ( Imagem1C* img, int* r ){
    int i, j, min;

    for(i = img->altura - 1; i > 1; i--) {
        for(j = img->largura - 1; j > 1 ; j--) {
            if( img->dados[i][j] != 0 ) {
                if( img->dados[i+1][j+1] == 0 && img->dados[i+1][j] == 0 && img->dados[i+1][j-1] == 0 && img->dados[i][j+1] == 0  ) {
                    rotulos[i][j] = *r;
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
                    rotulos[i][j] = min;
                }
            }
        }
    }
}