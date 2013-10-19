#include<stdio.h>
int u[3000000];
int main()
{
    int i,n,d,b=0;
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
                    b=1;
           }
    }
    if(b==0)
        printf("0");
    return 0;
}
