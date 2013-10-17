#include<stdio.h>
int main()
{
    int i,n,a,b,c,b1=0,b2=0,b3=0,b1t=0,b2t=0,b3t=0;
    scanf("%d",&n);


    for(i=0; i<n; i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        if(a<=15&&b<=10&&c<=8)
        {
            printf("1\n");
            b1+=(10*15*8)-(a*b*c);
            b1t++;
        }
        else if(a<=25&&b<=15&&c<=12)
        {
            printf("2\n");
            b2+=(25*15*12)-(a*b*c);
            b2t++;
        }
        else if(a<=50&&b<=40&&c<=20)
        {
            printf("3\n");
            b3+=(40*50*20)-(a*b*c);
            b3t++;
        }
        else
        {

            printf("Oversize product\n");
        }

    }
    printf("%d %d\n%d %d\n%d %d",b1t,b1,b2t,b2,b3t,b3);
    return 0;
}
