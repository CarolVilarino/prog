#include <stdio.h>
#include <stdlib.h>
#define TERMOMIN 0.01

int main()
{
    double n=1.0, somatorio=0.0;

    do{
        printf("%lf  ", 1.0/n);
        somatorio=somatorio+1.0/n;
        printf("%lf\n", somatorio);
        n++;

    }while(1/n>=TERMOMIN);

    return 0;
}
