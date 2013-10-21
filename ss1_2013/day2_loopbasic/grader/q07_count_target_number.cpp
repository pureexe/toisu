#include<stdio.h>
int main()
{
    int d,ct=0,u;
    scanf("%d",&d);
    while(1)
    {
        scanf("%d",&u);
        if(u==0)break;
        if(u==d)ct++;
    }
    if(ct==0)
        printf("None");
    else
        printf("%d",ct);

}
