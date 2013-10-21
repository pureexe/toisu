#include<stdio.h>
int main()
{

    int i,u,sum=0,x,b=0,y;
    scanf("%d %d",&x,&y);
    for(i=0;i<8;i++)
    {
        scanf("%d",&u);
        if(u>=x&&u<=y)
            {
                sum+=u;
            b=1;
            }
    }
    if(b==1)
    printf("%d",sum);
    else
        printf("None");
    return 0;
}
