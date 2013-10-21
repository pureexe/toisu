#include<stdio.h>
int main()
{
    int n;
    int a,b,c,c1=0,c2=0,c3=0,k=0;
    scanf("%d%d%d%d",&n,&c1,&c2,&c3);
    for(int i=0; i<n; i++)
    {
        k=-1;
        scanf("%d%d%d",&a,&b,&c);
        //printf("<%d>",i);
        if(a<=15&&b<=10&&c<=8)
        {
            if(c1!=0)
            {
                printf("1\n");
                c1--;
                k=0;
            }
            else k=1;
        }
        if(a<=25&&b<=15&&c<=12&&k!=0)
        {
            if(c2!=0)
            {
                printf("2\n");
                c2--;
                k=0;
            }
            else k=1;
        }
        if(a<=50&&b<=40&&c<=20&&k!=0)
        {
            if(c3!=0)
            {
                printf("3\n");
                c3--;
                k=0;
            }
            else k=1;
        }
        if(k==1)
            printf("Box not available\n");
        else if(k==-1)
        {
            printf("Oversize product\n");
        }
    }
}
