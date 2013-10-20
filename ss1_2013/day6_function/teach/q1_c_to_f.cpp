#include<stdio.h>
float getDegree(float c){
    return c/5*9+32;
}
int main()
{
    float u;
    printf("Input degree in Celsius :");
    scanf("%f",&u);
    printf("Degree in Fahrenheit is : %.1f",getDegree(u));
    return 0;
}
