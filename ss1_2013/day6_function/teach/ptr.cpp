#include<stdio.h>
int add_mult(int &x,int y){
    x=x+y;
    x=x*y;
    return x;
}
int main()
{
    int x,y,result;
    x=5;
    y=2;
    result=add_mult(x,y);
    printf("%d\n",x);
    printf("%d\n",result);
}
