#include<stdio.h>
#include<math.h>
int main()
{
    int x,y,r,u,v,n,i,ct=0;
    scanf("%d %d %d %d",&x,&y,&r,&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&u,&v);
        if(fabs(u-x)+fabs(v-y)<=r)
            ct++;
    }
    printf("%d",ct);
    return 0;
}
