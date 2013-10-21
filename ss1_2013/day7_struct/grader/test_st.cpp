#include<stdio.h>
struct st{
     int x,y;
};
int main()
{
    struct st a,b;
    a.x=1;
    a.y=2;
    b=a;
    printf("%d %d",b.x,b.y);
}
