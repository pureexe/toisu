#include<stdio.h>
struct box{
    int water,sugar;
};
struct box botton(int water,int sugar)
{
    int i=0;
    while(water>=250&&sugar>=15)
    {
        water-=250;
        sugar-=15;
        i++;
    }
    struct box s;
    s.water=water;
    s.sugar=i;
    return s;
}
int main()
{
    struct box tea[7];
    int i;
    for(i=0;i<7;i++)
         scanf("%d %d",&tea[i].water,&tea[i].sugar);
    struct box x;
    for(i=0;i<7;i++)
         {
             x=botton(tea[i].water,tea[i].sugar);
             printf("%d",x.sugar);
             if(x.water!=0)
                printf(" water");
             printf("\n");
         }
    return 0;
}
