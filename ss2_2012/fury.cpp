#include<stdio.h>
int front=-1,rear=-1;
int db[100][100];
int que[100];
int point,edge;
int bridge(int node,int come)
{
    int i;
    for(i=0; i<point; i++)
    {
        if(i!=come&&db[node][i]!=0)
            return 0;
    }
    return 1;

}
void fury(int root)
{
    int i;
    printf("%c -> ",root+'A');
    for(i=0; i<point; i++)
    {
        if(db[root][i]!=0&&!bridge(i,root))
        {

            db[root][i]=0;db[i][root]=0;
            fury(i);
        }
    }
}

int main()
{
    int i,j,x,y,tmp;
    scanf("%d %d",&point,&edge);
    for(i=0; i<edge; i++)
    {
        scanf("%d %d",&x,&y);
        db[x][y]++;
        if(x!=y)
            db[y][x]++;
    }

    for(i=0; i<point; i++)
    {
        tmp=0;
        for(j=0; j<point; j++)
        {
            if(i==j)
            {
                tmp+=db[i][j];
            }
            tmp+=db[i][j];

        }
        printf("deg(v[%d]) = %d\n",i,tmp);
        if(tmp%2!=0)
        {
            printf("Break because Not oiller graph");
            return 0;
        }
    }
    fury(0);
    printf("A");

    return 0;
}
