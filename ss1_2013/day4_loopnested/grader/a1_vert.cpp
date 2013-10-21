#include<stdio.h>
int main()
{
    int i,j,n,u;
    scanf("%d",&u);
    //n=u;
    n=(u+1)/2;
    for(i=0;i<n;i++)
    {
        for(j=0;j<i;j++)
            printf("1");
        for(j=0;j<u-(i*2);j++)
            printf("A");
        for(j=0;j<i;j++)
            printf("*");
        printf("\n");
    }
    return 0;
}
