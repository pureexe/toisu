#include<stdio.h>
int main()
{
    double a,b;
    scanf("%lf %lf",&a,&b);
    if(a>0&&b>0)
        printf("%.2lf",a*b);
    else
        printf("invalid width and height");
    return 0;
}
