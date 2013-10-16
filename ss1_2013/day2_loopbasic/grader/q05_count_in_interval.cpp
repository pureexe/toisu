#include<stdio.h>
int main()
{
    int x,y,i,u,ct=0,s;
    scanf("%d %d",&x,&y);
    if(x>y)
    {
        s=x;
        x=y;
        y=s;
    }
    for(i=0;i<8;i++)
    {
        scanf("%d",&u);
        if(u>=x&&u<=y)
            ct++;
    }
    if(ct==0)
        printf("None");
    else
        printf("%d",ct);
    return 0;
}
