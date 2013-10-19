#include<stdio.h>
int main()
{
    int old=786913524,i,n,u,consec=0,cursec=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&u);
        if(old>=u)
        {
            if(consec<=cursec)
                consec=cursec;
            cursec=0;
        }
        else if(u>=old)
            cursec++;
        old=u;
    }
    if(consec<=cursec)
                consec=cursec;

    if(consec==0)
        printf("No value increase");
    else
        printf("%d",consec);
    return 0;
}
