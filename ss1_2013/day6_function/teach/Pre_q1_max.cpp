#include<stdio.h>
struct box{
    int a,b;
};
int getMax(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int main()
{
    int i;
    struct box in[3];
    for(i=0;i<3;i++)
        scanf("%d %d",&in[i].a,&in[i].b);
    for(i=0;i<3;i++)
        printf("%d\n",getMax(in[i].a,in[i].b));
    return 0;
}
