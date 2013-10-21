#include<stdio.h>
#include<math.h>
int getbell(int n)
{
    return (int)ceil((float)n/480)
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",getbell(n));
}
