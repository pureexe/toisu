#include<stdio.h>
int rear=-1;
int db[100][100];
int stack[1000];
int chk[1000];
int point,edge;
void push(int input)
{
    int i;
    stack[++rear]=input;
}
int pop()
{
    if(rear<0)
        printf("Underflow");

    return stack[rear--];
}
int top()
{
    return stack[rear];
}
void dfs()
{
    int x,i,input,sing=0;
    push(0);
    while(rear>=0)
    {
        input=pop();
        if(chk[input]==1)
            continue;
        chk[input]=1;
        printf("%d ",input);
        for(i=point-1; i>=0; i--)
        {
            if(db[input][i]!=0&&chk[i]==0)
            {
                    push(i);
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
      printf("\n");
    dfs();
    return 0;
}
