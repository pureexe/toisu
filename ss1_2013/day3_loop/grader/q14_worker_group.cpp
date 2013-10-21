#include<stdio.h>

int ceil(float x)
{
    int y=(int)x;
    if((float)y!=x)
        x++;
    return (int)x;
}

int main()
{
    int k,m,n,x1,x2,mm,mn,d=100000;
    scanf("%d%d%d",&k,&m,&n);
    if(m==0)
    {
        printf("0 %d",k);
        return 0;
    }
    if(n==0)
    {
        for(int i=1; i<=k; i++)
        {
            x1=ceil((float)m/(i*6));
            if(x1<d)
            {
                d=x1;
                mm=i;
                mn=k-i;
            }
        }
        printf("%d %d",mm,mn);
        return 0;
    }
    int c;
    for(int i=1; i<=k; i++)
    {
        x1=ceil((float)m/(i*6));
        if(i!=k)
            x2=ceil((float)n/((k-i)*10));
        else
            x2+=1000000;
        if(x1>x2)
            c=x1;
        else
            c=x2;
        if(c<d)
        {
            d=c;
            mm=i;
            mn=k-i;
            //printf("!");
        }
        //printf("<%d>",x);
    }

    printf("%d %d",mm,mn);
}
