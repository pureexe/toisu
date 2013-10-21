#include<stdio.h>
/*
int pow(int a,int b)
{
    int i,sum=1;
    for(i=1;i<=b;i++)
        sum*=a;
    return sum;
}
int fac(int a)
{
    int i,sum=1;
    for(i=2;i<=a;i++)
        sum*=i;
    return sum;
*/
int pow(int a,int b)
{
    if(b==0)
            return 1;
    return a*pow(a,b-1);

}
int fac(int a)
{
    if(a<=1)
        return 1;
    return a*fac(a-1);
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d %d",pow(2,n),fac(n));
    return 0;
}
