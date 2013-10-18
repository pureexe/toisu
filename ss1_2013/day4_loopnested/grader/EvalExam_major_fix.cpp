#include<stdio.h>
int main()
{
    float v_min=9999,v_max=-9999,b,u;
    int i=1,big,newchar=1,v_max_char=-9999,v_min_char=-9999;
    while(1)
    {
        scanf("%f",&u);
        if(u==0&&newchar==1)
        {
            break;
        }
        else if(u<0)
        {
            newchar=1;
            i++;
        }
        else if(newchar==1)
        {
            newchar=0;
            big=u;
        }
        else
        {
            b=((float)u/big)*100;
            if(b>v_max)
            {
                v_max=b;
                v_max_char=i;
            }
            if(b<v_min)
            {
                v_min=b;
                v_min_char=i;
            }
        }
    }
    if(v_min!=9999)
    {
        printf("%d %.2f\n%d %.2f\n",v_min_char,v_min,v_max_char,v_max);

    }

    return 0;
}
