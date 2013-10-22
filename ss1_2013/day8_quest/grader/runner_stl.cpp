#include<iostream>
#include<algorithm>
using namespace std;
struct runner{
    int id;
    float sp;
    int time;
};
bool cmp(struct runner a,struct runner b){
    if(a.time==b.time)
        return a.sp>b.sp;
    return a.time<b.time;
}
int main()
{

    struct runner run[31];
    int i,T,t_1,t_2,t_3,distance,n,j;
    cin >> T;
    for(i=0;i<T;i++)
    {
        cin >> n >> distance;
        for(j=0;j<n;j++)
        {
            cin >> t_1 >> t_2;
            run[j].id=j+1;
            run[j].sp=t_1;
            run[j].time=(((float)distance)*1000/t_1)+t_2;
        }
        sort(run,run+n,cmp);
        for(j=0;j<n;j++)
            cout << run[j].id <<"\n";
    }
    return 0;
}
