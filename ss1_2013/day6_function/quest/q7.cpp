#include<stdio.h>
#include<math.h>
int getpin(int n)
{
    return (int)ceil((float)n/120;

int getbell(int n)
{
    return (int)ceil((float)n/30);
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d %d",getpin(n),getbell(n));
    return 0;
}
