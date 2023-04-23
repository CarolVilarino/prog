#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=0, a=0, b=1, i, aux;

    while(n<3 || n>47){
        scanf("%d", &n);
    }

    printf("%d %d ", a, b);

    for(i=3; i<=n; i++){
            aux=a+b;
            a=b;
            b=aux;
            printf("%d ", aux);
    }

    return 0;
}
