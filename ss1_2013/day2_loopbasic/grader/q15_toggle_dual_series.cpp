#include<stdio.h>
int main(){
    int i,m,n,m2=1,n2=1,u=0;
    scanf("%d %d",&m,&n);
    for(i=3;i<=m;i+=2)
    {
        if(u%2==0)
            m2-=i;
        else
            m2+=i;
            //printf("[%d]",m2);
        u++;
    }
    u=0;
    for(i=2;i<=n;i*=2)
    {
        if(u%2==0)
            {
                //printf("\n{%d-%d=%d}\n",n2,i,n2-i);
                n2-=i;
            }
        else
            {
                //printf("\n{%d+%d=%d}\n",n2,i,n2+i);
                n2+=i;
            }

        u++;
    }
    printf("%d",m2*n2);
    return 0;
}
