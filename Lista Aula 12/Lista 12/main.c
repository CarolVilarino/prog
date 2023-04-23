#include <stdio.h>
#include <stdlib.h>

void removeExtremos (int *n, int *pri, int *ult)
{
int tn, pot = 1;
tn = *n;
while(tn >= 10)
{
tn = tn/10;
pot *= 10;
}
*pri = *n / pot;
*ult = *n % 10;
*n = *n % pot;
*n = *n / 10;
}

int main(){
    int n, primeiro, ultimo;

    scanf("%d", &n);

    do{
        removeExtremos(n, &primeiro, &ultimo);
    }while(primeiro==ultimo && n>9);
    if(n>9)
        printf("nao eh");
    else
        printf("eh");
    return 0;
}
