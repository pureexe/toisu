#include<stdio.h>
int main()
{
     int m,n,a=3,b=1,sum=0,u,v;
     scanf("%d %d",&m,&n);
     while(1)
     {
         u=a;
         v=b;
         sum+=(u*v);
         if(a==m&&b==n)
         {
             printf("%d",sum);
             return 0;
         }
         a=u+v;
         b=u-v;
     }
    return 0;
}
