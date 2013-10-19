#include<iostream>
#include<cstdio>
using namespace std;
int man[5],woman[5];
float avg(int i,int b)
{
    if(b==0)
        return 0;
    return (float)i/b;
}
int main()
{
    int man_ct=0,woman_ct=0,s,t[5];
    while(1)
    {

    cin >> s;
    if(s==0)
        break;
    else if(s==1)
    {
        man_ct++;
        cin >> t[0] >> t[1] >> t[2] >> t[3] >> t[4];
        man[0]+=t[0];
        man[1]+=t[1];
        man[2]+=t[2];
        man[3]+=t[3];
        man[4]+=t[4];
    }
    else if(s==2){
        woman_ct++;
        cin >> t[0] >> t[1] >> t[2] >> t[3] >> t[4];
        woman[0]+=t[0];
        woman[1]+=t[1];
        woman[2]+=t[2];
        woman[3]+=t[3];
        woman[4]+=t[4];
        }
    }
    int i;
    float u_man[5],s_man=0,u_woman[5],s_woman=0;
    printf("%d ",man_ct);
    for(i=0;i<5;i++)
    {
        u_man[i]=avg(man[i],man_ct);
        s_man+=u_man[i];
        printf("%.2f ",u_man[i]);
    }
    printf("%.2f\n",s_man/5);
    printf("%d ",woman_ct);
    for(i=0;i<5;i++)
    {
        u_woman[i]=avg(woman[i],woman_ct);
        s_woman+=u_woman[i];
        printf("%.2f ",u_woman[i]);
    }
    printf("%.2f\n",s_woman/5);
    printf("%d ",man_ct+woman_ct);
    float x=0,sum[5];
    for(i=0;i<5;i++)
    {
        sum[i]=(avg((man[i]+woman[i]),man_ct+woman_ct));
        x+=sum[i];
        printf("%.2f ",sum[i]);
    }

    printf("%.2f\n",x/5.0);
   // printf("%d %.2f %.2f %.2f %.2f %.2f %.2f\n",man_ct,avg(man[0],man_ct),avg(man[1],man_ct),avg(man[2],man_ct),avg(man[3],man_ct),avg(man[4],man_ct),avg(avg(man[0],man_ct)+avg(man[1],man_ct)+avg(man[2],man_ct)+avg(man[3],man_ct)+avg(man[4],man_ct),5));
    //printf("%d %.2f %.2f %.2f %.2f %.2f %.2f\n",woman_ct,avg(woman[0],woman_ct),avg(woman[1],woman_ct),avg(woman[2],woman_ct),avg(woman[3],woman_ct),avg(woman[4],woman_ct),avg(avg(woman[0],woman_ct)+avg(woman[1],woman_ct)+avg(woman[2],woman_ct)+avg(woman[3],woman_ct)+avg(woman[4],woman_ct),5));
    //printf("%d %.2f %.2f %.2f %.2f %.2f %.2f\n",man_ct+woman_ct,avg(man[0]+woman[0],man_ct+woman_ct),avg(man[1]+woman[1],man_ct+woman_ct),avg(man[2]+woman[2],man_ct+woman_ct),avg(man[3]+woman[3],man_ct+woman_ct),avg(man[4]+woman[4],man_ct+woman_ct),avg(avg(man[0]+woman[0],man_ct+woman_ct)+avg(man[1]+woman[1],man_ct+woman_ct)+avg(man[2]+woman[2],man_ct+woman_ct)+avg(man[3]+woman[3],man_ct+woman_ct)+avg(man[4]+woman[4],man_ct+woman_ct),5));
    return 0;
}
