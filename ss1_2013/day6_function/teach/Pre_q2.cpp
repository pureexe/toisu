#include<stdio.h>
double findCircleArea(double radius)
{
    const double PI = 3.1415926535;
    return PI * radius * radius;
}
int main()
{
    double radius;
    scanf("%lf",&radius);
    double circleArea= findCircleArea(radius);
    printf("Circle area = %f\n",circleArea);
    return 0;
}
