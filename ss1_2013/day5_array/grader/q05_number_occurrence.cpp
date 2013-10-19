#include<stdio.h>
int u[2500001];
int main()
{
    int i,n,d;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&u[i]);
    }
    scanf("%d",&d);
    for(i=0;i<n;i++)
    {
        if(u[i]==d)
           {
             printf("%d ",i+1);
           }
    }
    return 0;
}
