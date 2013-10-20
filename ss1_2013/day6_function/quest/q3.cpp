#include<stdio.h>
#include<math.h>

int cross(int x,int y,int z,int a,int b,int c)
{
    return a*x+b*y+c*z;
}
int getBox(int n)
{
    return (int)ceil((float)n/20);
}
int main()
{
    int x,y,z,a,b,c;
    scanf("%d %d %d",&x,&y,&z);
    scanf("%d %d %d",&a,&b,&c);

    printf("%d %d",getBox(cross(x,y,z,a,b,c)));
}
