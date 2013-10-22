#include<stdio.h>
#define LEFT 123451
#define RIGHT 123452
#define UP 123453
#define DOWN 123454
int tab[100][100];
int n;
int lot=0;
int run(int r,int c,int u)
{
    //printf("<%d,%d>\n",r,c);
    if(tab[r][c])
    {
        //printf("TERM");
        return 0;
    }
    lot++;
    tab[r][c]=lot;

    if(u==LEFT)
    {
        if(tab[r][c-1]==0&&c-1>=0)
            return run(r,c-1,LEFT);
        else
            return run(r-1,c,UP);
    }
    if(u==RIGHT)
    {
        if(tab[r][c+1]==0&&c+1<n)
            return run(r,c+1,RIGHT);
        else
            return run(r+1,c,DOWN);
    }
    if(u==UP)
    {
        if(tab[r-1][c]==0&&r-1>=0)
            return run(r-1,c,UP);
        else
            return run(r,c+1,RIGHT);
    }
    if(u==DOWN)
    {
        if(tab[r+1][c]==0&&r+1<n)
            return run(r+1,c,DOWN);
        else
            return run(r,c-1,LEFT);
    }
}
int main()
{
    int sum=0;
    scanf("%d",&n);
    run(0,0,RIGHT);
    int i,j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(i==j)
                sum+=tab[i][j];
            printf("%3d ",tab[i][j]);
        }
        printf("\n");
    }
    printf("\n\n\n%d",sum);
    return 0;
}
