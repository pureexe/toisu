#include<stdio.h>
int tab[1000][1000],r,c;
bool getMaxRow(int a,int b)
{
    int i;
    for(i=0;i<c;i++)
    {
        if(tab[a][b]<tab[a][i])
            return false;
    }
    return true;
}
bool getMinRow(int a,int b)
{
    int i;
    for(i=0;i<c;i++)
    {
        if(tab[a][b]>tab[a][i])
            return false;
    }
    return true;
}
bool getMinCol(int a,int b)
{
    int i;
    for(i=0;i<r;i++)
    {
        if(tab[a][b]>tab[i][b])
            return false;
    }
    return true;
}
bool getMaxCol(int a,int b)
{
    int i;
    for(i=0;i<r;i++)
    {
        if(tab[a][b]<tab[i][b])
            return false;
    }
    return true;
}
int main()
{
    int i,j,b=0;
    scanf("%d %d",&r,&c);
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d",&tab[i][j]);
        }
    }
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(getMaxRow(i,j)&&getMinCol(i,j))
            {
                printf("(%d, %d) = %d\n",i,j,tab[i][j]);
                b=1;
            }
            if(getMinRow(i,j)&&getMaxCol(i,j))
            {
                printf("(%d, %d) = %d\n",i,j,tab[i][j]);
                b=1;
            }
        }
    }
    if(b==0)
        printf("None");
    return 0;
}
