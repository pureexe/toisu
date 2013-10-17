#include<stdio.h>
int main()
{
    int man_ct=0,girl_ct=0;
    int i,n,k,g,b,sex;
    scanf("%d %d",&n,&k);
    for(i=0; i<n; i++)
    {
        scanf("%d %d %d",&sex,&b,&g);
        if(g>8&&b>8&&(man_ct<k&&girl_ct<k))
        {
            if(man_ct<k&&girl_ct<k)
            {
                printf("%d %d\n",i+1,sex);
                if(sex==1)
                    man_ct++;
                else
                    girl_ct++;
            }
            else if(man_ct<k)
            {
                printf("%d 1\n",i+1);
                girl_ct++;
            }
            else if(girl_ct<k)
            {
                printf("%d 2\n",i+1);
                man_ct++;
            }
        }
        else if(man_ct<k&&b>8)
            {
                printf("%d 1\n",i+1);
                man_ct++;
            }
        else if(girl_ct<k&&g>8)
            {
                printf("%d 2\n",i+1);
               girl_ct++;
            }

    }
    return 0;
}
