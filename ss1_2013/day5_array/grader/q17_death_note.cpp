#include<stdio.h>
#include<math.h>
long long int_rev(long long in)
{
    long long ans=0;
    while(in>10)
    {
        ans+=in%10;
        in/=10;
        ans*=10;
    }
    ans+=in;
    return ans;
}
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
        int i,n,u,ft=0;
        long long cur_num=0,cur2_num=0,buff=0;
        scanf("%d",&n);
        for(i=0; i<n; i++)
        {
            cur_num=getLongInt();
            buff+=fabs(cur_num-int_rev(cur_num));

        }
        printf("%lld",buff);
        return 0;
    }
