#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c;

    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    if(a<=b && a<=c && b<=c)
        printf("%d %d %d\n", a, b, c);
    else if(a<=b && a<=c && b>=c)
        printf("%d %d %d\n", a, c, b);
    else if(a<=b && a>=c && b>=c)
        printf("%d %d %d\n", c, a, b);
    else if(a>=b && a>=c && b>=c)
        printf("%d %d %d\n", c, b, a);
    else if (a>=b && a>=c && b<=c)
        printf("%d %d %d\n", b, c, a);
    else if(a>=b && a<=c && b<=c)
        printf("%d %d %d\n", b, a,c);

    return 0;
}
