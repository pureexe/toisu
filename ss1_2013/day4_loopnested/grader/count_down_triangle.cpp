#include<stdio.h>
int main()
{
    int i,j,n;
    scanf("%d",&n);
    for(i=n;i>0;i--)
    {
        for(j=0;j<n-i;j++)
            printf(" ");
        for(j=i;j>0;j--)
            printf("%d",i%10);
        printf("\n");
    }
    return 0;
}
