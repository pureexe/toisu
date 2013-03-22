#include<cstdio>
#include<climits>
#include<algorithm>
#include"../winconio.h"
using namespace std;
int point,edge,start,finish,db[20][20],dist[20]={INT_MAX},T[20],prev[20]={-1};
void print_matrix()
{
    int i,j;
    for(i=0;i<point;i++)
    {
           for(j=0;j<point;j++)
        {
            if(db[i][j]==INT_MAX)
            {
                textcolor(LIGHTBLUE);
                printf("! ");
            }
            else
            {
            textcolor(LIGHTMAGENTA);
            printf("%d ",db[i][j]);
            }
            textattr(LIGHTGRAY);

        }
            printf("\n");
    }
}
int main()
{
    int i,j,x,y,z;
    for(i=0;i<20;i++)
    {
        for(j=0;j<20;j++)
            db[i][j]=INT_MAX;
    }
    scanf("%d %d",&point,&edge);
    for(i=0;i<edge;i++)
    {
        scanf("%d %d %d",&x,&y,&z);
        if(db[x][y]>z&&x!=y)
        {   db[x][y]=z;
            db[y][x]=z;
        }
    }
    scanf("%d %d",&start,&finish);
    printf("\n");

    int current=start,minidist,tx;
    for(i=0;i<point;i++)
    {
        T[i]=1;
        prev[i]=-1;
        dist[i]=INT_MAX;
    }
    dist[start]=0;
    ///////////////////////////
    /// DiStar algorithm
    ///////////////////////////
    while(current!=finish)
    {
        minidist=INT_MAX;
        for(i=0;i<point;i++)
        {
            if(minidist>dist[i]&&T[i]==1){
                   // printf("DO");
                minidist=dist[i];
                current=i;
            }
        }
//        printf("%d-> ",current);
        T[current]=0;
        for(i=0;i<point;i++)
        {
            if(db[current][i]!=INT_MAX)
            {
                tx=i;
                if(T[tx]==1)
                {
                    if(dist[tx]>dist[current]+db[current][tx])
                    {
                    dist[tx]=dist[current]+db[current][tx];

                    prev[tx]=current;
                    }
                }
            }
        }

    }
    int k=prev[finish],buff[20],ctx=0;
    while(k!=-1)
    {
        buff[ctx++]=k;
        k=prev[k];
    }
    for(i=ctx-1;i>=0;i--)
    {
        printf("%d -> ",buff[i]);
    }
    printf("%d\n",finish);
    //print_matrix();


    return 0;
}
