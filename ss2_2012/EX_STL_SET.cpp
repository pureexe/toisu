#include<iostream>
#include<set>
using namespace std;
int main()
{
    set<int> s;
    int i=0,u;
    for(i=0;i<5;i++)
    {
        cin >> u;
        s.insert(u);
    }
    cin >> u;
    if(s.find(u)!=s.end())
    {
        cout << "Found";
    }
    else
    {
        cout << "NotFound";
    }
    return 0;
}
