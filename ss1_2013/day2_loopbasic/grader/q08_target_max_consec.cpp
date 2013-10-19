#include<stdio.h>
int main()
{
    int old=-4654548,u,d,consec=-4654548,ct=0,curcon=0;
    scanf("%d",&d);
    while(1)
    {
        scanf("%d",&u);
        old=u;
        if(u==0)
           {
               if(consec<curcon)
                    consec=curcon;
                curcon=0;
               break;

           }

        if(d==u)
        {
            ct++;
            if(old==d)
            {
                curcon++;
            }
        }
        else if(old!=d)
        {
            if(consec<curcon)
                consec=curcon;
            curcon=0;
        }
    }
    printf("%d\n%d",consec,ct);
}
