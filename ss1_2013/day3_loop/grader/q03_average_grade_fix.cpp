#include<stdio.h>
int A,B,C,D;
int getGrade(int p)
{
    if(p>=A)
        return 4;
    if(p>=B)
        return 3;
    if(p>=C)
        return 2;
    if(p>=D)
        return 1;
    return 0;
}
int main()
{
    int i,u,sum=0,v;
    scanf("%d %d %d %d",&A,&B,&C,&D);
    for(i=0;i<8;i++)
    {
        scanf("%d",&u);
        v=getGrade(u);
        printf("%d\n",v);
        sum+=v;
    }
    printf("%f",(float)sum/8);
    return 0;
}
