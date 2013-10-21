#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct student{
    string id;
    int s;
};
//struct student stu[1001];
vector<struct student> toplist;
int top_max=-932423;
int getScore(int n){
    int u,i,min_x=99999,sum=0;
    for(i=0;i<n;i++)
    {
        cin >> u;
        sum+=u;
        if(u<min_x)
            min_x=u;
    }
    sum-=min_x;
    return sum;
}
int main()
{
    int n,k,i,j,rec;
    struct student tmpload;
    cin >>n >> k;
    for(i=0;i<n;i++)
    {
        cin >> tmpload.id;
        tmpload.s=getScore(k);
        if(top_max<tmpload.s)
        {
            toplist.clear();
            toplist.push_back(tmpload);
            top_max=tmpload.s;
        }
        else if(top_max==tmpload.s)
        {
            toplist.push_back(tmpload);
        }
    }
    cout << top_max<<"\n";
    for(i=0;i<toplist.size();i++)
    {
        cout << toplist[i].id <<"\n";
    }

    return 0;
}
