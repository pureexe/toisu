#include<stdio.h>
#include<math.h>
int main()
{
    int near,i,d,u,len;
    scanf("%d",&d);
    scanf("%d",&u);
    len=fabs(d-u);
             near=u;
    for(i=0;i<7;i++)
    {
        scanf("%d",&u);
        if(fabs(d-u)<len)
        {
            len=fabs(d-u);
            near=u;
        }
    }
    printf("%d",near);
    return 0;
}
