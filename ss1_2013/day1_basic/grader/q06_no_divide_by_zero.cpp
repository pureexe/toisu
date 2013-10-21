#include<stdio.h>
using namespace std;
int main()
{
    float a,b,c;
    scanf("%f %f %f",&a,&b,&c);
    if(c==0)
        printf("cannot divide by zero");
    else
        printf("%f",(a+b)/c);
}
