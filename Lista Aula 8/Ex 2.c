#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dias, acessos, meta=0, saida=0, i;

    scanf("%d", &dias);

    for(i=1;i<=dias;i++){
        scanf("%d", &acessos);
        meta=meta+acessos;
        if(meta<=1000000){
            saida++;
        }
    }

    if(meta<1000000){
        saida=-1;
    }

    printf("%d dias", saida);

    return 0;
}
