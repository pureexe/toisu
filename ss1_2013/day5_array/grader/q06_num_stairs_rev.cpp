#include<stdio.h>
int main()
{
    int n,u[11],i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&u[i]);
    for(i=0;i<n;i++)
    {
        for(j=0;j<=i;j++)
        {
            printf("%d",u[n-i-1]);
        }
        printf("\n");
    }
    return 0;
}
