#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,n,k,f=0,u,v;
    scanf("%d %d",&n,&k);
    while(1)
    {
        f=0;
        for(i=0; i<n; i++)
        {
            scanf("%d %d",&u,&v);
            f+=u-v;
        }
        if(f>0)
            printf("Profit %d\n",f);
        if(f==0)
            printf("Breakeven\n");
        if(f<0)
            printf("Loss %d\n",abs(f));
        if(f>=k)
        {
            printf("Expand\n");
            break;
        }
        if((float)f>=(float)k/2)
        {
            printf("Wait and see\n");
            continue;
        }
        if((float)f<(float)k/2)
        {
            printf("Not expand\n");
            break;
        }

    }


    return 0;
}
