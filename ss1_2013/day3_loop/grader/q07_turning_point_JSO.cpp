#include<stdio.h>
int main()
{
    int a,b,c,up=0,down=0;
    scanf("%d%d%d",&a,&b,&c);
    while(1)
    {
        if(c<=0)
            break;
        if(a<b&&b>c)
            up++;
        else if(a>b&&b<c)
            down++;
        a=b; b=c;
        scanf("%d",&c);
    }
    printf("%d\n%d",up,down);
}
