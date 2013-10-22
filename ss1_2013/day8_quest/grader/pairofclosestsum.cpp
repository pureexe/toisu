#include<stdio.h>
#include<limits.h>
#include<math.h>
int a[1001];
int main()
{
    int near=INT_MAX,near_a,near_b,i,j,in,n,b;
    scanf("%d %d",&in,&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(a[i]!=a[j]){
            if(near>fabs(in-(a[i]+a[j])))
            {
                //printf("<%d,%d>\n",a[i],a[j]);
                near=fabs(in-(a[i]+a[j]));
                near_a=a[i];
                near_b=a[j];
            }else
            if(near==fabs(in-(a[i]+a[j])))
            {
                if(fabs(near_a-near_b)>fabs(a[i]-a[j]))
                {
                    near_a=a[i];
                    near_b=a[j];
                }
            }}
        }
    }
    if(near_b<near_a)
    printf("%d\n%d %d",near_a+near_b,near_b,near_a);
    else
    printf("%d\n%d %d",near_a+near_b,near_a,near_b);
}
