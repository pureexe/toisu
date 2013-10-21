#include<stdio.h>
int main()
{
    double a,b;
    scanf("%lf %lf",&a,&b);
    if(a>0&&b>0)
        printf("%.2f",a*b);
    else if(a<=0&&b<=0)
        printf("invalid width and height");
    else if(a<=0)
        printf("invalid width");
    else if(b<=0)
        printf("invalid height");
    return 0;
}
