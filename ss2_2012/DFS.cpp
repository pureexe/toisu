#include<stdio.h>
int front=-1,rear=-1;
int db[100][100];
int que[100];
int point,edge;
void dfs(int input)
{
    int x,i;
    que[input]++;
        printf("%d ",input);
        for(i=0; i<point; i++)
        {
            if(db[input][i]!=0&&que[i]==0)
            {
                    dfs(i);
            }
        }
}

int main()
{
    int i,j,x,y;
    scanf("%d %d",&point,&edge);
    for(i=0; i<edge; i++)
    {
        scanf("%d %d",&x,&y);
        db[x][y]++;
        if(x!=y)
            db[y][x]++;
    }
    dfs(0);
    return 0;
}
