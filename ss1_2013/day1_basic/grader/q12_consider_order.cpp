#include<stdio.h>
int absx(int u){
    if(u<0)
        return 0;
    return u;
}
int main()
{
    int x,y,m,n;
    scanf("%d %d %d %d",&x,&y,&m,&n);
    if(x>=(m*2)+n&&y>=(m*6)+(n*4))
        printf("Yes %d %d",x-((m*2)+n),y-((m*6)+(n*4)));
    else
        printf("No %d %d",absx(((m*2)+n)-x),absx(((m*6)+(n*4))-y));
    return 0;
}
