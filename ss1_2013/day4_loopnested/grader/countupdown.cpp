#include<stdio.h>
int main()
{
    int i,j=1,n,u;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&u);
        if(u>j)
        {
            if(j-u<-10||j-u>10)
                printf("%d . . . %d",j,u);
            else
            for(;j<=u;j++)
                printf("%d ",j);
            printf("\n");
            j=u;
        }
        else{
            if(j-u<-10||j-u>10)
                printf("%d . . . %d",j,u);
            else
            for(;j>=u;j--)
                printf("%d ",j);
            printf("\n");
            j=u;
        }
    }
    return 0;
}
