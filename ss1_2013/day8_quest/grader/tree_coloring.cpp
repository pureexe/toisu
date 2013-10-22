#include<stdio.h>
int getgap(int a,int b)
{
    int i,gap=b;
    gap%=93563;
    for(i=0;i<a-1;i++)
    {
        gap*=b-1;
        gap%=93563;
    }
    return gap;
}
int main()
{
    int i,j,T,n,k,t1,t2;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d %d",&n,&k);
        for(j=0;j<n-1;j++)
        {
            scanf("%d %d",&t1,&t2);
        }
        printf("%d\n",getgap(n,k));
    }
    return 0;
}
