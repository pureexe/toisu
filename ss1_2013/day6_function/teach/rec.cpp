#include<stdio.h>
int f(int i)
{
    if(i==1)
        return 1;
    return i+f(i-1);
}
int g(int i){
    if(i==1)
        return 2;
    return (i*2)*g(i-1);
}
int h(int i)
{
    if(i==1)
        return 1;
    return (i*2-1)+h(i-1);
}
int k(int i)
{
    if(i==1)
        return 2;
    if(i==2)
        return 3;
    return k(i-1)+k(i-2);
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("%d %d %d %d",f(n),g(n),h(n),k(n));
    return 0;
}
