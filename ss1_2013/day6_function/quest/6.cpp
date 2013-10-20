#include<stdio.h>
int a,b;
int f(){
    if(a/4<b/2)
        return a/4;
    return b/2;
}
int main(){
    scanf("%d %d",&a,&b);
    printf("%d",f());
    return 0;
}
