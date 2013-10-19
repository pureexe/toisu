#include<iostream>
#include<set>
using namespace std;
set<int> tab;
int main()
{
    int i,n,u;
    cin >>n;
    for(i=0;i<n;i++)
    {
        cin >> u;
        tab.insert(u);
    }
    for(set<int>::iterator i=tab.begin();i!=tab.end();i++)
    {
        cout << *i <<" ";
    }
    return 0;
}
