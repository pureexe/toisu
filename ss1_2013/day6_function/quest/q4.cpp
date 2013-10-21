#include<stdio.h>
int getSpeed(int x,int y,int t){
    return (int)ceil(y/(x*t));
}
int main(){
    int x,y,t;
    scanf("%d %d %d",&x,&y,&t);
    printf("%d",getSpeed(x,y,t));
}
