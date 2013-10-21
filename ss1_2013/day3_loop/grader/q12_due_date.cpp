#include<stdio.h>
 int k,n,i,w,d=1,u,sum;
int main()
{

    scanf("%d %d",&k,&n);
    for(i=0;i<n;i++)
        {
            scanf("%d",&u);
            sum+=u;
            if(sum%(k*100)==0)
                printf("%d\n",sum/(k*100));
            else
                printf("%d\n",(sum/(k*100))+1);
        }

    return 0;
}
