#include<stdio.h>
int front=-1,rear=-1;
int db[100][100];
int que[1000];
int point,edge;
void enqueue(int i)
{
    que[++rear]=i;
}
int dequeue()
{
    return que[++front];
}
int find_q(int x)
{
    int i;
    for(i=0; i<=rear; i++)
        if(que[i]==x)
            return 1;
    return 0;
}
void bfs()
{
    int x,i;
    enqueue(0);

    while(front!=rear)
    {
        x=dequeue();
        printf("%d ",x);
        for(i=0; i<point; i++)
        {
            if(db[x][i]!=0&&find_q(i)==0)
            {
                enqueue(i);
            }
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
    bfs();
    return 0;
}
