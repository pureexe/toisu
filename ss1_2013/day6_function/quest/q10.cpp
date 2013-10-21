#include<stdio.h>
#include<math.h>
int getBig(int n)
{
    return n/15;
}
int getMid(int n)
{
    return n/8;
}
int getsmall(int n)
{
    return (int)ceil((float)n/2);
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("%d %d %d",getBig(n),getMid(n-(15*getBig(n))),getsmall(n-(15*getBig(n))+(getMid(n-(15*getBig(n)))*8)));
}
