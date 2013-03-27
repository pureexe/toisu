#include<cstdio>
using namespace std;
int int_rev(int in){
    int ans=0;
    while(in>10)
    {
        ans+=in%10;
        in/=10;
        ans*=10;
    }
    ans+=in;
    return ans;
}
int int_pow(int in){
    int ans=1;
    while(in>10)
    {
        in/=10;
        ans*=10;
    }
    return ans*10;
}
bool chkmin(int in){
    int ans=0,x=10;
    while(in>=1)
    {
        if(x<=in%10)
        {
            return false;
        }
        x=in%10;
        in/=10;
    }
    return true;
}
bool chkmax(int in){
    int ans=0,x=-1;
    while(in>=1)
    {
        if(x>=in%10)
        {
            return false;
        }
        x=in%10;
        in/=10;
    }
    return true;
}
int main()
{
    long long int xmin=0;
    long long int xmax=0;
    int i;
    for(i=0;i<10000;i++)
        {
           if(chkmin(i))
           {
               printf("%d\n",i*int_pow(i)+int_rev(i));
               xmin+=i*int_pow(i)+int_rev(i);
//               printf("%d\n",i/10*int_pow(i)+int_rev(i));
//               xmin+=i/10*int_pow(i)+int_rev(i);
           }else if(chkmax(i))
           {
               printf("%d\n",i*int_pow(i)+int_rev(i));
               xmax+=i*int_pow(i)+int_rev(i);
//               printf("%d\n",i/10*int_pow(i)+int_rev(i));
//               xmax+=i/10*int_pow(i)+int_rev(i);
           }
        }
        printf("<%lld \n>%lld",xmin,xmax);
    return 0;
}
