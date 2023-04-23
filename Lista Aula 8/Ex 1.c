#include <stdio.h>
#include <stdlib.h>

int main()
{
    int entrada, i;

    scanf("%d", &entrada);
    printf("\n");

    for(i=1; entrada!=1; i++){
        printf("%d, ", entrada);
        if(entrada%2==0){
            entrada=entrada/2;
        }
        else{
            entrada=3*entrada+1;
        }
    }
    printf("%d\n", entrada);
    printf("foram gerados %d elementos.\n", i);


    return 0;
}
