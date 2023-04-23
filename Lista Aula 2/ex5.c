#include <stdio.h>
#include <stdlib.h>

int main(){

    int valora,valorb,valorc,valord,valore;
    float media;

    scanf("%d",&valora);
    scanf("%d",&valorb);
    scanf("%d",&valorc);
    scanf("%d",&valord);
    scanf("%d",&valore);

    media=(valora+valorb)/2.0;
    printf("%f\n", media);

    media=(valora+valorb+valorc)/3.0;
    printf("%f\n", media);

    media=(valora+valorb+valorc+valord)/4.0;
    printf("%f\n", media);

    media=(valora+valorb+valorc+valord+valore)/5.0;
    printf("%f\n", media);

    return 0;

}
