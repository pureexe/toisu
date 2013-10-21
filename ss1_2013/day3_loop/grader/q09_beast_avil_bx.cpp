#include<stdio.h>
int main()
{
    int i,n,a,b,c,x,y,z;
    scanf("%d",&n);
    scanf("%d %d %d",&x,&y,&z);

    for(i=0; i<n; i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        if(a<=15&&b<=10&&c<=8&&x>0)
        {
            printf("1\n");
            x--;
        }
        else if(a<=25&&b<=15&&c<=12&&y>0)
        {
            printf("2\n");
            y--;
        }
        else if(a<=50&&b<=40&&c<=20&&z>0)
        {
            printf("3\n");
            z--;
        }
        else if(a<=50&&b<=40&&c<=20)
        {
            printf("Box not avaliable\n");

        }
        else
        {
            printf("Oversize product\n");
        }

    }
    return 0;
}
