#include<stdio.h>
int main()
{
    int i,j,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=0;j<n-i;j++)
            printf(" ");
        for(j=0;j<i*2-1;j++)
            printf("*");
        printf("\n");
    }
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
            printf(" ");
        for(j=0;j<(n-i)*2-1;j++)
            printf("*");
        printf("\n");
    }
    return 0;
}
