#include<stdio.h>
int main()
{
    int in=0,out=0,in_ct=0,out_ct=0,a,b;
    while(1)
    {
        scanf("%d",&a);
        if(a==0)
            break;
        scanf("%d",&b);
        if(a==1)
            {
                in_ct++;
                in+=b;
            }
        if(a==2)
            {
                out_ct++;
                    out+=b;
            }
    }
    printf("%d %d\n%d %d %d",in_ct,out_ct,in,out,in-out);
    return 0;
}
