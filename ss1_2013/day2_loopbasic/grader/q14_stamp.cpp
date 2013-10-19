#include<stdio.h>
struct box{
    int id;
    int m;
};
struct box lst[3];
int isInList(int id)
{
    int i;
    for(i=0;i<3;i++)
        if(lst[i].id==id)
            return lst[i].m;
    return -922;
}
int main()
{

    int i,n,cut_money,sum=0,stamp=0,sticker=0,money=0;
    for(i=0;i<3;i++)
        scanf("%d %d",&lst[i].id,&lst[i].m);
    scanf("%d %d",&n,&cut_money);
    struct box p;
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&p.id,&p.m);
        money+=p.m;
        if(isInList(p.id)!=-922)
        {
            stamp+=isInList(p.id);
        }
        else{
            sum+=p.m;
        }
    }
    printf("%d\n%d\n%d",money,sum,stamp+(sum/cut_money));
    return 0;
}
