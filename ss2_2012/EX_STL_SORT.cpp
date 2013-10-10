#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct box{
    int id;
    int value;

    box(int a,int b){
        id=a;
        value=b;
    }
};
bool sortfx(struct box a,struct box b)
{
    return a.value<b.value;
}
int main()
{
    int i,u;
    vector<box> vex;
    for(i=0;i<5;i++)
    {
        cin >> u;
        vex.push_back(box(i,u));
    }
    sort(vex.begin(),vex.end(),sortfx);
    for(struct box v : vex)
    {
        cout << v.value << " ";
    }
    return 0;
}
