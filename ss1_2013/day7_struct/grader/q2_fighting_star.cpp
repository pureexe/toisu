#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
struct star{
    string name;
    int vote;
};
bool cmp(struct star a,struct star b){
    return a.vote<b.vote;
}
int main()
{
    struct star st[10];
    int i,n,u;
    for(i=0;i<8;i++)
    {
        cin >> st[i].name;
        st[i].vote=0;
    }
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> u;
        st[u-1].vote++;
    }
    struct star* minvar=min_element(st,st+8,cmp);
    for(i=0;i<8;i++)
    {
        if(st[i].vote>minvar->vote)
        cout <<st[i].name <<"\n";
    }

    return 0;
}
