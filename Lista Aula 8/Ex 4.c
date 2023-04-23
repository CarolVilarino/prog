#include <stdio.h>
#include <stdlib.h>

int main()
{
    int entrada, nme, n, nma, i, montanha, vale=0;

    scanf("%d", &entrada);

    for(i=0;i<entrada;i++){
        scanf("%d", &montanha);
        if(i==0)
            nme=montanha;
        else if(i==1)
            n=montanha;
        else if(i==2)
            nma=montanha;
        else{
            nme=n;
            n=nma;
            nma=montanha;
            if(n<nme && n<nma)
                vale++;
        }

    }
    if(vale!=0)
        printf("N\n");
    else
        printf("S\n");

    return 0;
}
