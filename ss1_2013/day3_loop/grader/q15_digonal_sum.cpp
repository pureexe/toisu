#include<stdio.h>
int main()
{
    int r,n,sum=0,i=0,gap=1;
    scanf("%d",&n);
    r=1;
    sum=1;
    while(1)
    {
        r=r+(2*(n-gap));
        if(r>(n*n))break;
        sum+=r;
        i++;
        if(i%2==0)
            gap+=2;
    }
    printf("%d",sum);
    return 0;
}
