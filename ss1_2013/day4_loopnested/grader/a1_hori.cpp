#include<stdio.h>
int main()
{
    int i,j,n,u;
    scanf("%d",&u);
    //n=u;
    n=(u+1)/2;
    for(i=0; i<=n; i++)
    {
        for(j=0; j<i; j++)
        {
            printf("A");
        }

        if(i!=0)
        {
            for(j=0; j<n-i; j++)
            {
                printf("1");
            }
            printf("\n");
        }
    }
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            printf("A");
        }
        for(j=0; j<=i; j++)
        {
            printf("*");
        }

        printf("\n");
    }
    return 0;
}
