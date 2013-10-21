#include<stdio.h>
int a,b,c,d;
int f(){
    return (25*a)+(40*b)+(50*c)+(60*d);
}
int main(){
    scanf("%d %d %d %d",&a,&b,&c,&d);
    printf("%d",f());
    return 0;
}
