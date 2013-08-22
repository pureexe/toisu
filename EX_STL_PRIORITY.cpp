#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct box{
    int id;
    int value;
    box(int a,int b)
    {
        id=a;
        value=b;
    }
};
struct Comparetor{
    bool operator()(struct box u,struct box v)
    {
        return u.value>v.value;
    }
};
int main()
{
    priority_queue<box,vector<box>,Comparetor> que;
    int i,u;
    for(i=0;i<5;i++)
    {
        cin >> u;
        que.push(box(i,u));
    }
    while(!que.empty())
    {
        cout << que.top().value << " ";
        que.pop();
    }
    return 0;
}
