#include<stdio.h>
int getOut(int shirt)
{
    int out;
    if(shirt<=100)
        out=shirt*80;
    else if(shirt<=250)
        out=8000+((shirt-100)*70);
    else
        out=18500+((shirt-250)*60);
    return out;

}
int main()
{
    int x,i,b=0,u,profit;
    scanf("%d",&x);
    for(i=0;i<7;i++)
    {
        scanf("%d",&u);
        b+=u;
    }
    profit=(x*b)-getOut(b);
    printf("%d\n%d\n",getOut(b),x*b);
    if(profit<=0)
        printf("No Profit");
    else
        printf("%d",profit);

    return 0;
}
