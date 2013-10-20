#include<stdio.h>
int getlow(int n)
{
    return (int)ceil((float)n/12);
}

int getlung(int n)
{
    return (int)ceil((float)n/24);

}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d %d",getlow(n),getlung(n));
}
