#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c;

    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    if(a>0)
        printf("+");
    else
        printf("-");
    if(b>0)
        printf("+");
    else
        printf("-");
    if(c>0)
        printf("+\n");
    else
        printf("-\n");

    return 0;
}
