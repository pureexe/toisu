/*kawin_earth@hotmail.com*/
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
typedef struct person{
    char name[10];
    int income;
    int payment;
}person;
person unit[100];
bool sort_risk(person a,person b)
{
        return a.income-a.payment>b.income-b.payment;
}
int main()
{
    int i,round=5,a,b;
    //scanf("%d",&round);
    for(i=0;i<round;i++)
    {
        scanf("%s %d %d",&unit[i].name,&unit[i].income,&unit[i].payment);
    }
    sort(unit,unit+round,sort_risk);
for(i=0;i<round;i++)
    {
        printf("total money of %s is %d\n",unit[i].name,unit[i].income-unit[i].payment);
    }

}
