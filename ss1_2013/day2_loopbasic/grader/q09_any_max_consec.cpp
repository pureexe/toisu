#include<stdio.h>
int main()
{
    int old=-4654548,u,consec=-4654548,curcon=0,near,ft=0,fbs;
    while(1)
    {
        scanf("%d",&u);
        if(ft==0)
        {
            fbs=u;
            ft=1;
        }
        if(u==0)
           {
               if(consec<curcon)
                {
                     consec=curcon;
                        near=old;
                }

               break;
           }

        if(old==u)
        {
                curcon++;
        }
        else if(old!=u)
        {
            if(consec<curcon)
                {
                    consec=curcon;
                    near=old;
                }
            curcon=0;
        }
        old=u;

    }
    if(consec!=0)
    printf("%d\n%d",consec+1,near);
    else
    printf("%d\n%d",1,fbs);
}
