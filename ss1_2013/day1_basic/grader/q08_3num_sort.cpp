#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int i,u;
    vector<int> vex;
    for(i=0;i<3;i++)
    {
        cin >> u;
        vex.push_back(u);
    }
    sort(vex.begin(),vex.end());
    for(i=0;i<3;i++)
      cout << vex[i] <<" ";
    return 0;
}
