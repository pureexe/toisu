#include<stdio.h>
long long getLongInt()
{

    long long cur_num=0;
    int u,ft=0;
    scanf("%d",&u);
    cur_num+=u;
    while(1)
    {

        scanf("%d",&u);
        if(u==0)
            break;

        cur_num*=10;
        cur_num+=u;

    }
    return cur_num;
}
int main()
{
    int i,n,buff=0,u,ft=0;

    printf("%lld",getLongInt());
    return 0;
}
