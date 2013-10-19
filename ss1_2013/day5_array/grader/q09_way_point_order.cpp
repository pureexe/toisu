#include<stdio.h>
int tab[101][101];
int main()
{
    int i,j,r,c,n,u,v;
    scanf("%d %d %d",&r,&c,&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&u,&v);
        tab[u][v]=i+1;
    }
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=c;j++)
        {
            printf("%d ",tab[i][j]);
        }
        printf("\n");
    }

    return 0;
}
