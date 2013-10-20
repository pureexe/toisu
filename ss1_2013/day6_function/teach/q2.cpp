#include<stdio.h>int getResult(int a,int b){
    int i,s=0;
    for(i=a;i<=b;i++)
        s+=i;
    return s;
}
int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d",getResult(a,b));
    return 0;
}
