#include<stdio.h>
#include<math.h>
int getchick(int n)
{
    return (int)ceil((float)n/2)
}
int getpig(int n)
{
    return (int)ceil((float)n/4)
}
int main()
{
    int n.m;
    scanf("%d %d",&n,&m);
    printf("%d %d",getchick(n),getpig(m));
}
